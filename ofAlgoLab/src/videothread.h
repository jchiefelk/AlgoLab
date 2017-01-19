//
//  videothread.h
//  ofAlgoLab
//
//  Created by Jackson on 5/4/16.
//
//

#pragma once
#include "ofThread.h"
#include "ofApp.h"
#include "ofMain.h"
#include "ofImage.h"
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace std;
using namespace cv;


class VideoThread: public ofThread
{

public:
    
    ofVideoGrabber cam;
    ofPixels pixels;
    Mat image;
    
    VideoThread() {
        cam.initGrabber(1280,720,false);
        cam.setDesiredFrameRate(30);
    }
    
    void threadedFunction() {
        while(isThreadRunning()) {
            cam.update();
            if(cam.isFrameNew()) {
                lock();
                pixels = cam.getPixels();
                ofPixels & data = cam.getPixels();
                auto img = cv::Mat(720, 1280, CV_8UC1, pixels.getData());
                image = img;
                unlock();
            }	  
        }  
    }
    
};
