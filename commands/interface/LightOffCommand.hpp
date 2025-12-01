#ifndef LIGHT_OFF_COMMAND_HPP
#define LIGHT_DIM_COMMAND_HPP

#include <memory>

#include "Light.hpp"
#include "Command.hpp"

class LightOffCommand: public Command {
    private:
        bool previousBrightness;
        std::shared_ptr<Light> light;
    
    public:
        void execute() override;
        void undo() override;

        LightOffCommand(std::shared_ptr<Light> light);
        ~LightOffCommand();
};

#endif // LIGHT_DIM_COMMAND_HPP