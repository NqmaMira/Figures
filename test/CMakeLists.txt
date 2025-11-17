# Executable target for the unit tests
add_executable(unit-tests)

target_link_libraries(
    unit-tests
    PRIVATE
        helperlib
        trianglelib
        circlelib
        rectanglelib
        Catch2::Catch2WithMain
        factorylib
)

target_sources(
    unit-tests
    PRIVATE
        "test-triangle.cpp"
        "test-circle.cpp"
        "test-rectangle.cpp"
        "test-strFactory.cpp"
)

# Automatically register all tests
catch_discover_tests(unit-tests ADD_TAGS_AS_LABELS)
