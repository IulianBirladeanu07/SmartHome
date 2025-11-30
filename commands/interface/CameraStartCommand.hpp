#include <memory>

#include "Camera.hpp"
#include "Command.hpp"

class CameraStartCommand: public Command {
    private:
        bool previousState;
        std::shared_ptr<Camera> camera;

    public:
        void execute() override;
        void undo() override;

        CameraStartCommand(std::shared_ptr<Camera> camera);
};
