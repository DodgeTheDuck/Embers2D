
#include "stdafx.h"
#include "vao.h"

namespace GFX {

	VAO::VAO(void) {
		glGenVertexArrays(1, &_vao);
	}

	void VAO::Bind(void) {
		glBindVertexArray(_vao);
	}

	void VAO::Unbind(void) {
		glBindVertexArray(0);
	}

	VAO::~VAO() {
		glDeleteVertexArrays(1, &_vao);
	}

}