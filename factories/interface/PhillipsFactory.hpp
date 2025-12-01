#ifndef PHILLIPS_FACTORY_HPP
#define PHILLIPS_FACTORY_HPP

#include <memory>

#include "Light.hpp"
#include "Device.hpp"
#include "Camera.hpp"
#include "DeviceFactory.hpp"

class PhillipsFactory : public DeviceFactory {
    public:
        std::shared_ptr<Device> createDevice(DeviceType type);
};

#endif // PHILLIPS_FACTORY_HPP