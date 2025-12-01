#ifndef LIGHT_ON_COMMAND_HPP
#define LIGHT_ON_COMMAND_HPP

#include <memory>

#include "Light.hpp"
#include "Command.hpp"

class LightOnCommand: public Command {
    private:
        int previousBrightness;
        std::shared_ptr<Light> light;
    
    public:
        LightOnCommand(std::shared_ptr<Light> light);
        ~LightOnCommand();

        void execute() override;
        void undo() override;
};

#endif // LIGHT_ON_COMMAND_HPP