//
// Created by Andrew Graser on 3/20/2024.
//

#ifndef MANGANESE_APPLICATIONEVENT_H
#define MANGANESE_APPLICATIONEVENT_H

#include "Event.h"

namespace Manganese {
    enum class ApplicationEvents {
        WindowResize,
        WindowClose
    };

    class WindowCloseEvent : public Event<ApplicationEvents> {
    public:
        WindowCloseEvent() : Event<ApplicationEvents>(ApplicationEvents::WindowClose, "WindowClose") {}
        virtual ~WindowCloseEvent() override {}
    };

    class WindowResizeEvent : public Event<ApplicationEvents> {
    public:
        WindowResizeEvent() : Event<ApplicationEvents>(ApplicationEvents::WindowResize, "WindowResize") {}
        virtual ~WindowResizeEvent() override {}


        uint32_t Width, Height;
    };
}

#endif //MANGANESE_APPLICATIONEVENT_H
