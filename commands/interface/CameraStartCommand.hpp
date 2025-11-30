#include "../devices/Camera.hpp"
#include "Command.hpp"

class CameraStartCommand: public Command {
    private:
        std::shared_ptr<Camera> camera;

    public:
        void execute() override;
        void undo() override;

        ~CameraStartCommand();
};
