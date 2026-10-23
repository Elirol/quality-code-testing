
add_library(password_module

    src/passwords.c
    src/function.c
    
)

target_include_directories(password_module

    PUBLIC
        include

)

target_link_libraries(password_module

    PRIVATE
        project_warnings
        project_options

)
