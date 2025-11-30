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