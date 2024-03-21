//
// Created by Andrew Graser on 3/20/2024.
//

#include "EventHandler.h"

namespace Manganese {
    std::unique_ptr<EventHandler> EventHandler::sInstance = nullptr;

    EventHandler *EventHandler::GetInstance() {
        if(!sInstance){
            sInstance = std::make_unique<EventHandler>();
        }

        return sInstance.get();
    }


}