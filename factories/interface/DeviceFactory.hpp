#ifndef DEVICE_FACTORY_HPP
#define DEVICE_FACTORY_HPP

#include <memory>

#include "Light.hpp"
#include "Device.hpp"
#include "Camera.hpp"
#include "DoorLock.hpp"
#include "Thermostat.hpp"

class DeviceFactory {
    public:
        virtual std::shared_ptr<Device> createDevice(DeviceType type) = 0;
        virtual ~DeviceFactory() = default;
};

#endif // DEVICE_FACTORY_HPP