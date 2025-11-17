# Triangle static library
add_library(trianglelib STATIC)

set_target_properties(trianglelib PROPERTIES OUTPUT_NAME "triangle")

target_sources(
    trianglelib
    PRIVATE
        "triangle.cpp"
        "triangle.h"
        "compareDoubles.cpp"
)

# Circle static library
add_library(circlelib STATIC)

set_target_properties(circlelib PROPERTIES OUTPUT_NAME "circle")

target_sources(
    circlelib
    PRIVATE
        "circle.cpp"
        "circle.h"
        "compareDoubles.cpp"
)

# Executable target for the application
add_executable(application)

set_target_properties(application PROPERTIES OUTPUT_NAME "figures")

target_link_libraries(
    application
    PRIVATE
        trianglelib
        circlelib
)

target_sources(
    application
    PRIVATE
        "application.cpp"
)