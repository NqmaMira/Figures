# Triangle static library
add_library(trianglelib STATIC)

set_target_properties(trianglelib PROPERTIES OUTPUT_NAME "triangle")

target_sources(
    trianglelib
    PRIVATE
        "triangle.cpp"
        "triangle.h"
)

# Circle static library
add_library(circlelib STATIC)

set_target_properties(circlelib PROPERTIES OUTPUT_NAME "circle")

target_sources(
    circlelib
    PRIVATE
        "circle.cpp"
        "circle.h"
)

# Rectangle static library
add_library(rectanglelib STATIC)

set_target_properties(rectanglelib PROPERTIES OUTPUT_NAME "rectangle")

target_sources(
    rectanglelib
    PRIVATE
        "rectangle.cpp"
        "rectangle.h"
)

# Helper static library
add_library(helperlib STATIC)

set_target_properties(helperlib PROPERTIES OUTPUT_NAME "helper")

target_sources(
    helperlib
    PRIVATE
        "compareDoubles.cpp"
)

# Reader static library
add_library(readerlib STATIC)

set_target_properties(readerlib PROPERTIES OUTPUT_NAME "reader")

target_sources(
    readerlib
    PRIVATE
        "stringToFigure.h"
        "stringToFigure.cpp"
        "triangleReader.h"
        "triangleReader.cpp"
        "circleReader.h"
        "circleReader.cpp"
        "rectangleReader.h"
        "rectangleReader.cpp"
)

# RandFactory static library
add_library(randfactorylib STATIC)

set_target_properties(randfactorylib PROPERTIES OUTPUT_NAME "randfactory")

target_sources(
    randfactorylib
    PRIVATE
        "randomFigureFactory.h"
        "randomFigureFactory.cpp"
)

# Executable target for the application
add_executable(application)

set_target_properties(application PROPERTIES OUTPUT_NAME "figures")

target_link_libraries(
    application
    PRIVATE
        helperlib
        trianglelib
        circlelib
        rectanglelib
        readerlib
        randfactorylib
)

target_sources(
    application
    PRIVATE
        "application.cpp"
)