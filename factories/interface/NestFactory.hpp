#ifndef NEST_FACTORY_HPP
#define NEST_FACTORY_HPP

#include "DeviceFactory.hpp"

class NestFactory : public DeviceFactory {
    public:
        std::shared_ptr<Device> createDevice(DeviceType type) override;
};

#endif // NEST_FACTORY_HPP