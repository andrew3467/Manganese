//
// Created by Andrew Graser on 3/20/2024.
//

#include "Renderer.h"
#include "rhpch.h"
#include "glm/ext/matrix_transform.hpp"
#include "VertexArray.h"


#include <Glad/glad.h>



namespace Manganese {
    struct RendererData {
        std::shared_ptr<VertexArray> SquareVA;
        std::shared_ptr<VertexArray> CubeVA;

        std::shared_ptr<Shader> Shader;
    };

    RendererData* sData = nullptr;



    void Renderer::Init() {
        sData = new RendererData;

        {
            float vertices[4 * 5] = {
                    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
                    0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
                    0.5f, 0.5f, 0.0f, 1.0f, 1.0f,
                    -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
            };

            uint32_t indices[2 * 3]{
                    0, 1, 2,
                    2, 3, 0
            };

            sData->SquareVA = std::make_shared<VertexArray>();

            std::shared_ptr<VertexBuffer> vb = std::make_shared<VertexBuffer>(vertices, sizeof(vertices));

            vb->SetLayout({
                                  {3, GL_FLOAT, 0, false},
                                  {2, GL_FLOAT, 3, false},
                          });

            sData->SquareVA->SetVertexBuffer(vb);

            std::shared_ptr<IndexBuffer> ib = std::make_shared<IndexBuffer>(indices,
                                                                            sizeof(indices) / sizeof(uint32_t));
            sData->SquareVA->SetIndexBuffer(ib);
        }

        {
            float vertices[4 * 5] = {
                    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
                    0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
                    0.5f, 0.5f, 0.0f, 1.0f, 1.0f,
                    -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
            };

            uint32_t indices[2 * 3]{
                    0, 1, 2,
                    2, 3, 0
            };

            sData->CubeVA = std::make_shared<VertexArray>();

            std::shared_ptr<VertexBuffer> vb = std::make_shared<VertexBuffer>(vertices, sizeof(vertices));

            vb->SetLayout({
                                  {3, GL_FLOAT, 0, false},
                                  {2, GL_FLOAT, 3, false},
                          });

            sData->CubeVA->SetVertexBuffer(vb);

            std::shared_ptr<IndexBuffer> ib = std::make_shared<IndexBuffer>(indices,
                                                                            sizeof(indices) / sizeof(uint32_t));
            sData->CubeVA->SetIndexBuffer(ib);
        }


        sData->Shader = std::make_shared<Shader>("../../assets/shaders/Solid_Unlit.glsl");
    }

    void Renderer::DrawSquare(const glm::vec3& position, const glm::vec3& scale) {
        auto transform = glm::translate(glm::scale(glm::mat4(1.0f), scale), position);

        sData->Shader->Bind();

        sData->Shader->SetMat4("uTransform", transform);

        sData->SquareVA->Bind();
        glDrawElements(GL_TRIANGLES, sData->SquareVA->GetIndexBuffer().GetCount(), GL_UNSIGNED_INT, 0);
    }

    void Renderer::DrawCube(const glm::vec3 &position, const glm::vec3 &scale) {
        auto transform = glm::translate(glm::scale(glm::mat4(1.0f), scale), position);

        sData->Shader->Bind();

        sData->Shader->SetMat4("uTransform", transform);

        sData->CubeVA->Bind();
        glDrawElements(GL_TRIANGLES, sData->CubeVA->GetIndexBuffer().GetCount(), GL_UNSIGNED_INT, 0);
    }

    void Renderer::StartScene(PerspectiveCamera &camera) {
        sData->Shader->Bind();
        sData->Shader->SetMat4("uViewProj", camera.GetViewProjection());
    }

    void Renderer::EndScene() {

    }
}