# Sample static library
add_library(trianglelib STATIC)

set_target_properties(trianglelib PROPERTIES OUTPUT_NAME "triangle")

target_sources(
    trianglelib
    PRIVATE
        "triangle.cpp"
        "triangle.h"
)


# Executable target for the application
add_executable(application)

set_target_properties(application PROPERTIES OUTPUT_NAME "figures")

target_link_libraries(
    application
    PRIVATE
        trianglelib
)

target_sources(
    application
    PRIVATE
        "application.cpp"
)