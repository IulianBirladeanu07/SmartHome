#include "../devices/Thermostat.hpp"
#include "Command.hpp"

class ThermostatSetCommand: public Command {
    private:
        std::shared_ptr<Thermostat> thermostat;
    
    public:
        void execute() override;
        void undo() override;

        ~ThermostatSetCommand();
};