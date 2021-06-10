#pragma once

namespace GFX {

	class EMB_API VAO {

	public:
		VAO(void);
		void Bind(void);
		void Unbind(void);
		~VAO(void);

	private:
		uint32_t _vao;

	};

}