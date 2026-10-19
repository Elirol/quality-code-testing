cmake_minimum_required(VERSION 3.16)

project(generating_passwords)

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
target_compile_features(project_options INTERFACE c_std_17)

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

message("Compiler:         \t ${CMAKE_CXX_COMPILER_ID}")
message("Colored output:   \t ${ENABLE_COLORED_OUTPUT}")
message("Testing enabled:  \t ${BUILD_TESTING}")
message("Sanitizers:       \t ${ENABLE_SANITIZER}")
message("Coverage:         \t ${ENABLE_COVERAGE}")

message("#########################################")

# --- External libraries --- #
set(LIBS_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/external")

# Catch2 #
set(CATCH2 "${LIBS_ROOT}/Catch2")       # https://github.com/catchorg/catch2

if(BUILD_TESTING)   # Only include catch2 if we compile with testing
    add_subdirectory(${CATCH2})    
endif()


# --- Main executable --- #
add_executable(Main
    main.c
    passwords.c
)

target_include_directories(Main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Main
    PRIVATE
        project_warnings
        project_options
)

# --- Testing --- #
if(BUILD_TESTING)    
    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/tests")
endif()

