//
// Created by Andrew Graser on 3/18/2024.
//


#include "Rhenium/Core/Application.h"
#include "Rhenium/Core/EntryPoint.h"

#include "ExampleLayer.h"


class Sandbox : public Manganese::Application {
public:
    Sandbox(){
        PushLayer(new ExampleLayer());
    }

    ~Sandbox() {

    }
};



Manganese::Application* Manganese::Application::CreateApplication() {
    return new Sandbox();
}


