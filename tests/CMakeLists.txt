
add_executable(unit_tests
    tests.cpp
    simple-tests.cpp
)

target_link_libraries(unit_tests
    
    PRIVATE
        project_warnings
        project_options
    PUBLIC
        Catch2::Catch2WithMain
        password_module

)

include(Catch)
catch_discover_tests(unit_tests)
