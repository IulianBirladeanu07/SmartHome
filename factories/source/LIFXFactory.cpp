#include <iostream>
#include "LIFXFactory.hpp"

std::shared_ptr<Device> LIFXFactory::createDevice(DeviceType type) {
    switch(type) {
        case DeviceType::LIGHT:
            return std::make_shared<Light>("LIFX Light", "LIFX", DeviceType::LIGHT);

        default:
            std::cout << "LIFXFactory::Device Type not supported.." << std::endl;
            return nullptr;
    }
}