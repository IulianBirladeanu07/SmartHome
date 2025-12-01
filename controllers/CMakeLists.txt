add_library(controllers
    source/HomeController.cpp
    source/RemoteController.cpp
)

target_link_libraries(controllers PUBLIC
    devices
    commands
)
target_include_directories(controllers PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/interface
)