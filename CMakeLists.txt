cmake_minimum_required(VERSION 3.3)
project(video-filter-sequential)

set(CMAKE_CXX_STANDARD 17)
find_package( OpenCV REQUIRED )
find_package(OpenMP REQUIRED)


if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()


set(SOURCE_FILES main.cpp)
set(SOURCE_FILES ${SOURCE_FILES} Filter/black_white.cpp Filter/black_white.h)
set(SOURCE_FILES ${SOURCE_FILES} Filter/sepia.cpp Filter/sepia.h)
set(SOURCE_FILES ${SOURCE_FILES} Filter/blur.cpp Filter/blur.h)
set(SOURCE_FILES ${SOURCE_FILES} Filter/contrast.cpp Filter/contrast.h)
set(SOURCE_FILES ${SOURCE_FILES} Filter/edge_detection.cpp Filter/edge_detection.h)
set(SOURCE_FILES ${SOURCE_FILES}  Filter/filter.cpp Filter/filter.h)
add_executable(video-filter-sequential ${SOURCE_FILES})

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(video-filter-sequential ${OpenCV_LIBS} )