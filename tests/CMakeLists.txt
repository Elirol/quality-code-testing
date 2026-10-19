
add_executable(unit_tests
    tests.cpp
)

target_include_directories(unit_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)

target_link_libraries(unit_tests
    
    PRIVATE
        project_warnings
        project_options
    PUBLIC
        Catch2::Catch2WithMain

)

include(Catch)
catch_discover_tests(unit_tests)
