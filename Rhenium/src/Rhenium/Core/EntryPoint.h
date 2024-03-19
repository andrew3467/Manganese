//
// Created by Andrew Graser on 3/18/2024.
//

#ifndef MANGANESE_ENTRYPOINT_H
#define MANGANESE_ENTRYPOINT_H

#include "Application.h"

int main() {
    auto app = Manganese::Application::CreateApplication();
    app->Run();
    delete app;
}

#endif //MANGANESE_ENTRYPOINT_H
