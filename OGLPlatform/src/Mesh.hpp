//
//  Mesh.hpp
//  OGLPlatform
//
//  Created by Guillaume Troll� on 30/08/2016.
//  Copyright � 2016 Guillaume Troll�. All rights reserved.
//

#pragma once

#include <GL/glew.h>
#include <vector>
#include "Vertex.hpp"
#include "VertexBuffer.hpp"
#include "Material.hpp"

namespace gs
{
	class Program;

	class Mesh
	{
	public:
		Mesh();
		~Mesh();

		void InitGL(std::vector<Vertex> vertices, std::vector<GLuint> indices);
		void SetMaterial(Material* material) { this->material = material; }
		void Draw(Program* program);

		int GetMaterialIndex() const { return materialIndex; }
		void SetMaterialIndex(int index) { materialIndex = index; }

		int GetNbIndices() const { return nbIndices; }
		void SetNbIndices(int size) { nbIndices = size; }

		glm::mat4 GetModelMatrix() const { return modelMatrix; }
		VertexBuffer GetVBO() const { return vbo; }
		VertexBuffer GetIBO() const { return ibo; }

	private:
		VertexBuffer vbo;
		VertexBuffer ibo;
		int materialIndex;
		int nbIndices;
		glm::mat4 modelMatrix;
					
		Material* material;
	};
}
/* Mesh.hpp */