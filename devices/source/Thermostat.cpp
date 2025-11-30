#include <iostream>
#include "Thermostat.hpp"

#define MIN_TEMP 15
#define MAX_TEMP 30

Thermostat::Thermostat(const std::string& name, const std::string& manufacturer, DeviceType type) : Device(name, manufacturer, type), temperature(0) {
    std::cout << "Thermostat::constructed!" << std::endl;
}

void Thermostat::setTemperature(double newTemperature) {
    std::lock_guard<std::mutex> lock(temperatureMutex);
    if(newTemperature >= MIN_TEMP && newTemperature <= MAX_TEMP) {
        temperature = newTemperature;
        std::cout << "Tempeature was set to: " << temperature << std::endl;
    } else {
        std::cout << "Given temperaure(" << temperature << ")" << "is outside of (15-30) range" << std::endl; 
    }
}

double Thermostat::getTemperature() {
    std::lock_guard<std::mutex> lock(temperatureMutex);
    return temperature;
}

std::string Thermostat::getStatus() const {
    std::lock_guard<std::mutex> lock(temperatureMutex);
    return std::to_string(static_cast<int>(temperature)) + "°C";
}