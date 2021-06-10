#pragma once

#include <string>

namespace GFX {

	class Shader;

	class EMB_API ShaderProgram {

	public:
		ShaderProgram(const std::string& fragPath, const std::string& vertPath);
		void Bind(void);

		void SetVec2(const std::string &name, uint32_t a, uint32_t b);
		void SetVec3(const std::string &name, uint32_t a, uint32_t b, uint32_t c);
		void SetMat4(const std::string& name, glm::mat4& mat);
		void SetInt(const std::string& name, int i);

	private:
		uint32_t _prg;

	};

}