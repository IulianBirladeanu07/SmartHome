add_library(observers
    source/TemperatureSensor.cpp
    source/MotionSensor.cpp
    source/DoorSensor.cpp
    source/Subject.cpp
)

target_link_libraries(observers
    commands
 )
target_include_directories(observers PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/interface
)