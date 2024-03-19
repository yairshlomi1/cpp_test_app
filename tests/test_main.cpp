#include <gtest/gtest.h>
#include <iostream>
#include <FaceDetector.h>

FaceDetector face_detector;

// Test initialization of the camera
TEST(CameraTest, InitializeCamera) {
    ASSERT_TRUE(face_detector.initialize_camera());
}

// Test the face detection functionality (mocked)
TEST(FaceDetectionTest, DetectFace) {
    ASSERT_TRUE(face_detector.detect_face()); // Assuming face is always detected for this mock
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
