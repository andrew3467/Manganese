//
// Created by Andrew Graser on 3/22/2024.
//

#ifndef MANGANESE_BUFFER_H
#define MANGANESE_BUFFER_H

#include <Glad/glad.h>

namespace Manganese {
    struct LayoutElement {
        uint32_t Size;      //Num of values
        uint32_t Type;
        uint32_t Offset;

        bool Normalized;
    };

    struct VertexBufferLayout {
        VertexBufferLayout() = default;
        VertexBufferLayout(const std::initializer_list<LayoutElement> elements) : Elements(elements), Stride(0) {
            for(auto& elem : elements) {
                //TODO: Create Dedicated function when abstracting platform API
                Stride += elem.Size * sizeof(float);
            }
        }

        uint32_t Stride;
        std::vector<LayoutElement> Elements;
    };

    class VertexBuffer {
    public:
        VertexBuffer(float *data, uint32_t size);
        ~VertexBuffer() = default;

        void SetLayout(const VertexBufferLayout& layout) {mLayout = layout;}
        const VertexBufferLayout& GetLayout() const {return mLayout;}

        void Bind();
        void Unbind();


    private:
        uint32_t mRendererID;
        VertexBufferLayout mLayout;
    };

    class IndexBuffer {
    public:
        IndexBuffer(uint32_t *data, uint32_t count);
        ~IndexBuffer() = default;

        void Bind();
        void Unbind();

        uint32_t GetCount() const;

    private:
        uint32_t mRendererID;
        uint32_t mCount;
    };
}


#endif //MANGANESE_BUFFER_H
