cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_C_COMPILER /usr/bin/gcc)

project(MyWebcamApp)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# # For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)
set (GTEST_BOTH_LIBRARIES gtest gtest_main)


list(APPEND CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/opencv4/")

# Find required packages
find_package(PkgConfig)
find_package(OpenCV REQUIRED)

message(STATUS "OpenCV_INCLUDE_DIRS = ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV_LIBS = ${OpenCV_LIBS}")


# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories( "/usr/lib/x86_64-linux-gnu/cmake/opencv4/" )
include_directories("${CMAKE_SOURCE_DIR}/build/_deps/googletest-src/googletest/include/gtest/")


# Add executable
add_executable(MyWebcamApp src/main.cpp src/FaceDetector.cpp)

# Link libraries
target_link_libraries(MyWebcamApp ${OpenCV_LIBS})

message("testing")
enable_testing()


#Add your test executable
add_executable(MyWebcamAppTests tests/test_main.cpp src/FaceDetector.cpp)
target_link_libraries(MyWebcamAppTests ${GTEST_BOTH_LIBRARIES} ${OpenCV_LIBS})
gtest_discover_tests(MyWebcamAppTests)