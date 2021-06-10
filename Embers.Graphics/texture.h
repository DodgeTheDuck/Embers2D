#pragma once

namespace GFX {

	class EMB_API Texture {

	public:
		Texture(unsigned char * data, int width, int height);

		void Bind(void);
		uint32_t GetHandle(void);

		~Texture(void);
	private:

		uint32_t _texture;

	};

}