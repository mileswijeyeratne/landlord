file(GLOB common_SRC
	"*.h"
	"*.cpp"
)


list(FILTER common_SRC EXCLUDE REGEX "tests/combo.cpp$")

# normal library
add_library(common STATIC ${common_SRC})
target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# tests
add_executable(common_tests tests/combo.cpp)
target_link_libraries(common_tests common)

# enable testing
enable_testing()
add_test(NAME CommonLibraryTest COMMAND common_tests)
