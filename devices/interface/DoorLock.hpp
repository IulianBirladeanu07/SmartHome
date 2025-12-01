#ifndef DOOR_LOCK_HPP
#define DOOR_LOCK_HPP

#include <string>
#include "Device.hpp"

class DoorLock : public Device{
    private:
        bool locked;
        mutable std::mutex doorMutex;

    public:
        void lock();
        void unlock();
        bool isLocked();

        std::string getStatus() const override;
        DoorLock(const std::string& name, const std::string& manufacturer, DeviceType type);
};

#endif // DOOR_LOCK_HPP