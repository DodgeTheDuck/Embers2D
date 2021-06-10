#pragma once

#include <Embers.Lib/dll.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace GFX {

	struct Vertex {

		Vertex(glm::vec3 position, glm::vec4 color, glm::vec2 texCoord) {
			this->position = position;
			this->color = color;
			this->texCoord = texCoord;
		}

		//~Vertex(void) {
		//	free(data);
		//}

		//t_real* data;
		//t_real* position;
		//t_real* texCoord;
		//t_real* color;	

		glm::vec3 position;
		glm::vec4 color;
		glm::vec2 texCoord;

	};

}