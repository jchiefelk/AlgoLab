//
//  main.cpp
//  VisionCode
//
//  Created by Jackson on 5/4/16.
//  Copyright © 2016 Jackson. All rights reserved.
//
#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <fstream>
using namespace std;
using namespace cv;


int main() {
         // Open the first camera attached to your computer
         cv::VideoCapture cap(0);
         if(!cap.isOpened()) {
                 std::cout << "Unable to open the camera\n";
                 std::exit(-1);
             }
    
        Mat image;
        double FPS = 24.0;
        Mat src, dest;
        cout << src.rows << "\n";
        vector<KeyPoint> keypoints;
        vector<cv::KeyPoint>::iterator it;
        vector<cv::Point2f> points;
        ofstream outfile1,outfile2,outfile3;
        int threshold=3;
         // Read camera frames (at approx 24 FPS) and show the result
         while(true) {
                cap >> image;
                if(image.empty()) {
                        std::cout << "Can't read frames from your camera\n";
                         break;
                }
                src = image;
                cvtColor(src, src, CV_BGR2GRAY);
             GaussianBlur(src, src, cv::Size(7,7), 1.5, 1.5);
                FAST(src,keypoints,threshold,true);
                drawKeypoints(src, keypoints, dest);
                imshow("Camera feed", dest);
                 // Stop the camera if users presses the "ESC" key
                 if(waitKey(1000.0/FPS) == 27) break;
             }
     
         return 0;
}
