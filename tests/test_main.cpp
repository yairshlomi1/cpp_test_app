
#include <iostream>
#include <opencv2/opencv.hpp>
#include <gtest/gtest.h>
#include <FaceDetector.h>

FaceDetector face_detector;

// Test initialization of the camera
TEST(CameraTest, InitializeCamera) {
    ASSERT_TRUE(face_detector.initialize_camera());
}

// Test the face detection functionality (mocked)
TEST(FaceDetectionTest, DetectFace) {
    //blank frame
    cv::Mat frame = cv::Mat::zeros(640, 480, CV_8UC3); 
    ASSERT_TRUE(face_detector.detect_face(frame).x == 0); // Assuming face is never detected for this mock
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
