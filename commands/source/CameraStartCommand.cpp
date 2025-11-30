#include <iostream>
#include "CameraStartCommand.hpp"

CameraStartCommand::CameraStartCommand(std::shared_ptr<Camera> camera) : camera(camera) {
    std::cout << "Camera was constructed" << std::endl;
}

void CameraStartCommand::execute() {
    previousState = camera->isRecording();
    camera->startRecording();
}

void CameraStartCommand::undo() {
    if(!previousState) {
        camera->stopRecording();
    }
}