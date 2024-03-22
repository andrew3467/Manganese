//
// Created by Andrew Graser on 3/19/2024.
//

#ifndef MANGANESE_EXAMPLELAYER_H
#define MANGANESE_EXAMPLELAYER_H

#include "Rhenium.h"


class ExampleLayer : public Manganese::Layer {
public:
    ExampleLayer();
    virtual ~ExampleLayer() = default;

    virtual void OnCreate() override;
    virtual void OnDestroy() override;

    virtual void OnUpdate() override;
    virtual void OnImguiUpdate() override;
};


#endif //MANGANESE_EXAMPLELAYER_H
