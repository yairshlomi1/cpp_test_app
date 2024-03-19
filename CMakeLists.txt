cmake_minimum_required(VERSION 3.10)
project(MyWebcamApp)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(GTEST_INCLUDE_DIR "C:/code/gtest/mingw64/include")
set(GTEST_LIBRARY "C:/code/gtest/mingw64/lib/libgtest.a")
set(GTEST_MAIN_LIBRARY "C:/code/gtest/mingw64/lib/libgtest_main.a")
set(OpenCV_DIR "C:/code/OpenCV-MinGW-Build")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lopencv_videoio")



# If necessary, set the path to the MinGW installation or the CMake toolchain file
set(CMAKE_MAKE_PROGRAM "C:/msys64/mingw64/bin/mingw32-make.exe")

list(APPEND CMAKE_PREFIX_PATH "C:/code/OpenCV-MinGW-Build")

# Find required packages
find_package(PkgConfig)
find_package(OpenCV REQUIRED)
message(STATUS "OpenCV_INCLUDE_DIRS = ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV_LIBS = ${OpenCV_LIBS}")

# find_library(VIDEOIO_LIB NAMES opencv_videoio PATHS ${OpenCV_LIB_DIR})
# message( STATUS "VIDEOIO_LIB = ${VIDEOIO_LIB}")


# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories( "C:/code/OpenCV-MinGW-Build/x64/mingw/bin" )

# Add executable
add_executable(MyWebcamApp src/main.cpp src/FaceDetector.cpp)

# Link libraries
target_link_libraries(MyWebcamApp ${OpenCV_LIBS})


enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

#Add your test executable
add_executable(MyWebcamAppTests tests/test_main.cpp src/FaceDetector.cpp)
target_link_libraries(MyWebcamAppTests ${GTEST_BOTH_LIBRARIES} ${OpenCV_LIBS})
gtest_discover_tests(MyWebcamAppTests)