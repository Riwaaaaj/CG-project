#pragma once

#include <OGL3D/Game/OGame.h>
#include <OGL3D/Graphics/OVertexArrayObject.h>
#include <OGL3D/Graphics/OShaderProgram.h>
#include <OGL3D/Math/OMat4.h>

class CubeGame : public OGame {
public:
    CubeGame();
    ~CubeGame();

    void onUpdate() override;
    void onDraw() override;

private:
    OVertexArrayObject_ptr m_vao;
    OShaderProgram_ptr m_shader;
    OMat4 m_projection, m_view;
    float m_rotation = 0.0f;
};
