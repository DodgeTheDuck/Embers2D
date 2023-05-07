#pragma once

#include <Embers.Lib/dll.h>
#include "gl.h"
#include "vertex.h"




namespace GFX {

	class VAO;
	class VBO;

	class EMB_API Mesh {
		
	public:

		static Mesh Rect(float left, float top, float width, float height, EDrawStyle style, glm::vec4 color = { 1.0, 1.0, 1.0, 1.0 });
		static Mesh Polygon(std::vector<glm::vec2> points, EDrawStyle style, glm::vec4 color = { 1.0, 1.0, 1.0, 1.0 });
		static Mesh Model(std::vector<glm::vec3> points, std::vector<uint32_t> indices, std::vector<glm::vec2> uvs, std::vector<glm::vec3> normals, EDrawStyle style, glm::vec4 color = { 1.0, 1.0, 1.0, 1.0 });

		std::vector<Vertex> Vertices(void);
		std::vector<uint32_t> Indices(void);
		void SetTexCoords(uint32_t index, glm::vec2 coords);
		void Upload(void);
		void Bind(void);
		void Unbind(void);

	private:
		std::vector<Vertex> _verts;
		std::vector<uint32_t> _indices;
		EDrawStyle _style;

		VAO * _vao;
		VBO * _vbo;

	};

}