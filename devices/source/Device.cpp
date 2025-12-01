#include "Device.hpp"

Device::Device(const std::string& name, const std::string& manufacturer, DeviceType type) : name(name),
                                                                                            manufacturer(manufacturer),
                                                                                            type(type) {
    std::cout << "Device::constructed!" << std::endl;
}

std::string Device::getName() const {
    return name;
}

std::string Device::getManufacturer() const {
    return manufacturer;
}

std::string Device::getTypeString() const {
    switch(type) {
        case DeviceType::LIGHT:
            return "Light";
        case DeviceType::CAMERA:
            return "Camera";
        case DeviceType::THERMOSTAT:
            return "Thermostat";
        case DeviceType::DOOR_LOCK:
            return "DoorLock";
        default:
            return "Unknown";
    }
}

void Device::printInfo() const {
    std::cout << "[" << getTypeString() << "] " 
              << name << " (" << manufacturer << ") - " 
              << getStatus() 
              << std::endl;
}

DeviceType Device::getType() const{
    return type;
}

