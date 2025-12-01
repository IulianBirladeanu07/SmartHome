add_library(factories
    source/PhilipsFactory.cpp
    source/LIFXFactory.cpp
    source/NestFactory.cpp
    source/RingFactory.cpp
)

target_link_libraries(factories PUBLIC
    devices
)

target_include_directories(factories PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/interface
)