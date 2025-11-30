#include <iostream>
#include "ThermostatSetCommand.hpp"
            
ThermostatSetCommand::ThermostatSetCommand(std::shared_ptr<Thermostat> thermostat, double targetTemperature)  :
                                            thermostat(thermostat),
                                            previousTemperature(0),
                                            targetTemperature(targetTemperature) {
    std::cout << "ThermostatSetCommand::constructed!" << std::endl;
}

ThermostatSetCommand::~ThermostatSetCommand() {
    std::cout << "ThermostatSetCommand::destructed!" << std::endl;
}

void ThermostatSetCommand::execute() {
    previousTemperature = thermostat->getTemperature();
    thermostat->setTemperature(targetTemperature);
}

void ThermostatSetCommand::undo() {
    thermostat->setTemperature(previousTemperature);
}