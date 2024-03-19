#include <iostream>
#include <FaceDetector.h>


#define CAP_N 0

FaceDetector face_detector;

int main() {
    if (!face_detector.initialize_camera()) {
        std::cerr << "Camera initialization failed!\n";
        return 1;
    }

    if (face_detector.detect_face()) {
        std::cout << "Face detected!\n";
    } else {
        std::cout << "No face detected.\n";
    }

    return 0;
}
