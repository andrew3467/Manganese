//
// Created by Andrew Graser on 3/18/2024.
//

#ifndef MANGANESE_APPLICATION_H
#define MANGANESE_APPLICATION_H

#include "rhpch.h"
#include "LayerStack.h"
#include "Window.h"
#include "Rhenium/Events/ApplicationEvent.h"
#include "Rhenium/Renderer/PerspectiveCameraController.h"


namespace Manganese {
    class Application {
    public:
        static Application* CreateApplication();
        static Application& GetInstance() {return *sInstance;}

    public:
        void Run();


        void PushLayer(Layer* layer);
        Window& GetWindow() {return *mWindow;}

    private:
        void OnApplicationEvent(const Event<ApplicationEvents>& e);

    private:
        static Application* sInstance;

        bool mRunning = true;

        float mLastFrameTime;

        LayerStack mLayerStack;

        std::unique_ptr<Window> mWindow;
        std::shared_ptr<PerspectiveCameraController> mCameraController;
    };
}


#endif //MANGANESE_APPLICATION_H
