#ifndef THERMOSTAT_SET_COMMAND_HPP
#define THERMOSTAT_SET_COMMAND_HPP

#include <memory>

#include "Thermostat.hpp"
#include "Command.hpp"

class ThermostatSetCommand: public Command {
    private:
        double previousTemperature;
        double targetTemperature;
        std::shared_ptr<Thermostat> thermostat;
    
    public:
        void execute() override;
        void undo() override;

        ThermostatSetCommand(std::shared_ptr<Thermostat> thermostat, double targetTemperature);
        ~ThermostatSetCommand();
};

#endif