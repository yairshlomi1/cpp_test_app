// FaceDetector.h
#ifndef FACE_DETECTOR_H
#define FACE_DETECTOR_H

#include <opencv2/core/mat.hpp> 

class FaceDetector {
public:
    FaceDetector();
    ~FaceDetector();
    
    int detectFaces(const cv::Mat& frame);
    bool initialize_camera();
    bool detect_face();

};

#endif // FACE_DETECTOR_H