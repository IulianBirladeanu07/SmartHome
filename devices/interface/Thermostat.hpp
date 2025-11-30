#include <mutex>

class Thermostat {
    private:
        double temperature;
        std::mutex temperatureMutex;

    public:
        void setTemperature(double newTemperature);
        double getTemperature();

        Thermostat();
};