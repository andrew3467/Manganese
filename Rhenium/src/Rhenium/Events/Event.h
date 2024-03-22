//
// Created by Andrew Graser on 3/20/2024.
//

#ifndef MANGANESE_EVENT_H
#define MANGANESE_EVENT_H

#include "rhpch.h"


namespace Manganese {

    template<class T>
    class Event {
    public:
        Event() = default;
        Event(T type, const std::string& name = "") : mType(type), mName(name) {}
        virtual ~Event() = default;


        inline const T GetType() const {return mType;}
        inline const std::string& GetName() const {return mName;}

        virtual bool Handled() const {return mHandled;}

        template<typename EventType>
        inline EventType ToType() const {
            return static_cast<const EventType&>(*this);
        }


    protected:
        T mType;
        std::string mName;
        bool mHandled = false;
    };


    template<typename T>
    class EventDispatcher {
    private:
        using Func = std::function<void(const Event<T>&)>;

    public:
        void AddListener(T type, const Func& func) {
            mListeners[type].push_back(func);
        }

        void SendEvent(const Event<T>& event){
            //Check for listeners of event type
            if(mListeners.find(event.GetType()) == mListeners.end()){
                return;
            }

            for(auto&& listener : mListeners.at(event.GetType())){
                if(!event.Handled())    listener(event);
            }
        }

    private:
        std::map<T, std::vector<Func>> mListeners;
    };
}

#endif //MANGANESE_EVENT_H
