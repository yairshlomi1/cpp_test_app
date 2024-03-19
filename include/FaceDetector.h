// FaceDetector.h
#ifndef FACE_DETECTOR_H
#define FACE_DETECTOR_H

#include <opencv2/objdetect.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/mat.hpp>

class FaceDetector
{
private:
    cv::Mat frame;
    cv::VideoCapture cap;
    cv::CascadeClassifier face_cascade;

public:
    FaceDetector();
    ~FaceDetector();


    bool initialize_camera();
    cv::Rect2i detect_face(cv::Mat frame);
    cv::Mat get_frame();
};

#endif // FACE_DETECTOR_H