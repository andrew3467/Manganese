//
// Created by Andrew Graser on 3/18/2024.
//


#include "rhpch.h"
#include "Application.h"
#include "Log/Log.h"
#include "Events/EventHandler.h"


#include "Glad/glad.h"
#include "Renderer/Renderer.h"
#include "Timestep.h"


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

        mCameraController = std::make_shared<PerspectiveCameraController>(5.0f, 25.0f);

        while(mRunning){
            float time = (float)glfwGetTime();     //Platform::GetTime()
            Timestep timestep = time - mLastFrameTime;
            mLastFrameTime = time;

            for(auto& layer : mLayerStack){
                layer->OnUpdate(timestep);
            }

            mCameraController->ProcessInput(timestep);

            glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            Renderer::StartScene(mCameraController->GetCamera());

            Renderer::DrawSquare(glm::vec3(0.0f), glm::vec3(1.0f));

            Renderer::EndScene();


            mWindow->OnUpdate();
        }
    }

    void Application::PushLayer(Manganese::Layer *layer) {
        mLayerStack.PushLayer(layer);
        layer->OnCreate();
    }
}