#include <iostream>
#include <mutex>

#include "Camera.hpp" 

Camera::Camera() : recording(true) {}

bool Camera::isRecording() {
    std::lock_guard<std::mutex> lock(cameraMutex);
    return recording;
}

void Camera::stopRecording() {
    std::lock_guard<std::mutex> lock(cameraMutex);
    if(recording) {
        recording = false;
        std::cout << "Camera Recording was STOPPED" << std::endl;
    } else {
        std::cout << "Camera is not recording" << std::endl;
    }
}

void Camera::startRecording() {
    std::lock_guard<std::mutex> lock(cameraMutex);
    if(!recording) {
        recording = true;
        std::cout << "Camera Recording was STARTED" << std::endl;
    } else {
        std::cout << "Camera is already recording" << std::endl;
    }
}