
#include "stdafx.h"
#include "mesh.h"

namespace GFX {

	Mesh Mesh::Rect(float left, float top, float width, float height, EDrawStyle style, glm::vec4 color) {

		Mesh mesh;

		mesh._style = style;

		mesh._verts.push_back(Vertex({
				left, top, 0
			}, color, {
				0.0, 0.0
		}));

		mesh._verts.push_back(Vertex({
				left+width, top, 0
			}, color, {
				1.0, 0.0
		}));

		mesh._verts.push_back(Vertex({
				left+width, top+height, 0
			}, color, {
				1.0, 1.0
		}));

		mesh._verts.push_back(Vertex({
				left, top+height, 0
			}, color, {
				0.0, 1.0
		}));

		if (style == EDrawStyle::TRIANGLES) {
			mesh._indices.push_back(0);
			mesh._indices.push_back(1);
			mesh._indices.push_back(3);
			mesh._indices.push_back(1);
			mesh._indices.push_back(2);
			mesh._indices.push_back(3);
		}
		else if (style == EDrawStyle::LINES) {
			mesh._indices.push_back(0);
			mesh._indices.push_back(1);
			mesh._indices.push_back(1);
			mesh._indices.push_back(2);
			mesh._indices.push_back(2);
			mesh._indices.push_back(3);
			mesh._indices.push_back(3);
			mesh._indices.push_back(0);
		}

		return mesh;
	}

	Mesh Mesh::Polygon(std::vector<glm::vec2> points, EDrawStyle style, glm::vec4 color) {

		Mesh mesh;

		//mesh._style = style;
		mesh._style = EDrawStyle::LINES; // TODO: filled polys

		for (int i = 0; i < points.size(); i++) {
			glm::vec2 p = points[i];

			mesh._verts.push_back(Vertex({
					p.x, p.y, 0
				}, color, {
					0, 0 // TODO: UV Coords for polys?
				}));

			if (i > 0) {				
				mesh._indices.push_back(i-1);
				mesh._indices.push_back(i);
			}
		}

		mesh._indices.push_back(points.size() - 1);
		mesh._indices.push_back(0);

		return mesh;
	}

	std::vector<Vertex> Mesh::Vertices(void) {
		return _verts;
	}

	std::vector<uint32_t> Mesh::Indices(void) {
		return _indices;
	}

	void Mesh::SetTexCoords(uint32_t index, glm::vec2 coords) {
		_verts[index].texCoord.x = coords.x;
		_verts[index].texCoord.y = coords.y;
	}

}