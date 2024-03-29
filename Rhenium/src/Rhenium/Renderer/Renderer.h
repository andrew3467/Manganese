//
// Created by Andrew Graser on 3/20/2024.
//

#ifndef MANGANESE_RENDERER_H
#define MANGANESE_RENDERER_H


#include "Shader.h"
#include "PerspectiveCamera.h"

namespace Manganese {
    class Renderer {
    public:
        static void Init();

        static void StartScene(PerspectiveCamera& camera);
        static void EndScene();

        static void DrawSquare(const glm::vec3& position, const glm::vec3& scale);
        static void DrawCube(const glm::vec3& position, const glm::vec3& scale);
    };
}


#endif //MANGANESE_RENDERER_H
