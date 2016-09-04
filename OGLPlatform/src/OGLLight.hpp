#pragma once

#include "OGLRenderableObject.hpp"
#include "OGLCube.hpp"
#include "Program.hpp"
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "Light.hpp"

class OGLLight : public gs::OGLRenderableObject
{
public:
	OGLLight();
	~OGLLight();

	void SetMVP(const glm::mat4& mvp) { MVP = mvp; }

	bool Load(const std::string& meshFilename);
	void Render(gs::Program* program) override;

private:
	OGLCube cube;
	gs::Program lightProgram;
	gs::VertexArray vao;
	gs::VertexBuffer vbo;
	glm::mat4 MVP;
};
