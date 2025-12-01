#ifndef RING_FACTORY_HPP
#define RING_FACTORY_HPP

#include "DeviceFactory.hpp"

class RingFactory : public DeviceFactory {
    public:
        std::shared_ptr<Device> createDevice(DeviceType type) override;
};

#endif // RING_FACTORY_HPP