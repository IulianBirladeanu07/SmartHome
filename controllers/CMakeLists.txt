add_library(controllers
    source/HomeController.cpp
    source/SecurityManager.cpp
)

target_link_libraries(controllers PUBLIC
    devices
)
target_include_directories(controllers PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/interface
)