#include <iostream>
#include "RingFactory.hpp"

std::shared_ptr<Device> RingFactory::createDevice(DeviceType type) {
    switch(type) {
        case DeviceType::DOOR_LOCK:
            return std::make_shared<Light>("Ring DoorLock", "RING", DeviceType::DOOR_LOCK);
        case DeviceType::CAMERA:
            return std::make_shared<Camera>("Ring Camera", "RING", DeviceType::CAMERA);
        
        default:
            std::cout << "RingFactory::Device Type not supported.." << std::endl;
            return nullptr;
    }
}