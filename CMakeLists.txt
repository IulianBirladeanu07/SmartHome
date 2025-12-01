cmake_minimum_required(VERSION 3.28)
project(SmartHome)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(devices)
add_subdirectory(commands)
add_subdirectory(observers)
add_subdirectory(factories)
add_subdirectory(controllers)

add_executable(SmartHome
    main.cpp
)

target_link_libraries(SmartHome
    devices
    commands
    observers
    factories
    controllers
)

target_include_directories(SmartHome PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/devices/interface
    ${CMAKE_CURRENT_SOURCE_DIR}/commands/interface
    ${CMAKE_CURRENT_SOURCE_DIR}/observers/interface
    ${CMAKE_CURRENT_SOURCE_DIR}/factories/interface
    ${CMAKE_CURRENT_SOURCE_DIR}/controllers/interface
)
if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "In-source builds are not allowed. Use a separate build/ directory.")
endif()