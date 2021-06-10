
#include "stdafx.h"
#include "shader.h"
#include "shader_program.h"

namespace GFX {

	ShaderProgram::ShaderProgram(const std::string& fragPath, const std::string& vertPath) {

		Shader * frag = new Shader(fragPath, EShaderType::FRAG);
		Shader * vert = new Shader(vertPath, EShaderType::VERTEX);

		_prg = glCreateProgram();
		glAttachShader(_prg, frag->GetHandle());
		glAttachShader(_prg, vert->GetHandle());
		glLinkProgram(_prg);

		frag->Delete();
		vert->Delete();

		delete(frag);
		delete(vert);

	}

	void ShaderProgram::Bind(void) {
		glUseProgram(_prg);
	}

	void ShaderProgram::SetVec2(const std::string& name, uint32_t a, uint32_t b) {
		uint32_t loc = glGetUniformLocation(_prg, name.c_str());
		glUniform2f(loc, a, b);
	}

	void ShaderProgram::SetVec3(const std::string &name, uint32_t a, uint32_t b, uint32_t c) {
		uint32_t loc = glGetUniformLocation(_prg, name.c_str());
		glUniform3f(loc, a, b, c);
	}

	void ShaderProgram::SetMat4(const std::string& name, glm::mat4 &mat) {
		uint32_t loc = glGetUniformLocation(_prg, name.c_str());
		glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(mat));
	}

	void ShaderProgram::SetInt(const std::string& name, int i) {
		uint32_t loc = glGetUniformLocation(_prg, name.c_str());
		glUniform1i(loc, i);
	}

}