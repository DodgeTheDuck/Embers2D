
#include "stdafx.h"
#include <Embers.System/window.h>
#include "gl.h"
#include "shader_program.h"
#include "fbo.h"

namespace GFX {

	GL* GL::_instance = NULL;

	GL::GL(void) {
		_dc = NULL;
		_context = NULL;
		_shaderPrg = NULL;
		_proj = glm::mat4(1.0);
		_blurShader = NULL;
		_currentPass = NULL;
		_lastPass = NULL;
		_sceneShader = NULL;
	}

	void GL::Init(HINSTANCE hInstance, HWND window) {

		_matStack.push(glm::mat4(1.0));

		PIXELFORMATDESCRIPTOR pfdFake =
		{
			sizeof(PIXELFORMATDESCRIPTOR),
			1,
			PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    // Flags
			PFD_TYPE_RGBA,        // The kind of framebuffer. RGBA or palette.
			32,                   // Colordepth of the framebuffer.
			0, 0, 0, 0, 0, 0,
			0,
			0,
			0,
			0, 0, 0, 0,
			24,                   // Number of bits for the depthbuffer
			8,                    // Number of bits for the stencilbuffer
			0,                    // Number of Aux buffers in the framebuffer.
			PFD_MAIN_PLANE,
			0,
			0, 0, 0
		};

		HWND fakeHwnd = _CreateFakeWindow(hInstance);
		HDC fakeDc = GetDC(fakeHwnd);

		int fakePixelFormat = ChoosePixelFormat(fakeDc, &pfdFake);
		SetPixelFormat(fakeDc, fakePixelFormat, &pfdFake);

		HGLRC fakeRc = wglCreateContext(fakeDc);
		wglMakeCurrent(fakeDc, fakeRc);

		if (!gladLoadGL() || !gladLoadWGL(fakeDc)) {
			exit(-1);
		}		
		
		const int pixelAttribs[] = {
			WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
			WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
			WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
			WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
			WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB,
			WGL_COLOR_BITS_ARB, 32,
			WGL_ALPHA_BITS_ARB, 8,
			WGL_DEPTH_BITS_ARB, 24,
			WGL_STENCIL_BITS_ARB, 8,
			WGL_SAMPLE_BUFFERS_ARB, GL_TRUE,
			WGL_SAMPLES_ARB, 4,
			0
		};

		int pixelFormat;
		uint32_t numFormats;

		_dc = GetDC(window);

		bool success = wglChoosePixelFormatARB(_dc, pixelAttribs, NULL, 1, &pixelFormat, &numFormats);

		if (!success || numFormats == 0) {
			exit(-1);
		}

		PIXELFORMATDESCRIPTOR pfd;
		DescribePixelFormat(_dc, pixelFormat, sizeof(pfd), &pfd);
		SetPixelFormat(_dc, pixelFormat, &pfd);

		const int major_min = 4, minor_min = 5;
		int  contextAttribs[] = {
			WGL_CONTEXT_MAJOR_VERSION_ARB, major_min,
			WGL_CONTEXT_MINOR_VERSION_ARB, minor_min,
			WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
			0
		};

		_context = glad_wglCreateContextAttribsARB(_dc, 0, contextAttribs);

		if (_context == NULL) {
			exit(-1);
		}

		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(fakeRc);
		ReleaseDC(fakeHwnd, fakeDc);
		DestroyWindow(fakeHwnd);		

		wglMakeCurrent(_dc, _context);

		if (!gladLoadGL() || !gladLoadWGL(fakeDc)) {
			exit(-1);
		}

		wglSwapIntervalEXT(0);

		glViewport(0, 0, 1024, 768);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glDisable(GL_CULL_FACE);

		glEnable(GL_DEPTH_TEST);

		//glLineWidth(1.0f);

		//glClearColor(0.467f, 0.62f, 0.796f, 1);
		glClearColor(0, 0, 0, 1);

		_sceneShader = new ShaderProgram("shaders/scene.frag", "shaders/scene.vert");
		_blurShader = new ShaderProgram("shaders/blur.frag", "shaders/blur.vert");

		//_proj = glm::ortho(0.0f, 1024.0f, 768.0f, 0.0f, -0.1f, 0.1f);
		_proj = glm::perspective(90.0f, 1024.0f / 768.0f, 0.01f, 1024.0f);

		_view = glm::mat4(1.0);

		_renderPasses[ERenderPass::SCENE] = new FBO(1024, 768);
		_renderPasses[ERenderPass::BLUR_X] = new FBO(1024, 768);
		_renderPasses[ERenderPass::BLUR_Y] = new FBO(1024, 768);
		_renderPasses[ERenderPass::GUI] = new FBO(1024, 768);

	}

