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
    
    cv::Mat image;
    double FPS = 24.0;
    // Read camera frames (at approx 24 FPS) and show the result
    while(true) {
        cap >> image;
        if(image.empty()) {
            std::cout << "Can't read frames from your camera\n";
            break;
        }
        
        cv::imshow("Camera feed", image);
        
        // Stop the camera if users presses the "ESC" key
        if(cv::waitKey(1000.0/FPS) == 27) break;
    }
    return 0;
}

void VideoFeed::ipcapture() {
    vector<KeyPoint> keypoints;
    vector<cv::KeyPoint>::iterator it;
    vector<cv::Point2f> points;
    int threshold=15;
    cout << threshold;
    for(;;)
    {
        
        cvtColor(src, src, CV_BGR2GRAY);
        GaussianBlur(src, src, Size(7,7), 1.5, 1.5);
        Canny(src, src, 0, 30, 3);
        FAST(src,keypoints,threshold,true);
        drawKeypoints(src, keypoints, dest);
        for(it=keypoints.begin(); it!=keypoints.end();it++){
            points.push_back(it->pt);
        }
        Mat pointmatrix(points);
        imshow("FAST", src);
        if(waitKey(30) >= 0) break;
    }
    
}
