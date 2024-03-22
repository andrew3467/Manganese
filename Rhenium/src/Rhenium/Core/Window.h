//
// Created by Andrew Graser on 3/20/2024.
//

#ifndef MANGANESE_WINDOW_H
#define MANGANESE_WINDOW_H

#include "rhpch.h"
#include "Rhenium/Events/ApplicationEvent.h"


class GLFWwindow;

namespace Manganese {
    struct WindowProps {
        uint32_t Width;
        uint32_t Height;

        std::string Title;

        WindowProps(uint32_t w, uint32_t h, const std::string& t)
            : Width(w), Height(h), Title(t)
        {

        }

        WindowProps()
                : Width(1280), Height(720), Title("Manganese Engine") {

        }
    };

    class Window {
    public:
        Window();
        Window(const WindowProps& props);
        ~Window();

        void OnUpdate();
        void ToggleCursor(bool enabled);

        GLFWwindow* GetNativeWindow() {return mWindow;}


    private:
        void InitGLFW();

        void OnApplicationEvent(const Manganese::Event<Manganese::ApplicationEvents> &e);

    private:
        WindowProps mData;
        GLFWwindow* mWindow;

        bool mCursorEnabled = true;
    };
}


#endif //MANGANESE_WINDOW_H