	void GL::SetShader(ShaderProgram* program) {
		//if (_shaderPrg != program) {
			_shaderPrg = program;
		//}
	}

	void GL::DrawArrays(void) {
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}	
	
	void GL::DrawElements(EDrawStyle style, uint32_t nElements) {	

		
		if (_shaderPrg) {		

			_shaderPrg->Bind();

			glm::mat4 MVP = _proj * _view * _matStack.top();

			_shaderPrg->SetMat4("uMvp", MVP);

			if (_currentPass == _renderPasses[ERenderPass::BLUR_X]) {
				_shaderPrg->SetVec2("uDirection", 1, 0);
			}
			else if (_currentPass == _renderPasses[ERenderPass::BLUR_Y]) {
				_shaderPrg->SetVec2("uDirection", 0, 1);
			}

			if (_lastPass) {
				glActiveTexture(GL_TEXTURE1);
				glBindTexture(GL_TEXTURE_2D, _lastPass->Color());
				glActiveTexture(GL_TEXTURE0);
			}

		}				

		glDrawElements(style, nElements, GL_UNSIGNED_INT, 0);
	}

	void GL::SetPerspective(void) {
		_proj = glm::perspective(90.0f, 1024.0f / 768.0f, 0.01f, 1024.0f);
	}

	void GL::SetOrtho(void) {
		_proj = glm::ortho(0, 1024, 0, 768);
	}

	void GL::Viewport(uint32_t x, uint32_t y, uint32_t w, uint32_t h) {
		glViewport(x, y, w, h);
	}

	void GL::DrawElementsScene(EDrawStyle style, uint32_t nElements) {

		if (_shaderPrg) {
			_sceneShader->Bind();
		}

		glDrawElements(style, nElements, GL_UNSIGNED_INT, 0);
	}

	ShaderProgram* GL::GetSceneShader(void) {
		return _shaderPrg;
	}

	void GL::BeginRenderPass(ERenderPass type) {

		_lastPass = _currentPass;

		if (type == ERenderPass::DISPLAY) {
			_currentPass = NULL;
			glBindFramebuffer(GL_FRAMEBUFFER, 0);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			
		}
		else {

			if (type == ERenderPass::GUI) {
				this->SetOrtho();
			}

			_currentPass = _renderPasses[type];
			_currentPass->Bind();
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			if (type == ERenderPass::BLUR_X || type == ERenderPass::BLUR_Y) {
				SetShader(_blurShader);
			}

		}

	}

	void GL::RebindRenderPass(void) {
		if (_currentPass) {
			_currentPass->Bind();
		}
	}

	void GL::DrawRenderPass(ERenderPass type) {
		_renderPasses[type]->Draw();
	}

	void GL::Swap(void) {
		SwapBuffers(_dc);
	}

	void GL::PushMatrix(glm::mat4 mat) {
		_matStack.push(_matStack.top() * mat);
	}

	glm::mat4 GL::TopMatrix(void) {
		return _matStack.top();
	}

	void GL::PopMatrix(void) {
		_matStack.pop();
	}

	void GL::SetView(glm::mat4 view) {
		//TODO: MAKE THIS AND GETVIEW BETTER PLS
		//view = glm::translate(view, glm::vec3((1024 / 2), (768 / 2), 0));
		_view = view;
	}

	glm::mat4 GL::GetView(void) {
		return glm::translate(_view, glm::vec3(-(1024 / 2), -(768 / 2), 0));
	}

	glm::mat4 GL::GetProjection(void) {
		return _proj;
	}

	void GL::SetProjection(glm::mat4 proj) {
		_proj = proj;
	}


	void GL::ClearView(void) {
		_view = glm::mat4(1.0);
	}

	void GL::BindTexture(uint32_t texture) {
		glBindTexture(GL_TEXTURE_2D, texture);
	}

	GL* GL::GetInstance(void) {
		if (!_instance) {
			_instance = new GL();
		}
		return _instance;
	}

	HWND GL::_CreateFakeWindow(HINSTANCE hInstance) {

		WNDCLASSEX wcex;

		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = NULL;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = hInstance;
		wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
		wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
		wcex.lpszMenuName = NULL;
		wcex.lpszClassName = "EMBERS2D";
		wcex.hIconSm = LoadIcon(hInstance, IDI_APPLICATION);

		RegisterClassEx(&wcex);

		return CreateWindow("EMBERS2D", "", WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CS_OWNDC, 256, 256, 128, 128, NULL, NULL, hInstance, NULL);

	}

}