#ifndef PHILLIPS_FACTORY_HPP
#define PHILLIPS_FACTORY_HPP

#include <memory>
#include "DeviceFactory.hpp"

class PhilipsFactory : public DeviceFactory {
    public:
        std::shared_ptr<Device> createDevice(DeviceType type) override;
};

#endif // PHILLIPS_FACTORY_HPP