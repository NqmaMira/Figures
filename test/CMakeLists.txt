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
        readerlib
        randfactorylib
)

target_sources(
    unit-tests
    PRIVATE
        "test-triangle.cpp"
        "test-circle.cpp"
        "test-rectangle.cpp"
        "test-reader.cpp"
        "test-randfactory.cpp"
)

# Automatically register all tests
catch_discover_tests(unit-tests ADD_TAGS_AS_LABELS)
