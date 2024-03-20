#include <iostream>
#include <FaceDetector.h>
#include <opencv2/highgui.hpp>

#define CAP_N 0

FaceDetector face_detector;

int main()
{
    if (!face_detector.initializeCamera())
    {
        std::cerr << "Camera initialization failed!\n";
        return 1;
    }
    while (true and face_detector.CascadeFileFound())
    {
        cv::Mat frame = face_detector.getFrame();
        // resize keep the aspect ratio
        double scale = 640.0 / frame.cols;
        cv::resize(frame, frame, cv::Size(640, frame.rows * scale));
        cv::flip(frame, frame, 1);

        cv::Rect2i r = face_detector.detectFace(frame);
        if (r.width > 0 && r.height > 0)
        {
            cv::rectangle(frame, r, cv::Scalar(0, 255, 0), 2);
        }

        cv::imshow("Frame", frame);
        if (cv::waitKey(1) == 27)
        {
            break;
        }
    }

    return 0;
}
