//
// Created by Andrew Graser on 3/18/2024.
//

#ifndef MANGANESE_APPLICATION_H
#define MANGANESE_APPLICATION_H


#include "LayerStack.h"
#include "Window.h"

#include <vector>
#include <memory>

namespace Manganese {
    class Application {
    public:
        static Application* CreateApplication();

    public:
        void Run();


        void PushLayer(Layer* layer);

    private:
        bool mRunning = true;

        LayerStack mLayerStack;


        std::unique_ptr<Window> mWindow;
    };
}


#endif //MANGANESE_APPLICATION_H
