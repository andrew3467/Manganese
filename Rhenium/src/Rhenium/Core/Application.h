//
// Created by Andrew Graser on 3/18/2024.
//

#ifndef MANGANESE_APPLICATION_H
#define MANGANESE_APPLICATION_H

#include <iostream>

namespace Manganese {
    class Application {
    public:
        static Application* CreateApplication();

    public:
        virtual void Run() = 0;


    };
}


#endif //MANGANESE_APPLICATION_H
