# include raylib
include_directories(../external/raylib/include)
link_directories(../external/raylib/lib)

# client files
add_executable(client
    main.cpp
)

# link
target_link_libraries(client PRIVATE common raylib winmm)
