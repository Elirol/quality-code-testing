cmake_minimum_required(VERSION 3.16)

project(Generating passwords)

# --- Options --- #
option(ENABLE_COVERAGE "Enable coverage reporting" FALSE)           # Ensures everything is covered by tests
option(ENABLE_SANITIZER "Enable address sanitizer" FALSE)           # Display additional information when doing illegal memory access
option(ENABLE_COLORED_OUTPUT "Enable colored output" FALSE)         # Add colored output to the warnings to. Only for GNU/Clang

include(CTest)
if(BUILD_TESTING)
    enable_testing()
endif()

# --- Libraries --- #
add_library(project_warnings INTERFACE)
add_library(project_options INTERFACE)

# --- Flags --- #
target_compile_features(project_options INTERFACE c_std_20)

if(ENABLE_COVERAGE)
    # Enables coverage and debugging symbols while disallowing optimization
    target_compile_options(project_options INTERFACE --coverage -O0 -g)
    target_link_libraries(project_options INTERFACE --coverage)     
endif()

if(ENABLE_SANITIZER)
    # Add additional information when accessing illegal memory locations
    target_compile_options(project_options INTERFACE -fsanitize=address)
    target_link_libraries(project_options INTERFACE -fsanitize=address)
endif()

target_compile_options(project_warnings
    # Adding warnings when compiling 
    INTERFACE
        -Wall
        -Wextra
        -Wshadow
        -Wcast-align            
        -Wunused
        -Wpedantic
        -Wconversion
        -Wsign-conversion
        -Wnull-dereference
        -Wdouble-promotion
)

# GNU specific flags
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(project_warnings
        INTERFACE
        -Wmisleading-indentation    # Better indentation warnings
        -Wduplicated-cond           # Same conditions twice in an if chain
        -Wlogical-op                # Conditions that are always true / false etc
        -Wuseless-cast                  
    )
endif()

# --- Summary message --- #
message("#########################################")
message("\t \t Summary")
message("#########################################")

message("Build type:       \t ${CMAKE_BUILD_TYPE}")
message("Compiler:         \t ${CMAKE_CXX_COMPILER_ID}")
message("Colored output:   \t ${ENABLE_COLORED_OUTPUT}")
message("Testing enabled:  \t ${BUILD_TESTING}")
message("Sanitizers:       \t ${ENABLE_SANITIZER}")
message("Coverage:         \t ${ENABLE_COVERAGE}")

message("#########################################")

