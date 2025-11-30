#include <iostream>
#include "CameraStopCommand.hpp"

CameraStopCommand::CameraStopCommand(std::shared_ptr<Camera> camera) : camera(camera) {
    std::cout << "Camera was constructed" << std::endl;
}

void CameraStopCommand::execute() {
    previousState = camera->isRecording();
    camera->stopRecording();
}

void CameraStopCommand::undo() {
    if(previousState) {
        camera->startRecording();
    }
}