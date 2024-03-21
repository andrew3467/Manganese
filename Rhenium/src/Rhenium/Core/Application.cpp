//
// Created by Andrew Graser on 3/18/2024.
//


#include "rhpch.h"
#include "Application.h"
#include "Events/EventHandler.h"


#include "Glad/glad.h"


namespace Manganese {
    void Application::OnApplicationEvent(const Event<ApplicationEvents>& e) {
        if(e.GetType() == ApplicationEvents::WindowClose) {
            mRunning = false;
        }
    }


    void Application::Run() {
        Log::Init();

        mWindow = std::make_unique<Window>();

        EVENTS_ADD_APPLICATION_LISTENER(ApplicationEvents::WindowClose, Application::OnApplicationEvent, this);

        while(mRunning){
            for(auto& layer : mLayerStack){
                layer->OnUpdate();
            }

            glClearColor(0.8f, 0.2f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            mWindow->OnUpdate();
        }
    }

    void Application::PushLayer(Manganese::Layer *layer) {
        mLayerStack.PushLayer(layer);
        layer->OnCreate();
    }
}