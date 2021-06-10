
#include "stdafx.h"
#include "shader.h"

#include <Embers.Graphics/gl.h>
#include <Embers.Graphics/shader_program.h>

namespace CORE {

	Shader::Shader(const std::string& fragPath, const std::string& vertPath) {
		_glShader = new GFX::ShaderProgram(fragPath, vertPath);
	}

	void Shader::Bind(void) {
		EMB_GL->SetShader(_glShader);
	}

	void Shader::SetVec3(const std::string& name, uint32_t a, uint32_t b, uint32_t c) {
		_glShader->SetVec3(name, a, b, c);
	}

	void Shader::SetMat4(const std::string& name, glm::mat4& mat) {
		_glShader->SetMat4(name, mat);
	}

}