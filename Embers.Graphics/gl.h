#pragma once

#include <Embers.Lib/dll.h>

#define EMB_GL GFX::GL::GetInstance()

namespace SYS {
	class Window;
}

namespace GFX {

	class ShaderProgram;
	class FBO;

	enum ERenderPass {
		PRE_DRAW,
		SCENE,
		BLUR_X,
		BLUR_Y,
		GUI,
		DISPLAY
	};

	enum EDrawStyle {
		LINES = 0x001,
		TRIANGLES = 0x004,
		TRIANGLE_STRIP = 0x005,
		TRIANGLE_FAN = 0x006
	};

	class EMB_API GL {

	public:
		void Init(HINSTANCE hInstnace, HWND window);

		void DrawArrays(void);
		void DrawElements(EDrawStyle style, uint32_t nElements);
		void DrawElementsScene(EDrawStyle style, uint32_t nElements);

		void BeginRenderPass(ERenderPass type);
		void RebindRenderPass(void);
		void DrawRenderPass(ERenderPass type);

		void Swap(void);

		static GL* GetInstance(void);

		void PushMatrix(glm::mat4 mat);
		glm::mat4 TopMatrix(void);
		void PopMatrix(void);

		void Viewport(uint32_t x, uint32_t y, uint32_t w, uint32_t h);

		void SetShader(GFX::ShaderProgram* shader);
		void BindTexture(uint32_t texture);

		void SetPerspective(void);
		void SetOrtho(void);

		void SetProjection(glm::mat4 proj);
		glm::mat4 GetProjection(void);

		void SetView(glm::mat4 view);
		glm::mat4 GetView(void);

		void ClearView(void);

		void EnableDepth(void);
		void DisableDepth(void);


		ShaderProgram* GetSceneShader(void);

	private:

		GL(void);		

		HWND _CreateFakeWindow(HINSTANCE hInstance);
		
		static GL* _instance;
		HDC _dc;
		HGLRC _context;
		ShaderProgram* _shaderPrg;

		glm::mat4 _proj;
		glm::mat4 _view;

		std::stack<glm::mat4> _matStack;

		ShaderProgram* _blurShader;
		ShaderProgram* _sceneShader;

		FBO* _lastPass;
		FBO* _currentPass;

		std::map<ERenderPass, FBO*> _renderPasses;

	};

}