add_library(common STATIC
    main.cpp
    main.h
)

target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
