//
// Created by Andrew Graser on 3/18/2024.
//


#include "Application.h"
#include "rhpch.h"



namespace Manganese {
    void Application::Run() {
        Log::Init();

        mWindow = std::make_unique<Window>();

        while(mRunning){
            for(auto& layer : mLayerStack){
                layer->OnUpdate();
            }

            mWindow->OnUpdate();
        }
    }

    void Application::PushLayer(Manganese::Layer *layer) {
        mLayerStack.PushLayer(layer);
        layer->OnCreate();
    }
}