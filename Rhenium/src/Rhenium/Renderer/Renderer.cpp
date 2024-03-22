//
// Created by Andrew Graser on 3/20/2024.
//

#include "Renderer.h"
#include "rhpch.h"
#include "glm/ext/matrix_transform.hpp"


#include <Glad/glad.h>


struct RendererData {
    uint32_t SquareVA;
};


RendererData* sData = nullptr;

namespace Manganese {
    void Renderer::Init() {
        sData = new RendererData;

        float vertices[4 * 5] = {
                -0.5f, -0.5f, 0.0f,         0.0f, 0.0f,
                0.5f, -0.5f, 0.0f,          1.0f, 0.0f,
                0.5f, 0.5f, 0.0f,        1.0f, 1.0f,
                -0.5f, 0.5f, 0.0f,       0.0f, 1.0f,
        };

        uint32_t indices[2 * 3] {
                0, 1, 2,
                2, 3, 0
        };

        glGenVertexArrays(1, &sData->SquareVA);
        glBindVertexArray(sData->SquareVA);

        uint32_t vb, ib;

        glGenBuffers(1, &vb);
        glBindBuffer(GL_ARRAY_BUFFER, vb);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glGenBuffers(1, &ib);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(float) * 5, (void*)0);
    }

    void Renderer::DrawSquare(const std::shared_ptr<Shader>& shader, const glm::vec3& position, const glm::vec3& scale) {
        auto transform = glm::translate(glm::scale(glm::mat4(1.0f), scale), position);

        shader->Bind();

        shader->SetMat4("uTransform", transform);

        glBindVertexArray(sData->SquareVA);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
}