#include <iostream>
#include <algorithm>

#include "HomeController.hpp"

HomeController::HomeController() {
    std::cout << "HomeController::constructed!" << std::endl;
}

HomeController& HomeController::getInstance() {
    static HomeController instance;
    return instance;
}

void HomeController::registerDevice(std::shared_ptr<Device> device) {
    std::lock_guard<std::mutex> lock(devicesMutex);
    devices.push_back(device);
    std::cout << "Registered: " << device->getName() << std::endl;
}

void HomeController::unregisterDevice(std::shared_ptr<Device> device) {
    std::lock_guard<std::mutex> lock(devicesMutex);
    auto it = std::remove(devices.begin(), devices.end(), device);

    if(it != devices.end()) {
        devices.erase(it, devices.end());
        std::cout << "Unregistered: " << device->getName() << std::endl;
    }
}

void HomeController::listAllDevices() const {
    std::lock_guard<std::mutex> lock(devicesMutex);
    
    std::cout << "\n=== Registered devices ===" << std::endl;

    if(devices.empty()) {
        std::cout << "No devices registered." << std::endl;
        return;
    }
    for(const auto& device: devices) {
        device->printInfo();
    }
    std::cout << "\nTotal: " << devices.size() << "device(s)" << std::endl;
}

int HomeController::getDeviceCount() const {
    std::lock_guard<std::mutex> lock(devicesMutex);
    return devices.size(); 
}