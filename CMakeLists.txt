cmake_minimum_required (VERSION 3.5)
project (videoCreator)


SET(OPENCV_ROOT "${CMAKE_SOURCE_DIR}/../opencv-3.1.0/opencv/build")
message(${OPENCV_ROOT})
include_directories(${OPENCV_ROOT}/include)

link_directories("${OPENCV_ROOT}/x64/vc12/lib")

add_executable(${PROJECT_NAME} videoCreator.cpp)

target_link_libraries(${PROJECT_NAME} opencv_world310.lib) 
