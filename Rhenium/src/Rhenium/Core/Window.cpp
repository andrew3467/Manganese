//
// Created by Andrew Graser on 3/20/2024.
//

#include "Window.h"
#include "rhpch.h"


#include <GLFW/glfw3.h>


namespace Manganese {
    bool sGLFWInitialized = false;

    Window::Window() {
        InitGLFW();
    }

    Window::Window(const WindowProps &props)
        : mData(props)
    {

    }

    Window::~Window() {

    }

    void Window::InitGLFW() {
        if (!sGLFWInitialized) {
            int success = glfwInit();
            MN_ASSERT(success, "ERROR: Failed to intialize GLFW!");

            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        }

        mWindow = glfwCreateWindow(mData.Width, mData.Height, mData.Title.c_str(), nullptr, nullptr);

        MN_ASSERT(mWindow != nullptr, "ERROR: Failed to create window!");

        glfwMakeContextCurrent(mWindow);
    }

    void Window::OnUpdate() {
        glfwPollEvents();
        glfwSwapBuffers(mWindow);
    }
}