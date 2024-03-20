// FaceDetector.cpp
#include "FaceDetector.h"

#include <opencv2/objdetect.hpp>
#include <opencv2/opencv.hpp>

FaceDetector::FaceDetector()
{
    cascade_file_suffix = "/haarcascades/haarcascade_frontalface_alt.xml";
    char buffer[PATH_MAX];
    ssize_t len = readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);
    if (len != -1)
    {
        buffer[len] = '\0';
        std::string path(buffer);
        std::string path_prefix;

        std::string::size_type pos = path.find_last_of("/");
        std::string folder_path = path.substr(0, pos);
        // std::cout << "Executable folder path: " << folder_path << std::endl;
        size_t last_slash_pos = folder_path.find_last_of('/');
        if (last_slash_pos != std::string::npos)
        {
            path_prefix = folder_path.substr(0, last_slash_pos);
            // std::cout << "Project folder path: " << path_prefix << std::endl;
            cascade_file_path = path_prefix + cascade_file_suffix;
            // std::cout << "cascade file path: " << cascade_file_path << std::endl;
            if (std::filesystem::exists(cascade_file_path))
            {
                found_cascade_file = true;
            }
            else
            {
                std::cout << "could not find cascade file" << std::endl;
                found_cascade_file = false;
            }
        }
        else
        {
            std::cout << "could not find cascade file" << std::endl;
            found_cascade_file = false;
        }
    }
    else
    {
        std::cout << "could not find cascade file" << std::endl;
        found_cascade_file = false;
    }
}

FaceDetector::~FaceDetector()
{
}

bool FaceDetector::initializeCamera()
{
    cap.open(0);
    if (!cap.isOpened())
    {
        std::cerr << "Error opening video stream or file" << std::endl;
        return false;
    }
    return true;
}

// get the frame from the camera
cv::Mat FaceDetector::getFrame()
{
    cap >> frame;
    return frame;
}

cv::Rect2i FaceDetector::detectFace(cv::Mat frame)
{
    // Load the cascade
    // current folder is the root folder

    face_cascade.load(cv::samples::findFile(cascade_file_path));
    if (frame.empty())
    {

        return cv::Rect2i(0, 0, 0, 0);
    }
    std::vector<cv::Rect> faces;
    cv::Mat frame_gray;
    cv::cvtColor(frame, frame_gray, cv::COLOR_BGR2GRAY);
    cv::equalizeHist(frame_gray, frame_gray);
    // Detect faces
    face_cascade.detectMultiScale(frame_gray, faces);
    if (faces.size() > 0)
    {
        return cv::Rect2i(faces[0].x, faces[0].y, faces[0].width, faces[0].height);
    }

    return cv::Rect2i(0, 0, 0, 0);
}

bool FaceDetector::CascadeFileFound()
{
    return found_cascade_file;
}
