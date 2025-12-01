#include <iostream>
#include "PhilipsFactory.hpp"

std::shared_ptr<Device> PhilipsFactory::createDevice(DeviceType type) {
    switch(type) {
        case DeviceType::LIGHT:
            return std::make_shared<Light>("Phillips Hue", "Phillips", DeviceType::LIGHT);
        case DeviceType::CAMERA:
            return std::make_shared<Camera>("Phillips Camera", "Phillips", DeviceType::CAMERA);
        
        default:
            std::cout << "PhilipsFactory::Device Type not supported.." << std::endl;
            return nullptr;
    }
}