#include <iostream>
#include "NestFactory.hpp"

std::shared_ptr<Device> NestFactory::createDevice(DeviceType type) {
    switch(type) {
        case DeviceType::THERMOSTAT:
            return std::make_shared<Light>("Nest Thermostat", "Nest", DeviceType::THERMOSTAT);
        case DeviceType::CAMERA:
            return std::make_shared<Camera>("Nest Camera", "Nest", DeviceType::CAMERA);
        
        default:
            std::cout << "NestFactory::Device Type not supported.." << std::endl;
            return nullptr;
    }
}