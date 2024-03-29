//
// Created by Andrew Graser on 3/28/2024.
//

#ifndef MANGANESE_VERTEXARRAY_H
#define MANGANESE_VERTEXARRAY_H

#include "rhpch.h"
#include "Rhenium/Renderer/Buffer.h"


namespace Manganese {
    class VertexArray {
    public:
        VertexArray();
        ~VertexArray() = default;

        void Bind();
        void Unbind();

        inline VertexBuffer& GetVertexBuffer() { return *mVertexBuffer;}
        inline IndexBuffer& GetIndexBuffer() { return *mIndexBuffer;}

        void SetVertexBuffer(const std::shared_ptr<VertexBuffer>& buffer);
        void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& buffer);

    private:
        uint32_t mRendererID;

        std::shared_ptr<VertexBuffer> mVertexBuffer;
        std::shared_ptr<IndexBuffer> mIndexBuffer;
    };
}


#endif //MANGANESE_VERTEXARRAY_H
