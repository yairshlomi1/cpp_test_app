// FaceDetector.cpp
#include "FaceDetector.h"

#include <opencv2/objdetect.hpp>
#include <opencv2/opencv.hpp>

FaceDetector::FaceDetector() {
}

FaceDetector::~FaceDetector() {

}


bool FaceDetector::initialize_camera() {
    cap.open(0);
    if (!cap.isOpened()) {
        std::cerr << "Error opening video stream or file" << std::endl;
        return false;
    }
    return true;
}

//get the frame from the camera
cv::Mat FaceDetector::get_frame() {
    cap >> frame;
    return frame;
}

cv::Rect2i  FaceDetector::detect_face(cv::Mat frame) {
    // Load the cascade
    //current folder is the root folder
    
    face_cascade.load(cv::samples::findFile("/home/arnon/code/cpp_test_app/haarcascades/haarcascade_frontalface_alt.xml"));
    if (frame.empty()) {
        
        return cv::Rect2i(0, 0, 0, 0);
    }
    std::vector<cv::Rect> faces;
    cv::Mat frame_gray;
    cv::cvtColor(frame, frame_gray, cv::COLOR_BGR2GRAY);
    cv::equalizeHist(frame_gray, frame_gray);
    // Detect faces
    face_cascade.detectMultiScale(frame_gray, faces);
    if (faces.size() > 0) {
        return cv::Rect2i(faces[0].x, faces[0].y, faces[0].width, faces[0].height);
    }


    return cv::Rect2i(0, 0, 0, 0);
}
