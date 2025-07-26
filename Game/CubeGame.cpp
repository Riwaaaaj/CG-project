#include "CubeGame.h"
#include "resources/cube_data.h"

#include <OGL3D/Graphics/OVertexBuffer.h>
#include <OGL3D/Graphics/OIndexBuffer.h>
#include <OGL3D/Graphics/OVertexAttribute.h>
#include <OGL3D/Math/OVec3.h>

CubeGame::CubeGame() {
    // Create shader program
    m_shader = OShaderProgram::create();
    m_shader->attachVertexShaderFromFile("shaders/vertex_shader.vert");
    m_shader->attachFragmentShaderFromFile("shaders/fragment_shader.frag");
    m_shader->link();

    // Create vertex buffer
    auto vbo = OVertexBuffer::create(
        cubeVertices,
        sizeof(cubeVertices),
        8,
        OVertexAttribute::createList(2),
        OBufferUsage::StaticDraw
    );

    // Create index buffer
    auto ibo = OIndexBuffer::create(cubeIndices, sizeof(cubeIndices));

    // Create vertex array object
    m_vao = OVertexArrayObject::create();
    m_vao->addVertexBuffer(vbo);
    m_vao->setIndexBuffer(ibo);

    // Set up projection and view matrices
    m_projection = OMat4::perspective(45.0f, 800.0f / 600.0f, 0.1f, 100.0f);
    m_view = OMat4::translate(OVec3(0, 0, -3));
}

CubeGame::~CubeGame() {}

void CubeGame::onUpdate() {
    // Update rotation angle
    m_rotation += 0.5f;
}

void CubeGame::onDraw() {
    // Create model matrix
    auto model = OMat4::rotate(m_rotation, OVec3(0.5f, 1.0f, 0.0f));

    // Set shader uniforms
    m_shader->use();
    m_shader->setMat4("model", model);
    m_shader->setMat4("view", m_view);
    m_shader->setMat4("projection", m_projection);

    // Draw the cube
    m_vao->draw();
}
