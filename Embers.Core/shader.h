#pragma once

#include <Embers.Lib/dll.h>
#include "asset.h"

namespace GFX{
	class ShaderProgram;
}

namespace CORE {

	class EMB_API Shader : public Asset {

	public:
		Shader(const std::string& fragPath, const std::string& vertPath);

		void Bind(void);
		void SetVec3(const std::string& name, uint32_t a, uint32_t b, uint32_t c);
		void SetMat4(const std::string& name, glm::mat4& mat);


	private:
		GFX::ShaderProgram* _glShader;


	};

}