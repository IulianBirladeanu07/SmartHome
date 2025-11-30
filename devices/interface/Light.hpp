#include <mutex>

class Light {
    private:
        int brightness;
        bool isLightOn;
        std::mutex lightMutex;

    public:
        void on();
        void off();
        void dim(int brightnessLevel);
        
        int getBrightness();
        Light();
};