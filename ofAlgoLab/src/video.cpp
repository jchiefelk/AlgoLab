//
//  vision.cpp
//  ofAlgoLab
//
//  Created by Jackson on 5/4/16.
//
//
#include "video.hpp"
#include <stdio.h>

void VideoFeed::start(){
    // Open the first camera attached to your computer
    cv::VideoCapture cap(0);
    if(!cap.isOpened()) {
        std::cout << "Unable to open the camera\n";
        std::exit(-1);
    }
    // cout << "TEST TEST TEST TEST";
    cv::Mat image;
    double FPS = 24.0;
    // Read camera frames (at approx 24 FPS) and show the result
    while(true) {
        cap >> image;
        if(image.empty()) {
            std::cout << "Can't read frames from your camera\n";
            break;
        }
        VideoFeed::src = image;
       // cout << VideoFeed::src;
        //cv::imshow("Camera feed", image);
        // Stop the camera if users presses the "ESC" key
        if(cv::waitKey(1000.0/FPS) == 27) break;
    }
    return 0;
}

void VideoFeed::ipcapture(Mat image) {
    vector<KeyPoint> keypoints;
    vector<cv::KeyPoint>::iterator it;
    vector<cv::Point2f> points;
    
}
