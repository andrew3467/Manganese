//
// Created by Andrew Graser on 3/8/2024.
//

#ifndef VOXEL_RENDERER_PERSPECTIVECAMERACONTROLLER_H
#define VOXEL_RENDERER_PERSPECTIVECAMERACONTROLLER_H


#include <memory>
#include "PerspectiveCamera.h"
#include "Rhenium/Core/Timestep.h"

#include <GLFW/glfw3.h>


namespace Manganese {
    class PerspectiveCameraController {
    public:
        PerspectiveCameraController(float moveSpeed, float sensitivity);

        ~PerspectiveCameraController();

        inline PerspectiveCamera &GetCamera() const { return *mCamera; }

        void ProcessInput(Timestep ts);

    private:
        void KeyboardInput(Timestep ts);

        void MouseInput(Timestep ts);

    private:
        std::shared_ptr<PerspectiveCamera> mCamera;

        float mMoveSpeed;
        float mSensitivity;

        float mLastX, mLastY;

        bool mFirstMouse = true;
        bool mFirstScrollDown = true;
    };
}


#endif //VOXEL_RENDERER_PERSPECTIVECAMERACONTROLLER_H
