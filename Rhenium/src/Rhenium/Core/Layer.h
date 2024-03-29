//
// Created by Andrew Graser on 3/19/2024.
//

#ifndef MANGANESE_LAYER_H
#define MANGANESE_LAYER_H


#include "Timestep.h"

namespace Manganese {
    class Layer {
    public:
        virtual ~Layer() = default;

        virtual void OnCreate() {};

        virtual void OnDestroy() {};

        virtual void OnUpdate(Timestep ts) {};

        virtual void OnImguiUpdate() {};
    };

}

#endif //MANGANESE_LAYER_H
