add_library(observers
    source/TemperatureSensor.cpp
    source/MotionSensor.cpp
    source/DoorSensor.cpp
    source/Observer.cpp
    source/Subject.cpp
)

target_include_directories(observers PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/interface
)