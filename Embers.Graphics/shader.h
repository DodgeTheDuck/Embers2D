#pragma once

namespace GFX {

	enum class EMB_API EShaderType {
		FRAG,
		VERTEX
	};
	
	class EMB_API Shader {

	public:
		Shader(const std::string &path, EShaderType type);

		uint32_t GetHandle(void);

		void Delete(void);

	private:
		uint32_t _shader;

	};

}