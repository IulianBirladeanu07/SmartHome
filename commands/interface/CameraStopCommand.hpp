#include <memory>

#include "Camera.hpp"
#include "Command.hpp"

class CameraStopCommand: public Command {
    private:
        bool previousState;
        std::shared_ptr<Camera> camera;

    public:
        void execute() override;
        void undo() override;

        CameraStopCommand(std::shared_ptr<Camera> camera);
        ~CameraStopCommand();
};
