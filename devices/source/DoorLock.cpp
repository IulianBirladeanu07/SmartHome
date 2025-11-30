#include <iostream>
#include <mutex>

#include "DoorLock.hpp"

DoorLock::DoorLock(const std::string& name, const std::string& manufacturer, DeviceType type) : Device(name, manufacturer, type), locked(false) {
    std::cout << "DoorLock::constructed!" << std::endl;
}

bool DoorLock::isLocked() {
    std::lock_guard<std::mutex> lock(doorMutex);
    return locked;
}

void DoorLock::lock() {
    std::lock_guard<std::mutex> lock(doorMutex);
    if(!locked) {
        locked = true;
        std::cout << "Door has been locked" << std::endl;
    } else {
        std::cout << "Dor is already locked" << std::endl;
    }
}

void DoorLock::unlock() {
    std::lock_guard<std::mutex> lock(doorMutex);
    if(locked) {
        locked = false;
        std::cout << "Door has been unlocked" << std::endl;
    } else {
        std::cout << "Dor is already unlocked" << std::endl;
    }
}

std::string DoorLock::getStatus() const {
    std::lock_guard<std::mutex> lock(doorMutex);
    return locked ? "Locked" : "Unlocked";
}