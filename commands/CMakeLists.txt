add_library(commands
    source/CameraStartCommand.cpp
    source/CameraStopCommand.cpp
    source/DoorLockCommand.cpp
    source/DoorUnlockCommand.cpp
    source/LightDimCommand.cpp
    source/LightOffCommand.cpp
    source/LightOnCommand.cpp
    source/ThermostatSetCommand.cpp
)

target_include_directories(commands PUBLIC
    ${CMAKE_SOURCE_DIR}/interface
)