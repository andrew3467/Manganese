//
// Created by Andrew Graser on 3/20/2024.
//

#ifndef MANGANESE_RENDERER_H
#define MANGANESE_RENDERER_H


#include "Shader.h"

namespace Manganese {
    class Renderer {
    public:
        static void Init();


        static void DrawSquare(const std::shared_ptr<Shader>& shader, const glm::vec3& position, const glm::vec3& scale);
    };
}


#endif //MANGANESE_RENDERER_H
