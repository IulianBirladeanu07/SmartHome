#include <iostream>
#include "CameraStopCommand.hpp"

CameraStopCommand::CameraStopCommand(std::shared_ptr<Camera> camera) : camera(camera) {
    std::cout << "CameraStopCommand::constructed" << std::endl;
}

CameraStopCommand::~CameraStopCommand() {
    std::cout << "CameraStopCommand::deconstructed" << std::endl;
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