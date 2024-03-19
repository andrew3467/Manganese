//
// Created by Andrew Graser on 3/18/2024.
//


#include "Rhenium/Core/Application.h"
#include "Rhenium/Core/EntryPoint.h"


class Sandbox : public Manganese::Application {
public:
    Sandbox(){

    }

    ~Sandbox() {

    }

    void Run() override {
        std::cout << "Hello, World!" << std::endl;
    }
};



Manganese::Application* Manganese::Application::CreateApplication() {
    return new Sandbox();
}


