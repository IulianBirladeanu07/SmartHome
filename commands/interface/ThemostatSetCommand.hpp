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

        ~ThermostatSetCommand();
};