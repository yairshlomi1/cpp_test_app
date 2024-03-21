# Task Summery

I Was required to demonstrate my proficiency in software development practices, focusing on environment setup, build automation, and CI/CD pipeline configuration. My task involved a C++ project hosted in a Git repository, which includes a test suite using Google Test.

## Objectives

1. **Environment Setup and Local Execution:**
   - the sample c++ program could not be ran on my PC as the path to the cascade file was hardcoded with username, so I took few steps to solve this issue:
      1. the program now checks the path of the executable file
      2. this path is concatenated to the location of the cascade file inside the repository
      3. the program checks if the file exists, and changes a flag to indicate if the cascade file found. if not, the program will end.


2. **CI/CD Pipeline Configuration:**
   - I've used GitHub Actions CI/CD pipeline and chose one of the suggested actions that runs on each push and pull request

   - using opencv and esespecially cap.open function required few steps to make the action work:
      1. add opencv installation as part of the build steps
      2. add a video_test.mp4 video to the repository for test purposes.
      3. change the initializeCamera code to open specific capture device depends on TEST_VIDEO_PATH environment variable.
      4. in the job yaml I've added a step that sets this variable to the path of the video_test.mp4 in the repository
   - as a result of these steps the action uses the test video for cap.open instead of trying to open a capture device and fail.

3. **Instructions:**
   - build:
      ```bash 
      mkdir build && cd build
      cmake ..
      make && ctest
      ```
   - run:
      ```bash 
      ./MyWebcamApp
      ```
