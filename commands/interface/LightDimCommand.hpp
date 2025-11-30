#include "../devices/Light.hpp"
#include "Command.hpp"

class LightDimCommand: public Command {
    private:
        std::shared_ptr<Light> light;
    
    public:
        LightDimCommand(std::shared_ptr<Light> light);

        void execute() override;
        void undo() override;
};