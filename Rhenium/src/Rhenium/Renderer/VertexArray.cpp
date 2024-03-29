//
// Created by Andrew Graser on 3/28/2024.
//

#include "VertexArray.h"
#include "Glad/glad.h"

namespace Manganese {

    VertexArray::VertexArray() {
        glGenVertexArrays(1, &mRendererID);
        glBindVertexArray(mRendererID);
    }

    void VertexArray::Bind() {
        glBindVertexArray(mRendererID);
    }

    void VertexArray::Unbind() {
        glBindVertexArray(0);
    }

    void VertexArray::SetVertexBuffer(const std::shared_ptr<VertexBuffer> &buffer) {
        mVertexBuffer = buffer;

        glBindVertexArray(mRendererID);
        buffer->Bind();


        int index = 0;
        const auto& layout = buffer->GetLayout();
        for(const auto& element : layout.Elements) {

            glEnableVertexAttribArray(index);
            glVertexAttribPointer(
                    index,
                    element.Size,
                    element.Type,
                    element.Normalized ? GL_TRUE : GL_FALSE,
                    layout.Stride,
                    (const void*)(element.Offset)
                    );

            index++;
        }
    }

    void VertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer> &buffer) {
        mIndexBuffer = buffer;

        glBindVertexArray(mRendererID);
        buffer->Bind();
    }
}