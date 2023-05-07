

#include "stdafx.h"
#include "model.h"
#include "material.h"
#include "texture.h"
#include "transform.h"

#include <Embers.Graphics/vbo.h>
#include <Embers.Graphics/vao.h>
#include <Embers.Graphics/gl.h>
#include <Embers.Graphics/mesh.h>
#include <Embers.Graphics/texture.h>

#include "engine.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace CORE {

	CModel::CModel(SceneObject* owner) : Component(owner) {

		_vao = NULL;
		_vbo = NULL;

		_material = NULL;

		_dirty = true;

		_ox = 0;
		_oy = 0;
		_oz = 0;

	}

	void CModel::Tick(void) {

	}

	CModel* CModel::FromFile(const char* path) {

		Assimp::Importer importer;
		const aiScene* scene = importer.ReadFile("./models/statuette.obj", aiProcess_Triangulate | aiProcess_FlipUVs);

		aiMesh* mesh = scene->mMeshes[scene->mRootNode->mChildren[1]->mMeshes[0]];

		CORE::Texture* tex = new CORE::Texture("./models/diffuse.png");
		_material = new CORE::Material();
		_material->SetTexture(CORE::ETextureType::DIFFUSE, tex);
		_material->SetShader(EMB_ASSET_BANK->GetAsset<CORE::Shader>("sha_poly"));

		for (int i = 0; i < mesh->mNumVertices; i++) {
			_points.push_back({
				mesh->mVertices[i].x,
				mesh->mVertices[i].y,
				mesh->mVertices[i].z
				});
			_normals.push_back({
				mesh->mNormals[i].x,
				mesh->mNormals[i].y,
				mesh->mNormals[i].z
				});
			_uvs.push_back({
				mesh->mTextureCoords[0][i].x,
				mesh->mTextureCoords[0][i].y
				});
		}

		for (int i = 0; i < mesh->mNumFaces; i++) {
			aiFace face = mesh->mFaces[i];
			for (int j = 0; j < face.mNumIndices; j++) {
				_indices.push_back(face.mIndices[j]);
			}
		}

		return this;

	}

	CModel* CModel::SetPoints(std::vector<glm::vec3> points) {
		_points = points;
		return this;
	}

	CModel* CModel::SetOrigin(float x, float y, float z) {
		_ox = x;
		_oy = y;
		_oz = z;
		return this;
	}

	void CModel::PreDraw(void) {
		EMB_GL->PushMatrix(glm::translate(glm::mat4(1.0), glm::vec3(-_ox, -_oy, -_oz)));
	}

	void CModel::Draw(void) {

		if (_dirty) {
			_Rebuild();
		}

		_material->Bind();
		_material->Update();
		_vao->Bind();
		EMB_GL->DrawElements(GFX::EDrawStyle::TRIANGLES, _points.size() * 2 + 2);

	}

	void CModel::PostDraw(void) {
		EMB_GL->PopMatrix();
	}

	void CModel::DrawPass(GFX::ERenderPass pass) {

	}

	CModel* CModel::SetMaterial(Material* mat) {
		_material = mat;
		return this;
	}

	std::vector<glm::vec3> CModel::GetPoints(void) {
		return _points;
	}

	Material* CModel::GetMaterial(void) {
		return _material;
	}

	void CModel::_Rebuild(void) {

		delete(_vbo);
		delete(_vao);

		_vao = new GFX::VAO();
		_vao->Bind();

		_mesh = GFX::Mesh::Model(_points, _indices, _uvs, _normals, GFX::EDrawStyle::LINES);

		_vbo = new GFX::VBO(_mesh);

		_vao->Unbind();

		_dirty = false;

	}

}