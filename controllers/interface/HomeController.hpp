#ifndef HOME_CONTROLLER_HPP
#define HOME_CONTROLLER_HPP

#include <mutex>
#include <memory>
#include <vector>

#include "Device.hpp"

class HomeController {
    private:
        static std::once_flag initFlag;
        mutable std::mutex devicesMutex;
        
        std::vector<std::shared_ptr<Device>> devices;
        
        HomeController();
        HomeController(const HomeController&) = delete;
        HomeController& operator=(const HomeController&) = delete;
        HomeController(const HomeController&&) = delete;
        HomeController& operator=(const HomeController&&) = delete;

    public:
        static HomeController& getInstance();

        void registerDevice(std::shared_ptr<Device> device);
        void unregisterDevice(std::shared_ptr<Device> device);
        void listAllDevices() const;

        int getDeviceCount() const;
};

#endif