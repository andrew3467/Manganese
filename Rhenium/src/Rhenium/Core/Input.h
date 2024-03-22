//
// Created by Andrew Graser on 3/22/2024.
//

#ifndef MANGANESE_INPUT_H
#define MANGANESE_INPUT_H


namespace Manganese {
    class Input {
    public:
        static bool IsKeyPressed(int keycode);
        static bool IsMouseButtonPressed(int button);

        static float GetMouseX();
        static float GetMouseY();
        static void SetMousePos(float x, float y);
        static std::pair<float, float> GetMousePos();
    };
}


#endif //MANGANESE_INPUT_H
