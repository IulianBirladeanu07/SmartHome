#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <iostream>
#include <string>

enum class DeviceType {
    LIGHT = 0,
    CAMERA,
    DOOR_LOCK,
    THERMOSTAT,
};

class Device {
    protected:
        std::string name;
        std::string manufacturer;
        DeviceType type;
    
    public:
        Device(const std::string& name, const std::string& manufacturer, DeviceType type);
        virtual ~Device() = default;

        std::string getName() const;
        std::string getManufacturer() const;
        std::string getTypeString() const;

        DeviceType getType() const;
        virtual std::string getStatus() const = 0;
        virtual void printInfo() const;
};

#endif // DEVICE_HPP