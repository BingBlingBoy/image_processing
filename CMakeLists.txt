cmake_minimum_required(VERSION 2.8.12)
project( DisplayImage )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( main ./src/main.cpp #[[ ./src/menu.cpp ./src/error_checking.cpp ]] ./src/mathematics.cpp)
target_link_libraries( main ${OpenCV_LIBS} )

