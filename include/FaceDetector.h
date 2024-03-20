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
    std::string cascade_file_path;
    std::string executable_file_path;
    std::string cascade_file_suffix;
    bool found_cascade_file = false;


public:
    FaceDetector();
    ~FaceDetector();


    bool initializeCamera();
    bool CascadeFileFound();
    cv::Rect2i detectFace(cv::Mat frame);
    cv::Mat getFrame();
};

#endif // FACE_DETECTOR_H