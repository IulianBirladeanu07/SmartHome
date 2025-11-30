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