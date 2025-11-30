#include <mutex>
#include <string>

#include "Device.hpp"

class Thermostat : public Device {
    private:
        double temperature;
        mutable std::mutex temperatureMutex;

    public:
        void setTemperature(double newTemperature);
        double getTemperature();

        std::string getStatus() const override;
        Thermostat(const std::string& name, const std::string& manufacturer, DeviceType type);
};