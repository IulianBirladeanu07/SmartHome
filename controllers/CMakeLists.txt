add_library(controllers
    source/HomeController.cpp
    source/SecurityManager.cpp
)

target_include_directories(controllers PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/interface
)