//
// Created by Andrew Graser on 3/20/2024.
//

#ifndef MANGANESE_LAYERSTACK_H
#define MANGANESE_LAYERSTACK_H

#include "rhpch.h"
#include "Layer.h"

namespace Manganese {
    class LayerStack {
    public:
        LayerStack();
        ~LayerStack() = default;

        std::vector<Layer*>::iterator begin() {return mLayers.begin();}
        std::vector<Layer*>::iterator end() {return mLayers.end();}

        void PushLayer(Layer* layer);

    private:
        std::vector<Layer*> mLayers;
    };
}


#endif //MANGANESE_LAYERSTACK_H
