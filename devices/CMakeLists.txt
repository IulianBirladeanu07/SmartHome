add_library(devices 
    source/Device.cpp
    source/Light.cpp
    source/Camera.cpp
    source/DoorLock.cpp
    source/Thermostat.cpp
)

target_include_directories(devices PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/interface
)