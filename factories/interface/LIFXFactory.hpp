#ifndef LIFX_FACTORY_HPP
#define LIFX_FACTORY_HPP

#include "DeviceFactory.hpp"

class LIFXFactory : public DeviceFactory {
    public:
        std::shared_ptr<Device> createDevice(DeviceType type) override;
};

#endif // LIFX_FACTORY_HPP