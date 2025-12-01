#ifndef CAMERA_STOP_COMMAND_HPP
#define CAMERA_STOP_COMMAND_HPP

#include <memory>

#include "Camera.hpp"
#include "Command.hpp"

class CameraStopCommand: public Command {
    private:
        bool previousState;
        std::shared_ptr<Camera> camera;

    public:
        void execute() override;
        void undo() override;

        CameraStopCommand(std::shared_ptr<Camera> camera);
        ~CameraStopCommand();
};

#endif // CAMERA_STOP_COMMAND_HPP