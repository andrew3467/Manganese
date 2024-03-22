//
// Created by Andrew Graser on 3/18/2024.
//


#include "rhpch.h"
#include "Application.h"
#include "Log/Log.h"
#include "Events/EventHandler.h"


#include "Glad/glad.h"
#include "Renderer/Renderer.h"


namespace Manganese {
    Application* Application::sInstance = nullptr;

    void Application::OnApplicationEvent(const Event<ApplicationEvents>& e) {
        if(e.GetType() == ApplicationEvents::WindowClose) {
            mRunning = false;
        }
    }


    void Application::Run() {
        Log::Init();

        sInstance = this;

        mWindow = std::make_unique<Window>();
        Renderer::Init();
        EVENTS_ADD_APPLICATION_LISTENER(ApplicationEvents::WindowClose, Application::OnApplicationEvent, this);

        std::shared_ptr<Shader> shader = std::make_shared<Shader>("../../assets/shaders/Solid_Unlit.glsl");
        mCameraController = std::make_shared<PerspectiveCameraController>(0.5f, 2.0f);

        while(mRunning){
            for(auto& layer : mLayerStack){
                layer->OnUpdate();
            }

            mCameraController->ProcessInput(1);

            glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            shader->Bind();
            shader->SetMat4("uViewProj", mCameraController->GetCamera().GetViewProjection());
            Renderer::DrawSquare(shader, glm::vec3(0.0f), glm::vec3(1.0f));

            mWindow->OnUpdate();
        }
    }

    void Application::PushLayer(Manganese::Layer *layer) {
        mLayerStack.PushLayer(layer);
        layer->OnCreate();
    }
}