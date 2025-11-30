#include <mutex>
#include <string>

#include "Device.hpp"

class Light : public Device {
    private:
        int brightness;
        bool isLightOn;
        mutable std::mutex lightMutex;

    public:
        void on();
        void off();
        void dim(int brightnessLevel);
        
        int getBrightness();

        std::string getStatus() const override;
        Light(const std::string& name, const std::string& manufacturer, DeviceType type);
};