cmake_minimum_required(VERSION 2.8)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
set(OpenCV_DIR "/usr/local/share/OpenCV/")

project(impression-bot)

find_package(Curses REQUIRED)
find_package(ImageMagick REQUIRED COMPONENTS Magick++)
find_package(OpenCV REQUIRED COMPONENTS core imgproc highgui)
include_directories(${ImageMagick_INCLUDE_DIRS})
include_directories(${CURSES_INCLUDE_DIR})

#set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-std=c++11 -O2 -DMAGICKCORE_QUANTUM_DEPTH=16 -DMAGICKCORE_HDRI_ENABLE=0")

add_executable(
  impression-bot
	image_place.cpp
	ImpressionVisualBot.cpp
	ProductList.cpp
	turnToAlpha.cpp
	regexing.cpp
	get_file_name.cpp
	ratio_resize_prod.cpp
	down_size.cpp
	product_data.cpp
	ratio_resize_logo.cpp
	print_area_regex.cpp
	down_size.cpp
	product_data.cpp
	ratio_resize_logo.cpp 
	image_type.cpp
	place_interactive.cpp
	custom_coordinates.cpp
	find_values.cpp
)
target_link_libraries(impression-bot ${CURSES_LIBRARY})
target_link_libraries(impression-bot ${ImageMagick_LIBRARIES})
target_link_libraries(impression-bot ${OpenCV_LIBS})
