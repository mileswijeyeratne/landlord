file(GLOB common_SRC
	"*.h"
	"*.cpp"
)

add_library(common STATIC ${common_SRC})

target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
