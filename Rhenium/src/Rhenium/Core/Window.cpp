//
// Created by Andrew Graser on 3/20/2024.
//

#include "Window.h"
#include "rhpch.h"

#include "Rhenium/Events/EventHandler.h"


#include <GLFW/glfw3.h>
#include <Glad/glad.h>


namespace Manganese {
    static void GLFWErrorCallback(int error_code, const char* description) {
        MN_ERROR("GLFW ERROR: {0}, {1}", error_code, description);
    }



    bool sGLFWInitialized = false;

    void Window::OnApplicationEvent(const Event<ApplicationEvents>& e) {
        if(e.GetType() == ApplicationEvents::WindowResize) {
            auto event = e.ToType<WindowResizeEvent>();
            glfwSetWindowSize(mWindow, event.Width, event.Height);
        }
    }

    Window::Window() {
        InitGLFW();

        //TODO: Move to rendering api class
        int success = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        MN_ASSERT(success, "ERROR: Failed to initialize GLAD!");
    }

    Window::Window(const WindowProps &props)
        : mData(props)
    {

    }

    Window::~Window() {

    }

    void Window::InitGLFW() {
        if (!sGLFWInitialized) {
            glfwSetErrorCallback(GLFWErrorCallback);

            int success = glfwInit();
            MN_ASSERT(success, "ERROR: Failed to initialize GLFW!");

            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        }

        mWindow = glfwCreateWindow(mData.Width, mData.Height, mData.Title.c_str(), nullptr, nullptr);

        MN_ASSERT(mWindow != nullptr, "ERROR: Failed to create window!");

        glfwMakeContextCurrent(mWindow);

        // Events
        EVENTS_ADD_APPLICATION_LISTENER(ApplicationEvents::WindowClose, Window::OnApplicationEvent, this);

        //callbacks
        glfwSetWindowCloseCallback(mWindow, [](GLFWwindow* window) {
            WindowCloseEvent e;

            SEND_APPLICATION_EVENT(e);
        });

        glfwSetWindowSizeCallback(mWindow, [](GLFWwindow* window, int width, int height){
            WindowResizeEvent e;
            e.Width = width;
            e.Height = height;


            SEND_APPLICATION_EVENT(e);
        });
    }

    void Window::OnUpdate() {
        glfwPollEvents();
        glfwSwapBuffers(mWindow);
    }
}