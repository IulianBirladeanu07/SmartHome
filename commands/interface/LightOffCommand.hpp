#include "../devices/Light.hpp"
#include "Command.hpp"

class LightOffCommand: public Command {
    private:
        std::shared_ptr<Light> light;
    
    public:
        LightOffCommand(std::shared_ptr<Light> light);
        ~LightOffCommand();
        void execute() override;
        void undo() override;
};