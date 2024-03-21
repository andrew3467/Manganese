//
// Created by Andrew Graser on 3/20/2024.
//

#ifndef MANGANESE_EVENTHANDLER_H
#define MANGANESE_EVENTHANDLER_H

#include "Event.h"
#include "ApplicationEvent.h"

namespace Manganese {
    class EventHandler {
    public:
        EventHandler() : ApplicationEventDispatcher() {}
        static EventHandler* GetInstance();

        EventDispatcher<ApplicationEvents> ApplicationEventDispatcher;

    private:
        static std::unique_ptr<EventHandler> sInstance;
    };

#define EVENTS_ADD_APPLICATION_LISTENER(eventType, func, arg) EventHandler::GetInstance()->ApplicationEventDispatcher.AddListener(eventType, std::bind(&func, this, std::placeholders::_1))


#define SEND_APPLICATION_EVENT(_eventType) EventHandler::GetInstance()->ApplicationEventDispatcher.SendEvent(_eventType)
}

#endif //MANGANESE_EVENTHANDLER_H
