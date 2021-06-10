
#include "stdafx.h"
#include <Embers.System/file_system.h>
#include "shader.h"

namespace GFX {

	Shader::Shader(const std::string &path, EShaderType type) {

		GLenum glType;

		switch(type) {
		case EShaderType::FRAG:
			glType = GL_FRAGMENT_SHADER;
			break;
		case EShaderType::VERTEX:
			glType = GL_VERTEX_SHADER;
			break;
		default:
			glType = NULL;
			break;
		};

		std::string srcStr = SYS::FileSystem::ReadText(path);
		const char* source = srcStr.c_str();

		_shader = glCreateShader(glType);

		glShaderSource(_shader, 1, &source, NULL);
		glCompileShader(_shader);

		int success = 0;
		char info[512];

		glGetShaderiv(_shader, GL_COMPILE_STATUS, &success);

		if (!success) {
			glGetShaderInfoLog(_shader, 512, NULL, info);
			int i = 1;
		}

	}

	uint32_t Shader::GetHandle(void) {
		return _shader;
	}

	void Shader::Delete(void) {
		glDeleteShader(_shader);
	}

}