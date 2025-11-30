#include <memory>

#include "Light.hpp"
#include "Command.hpp"

class LightDimCommand: public Command {
    private:
        int previousBrightness;
        int targetBrightness;
        std::shared_ptr<Light> light;

    public:
        void execute() override;
        void undo() override;

        LightDimCommand(std::shared_ptr<Light> light, int targetBrightness);
        ~LightDimCommand();
};