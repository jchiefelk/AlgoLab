#pragma once

#include "ofMain.h"
#include "videothread.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <fstream>
using namespace std;



class ofApp : public ofBaseApp{

	public:
		void setup();
        void update();
        void draw();
        void exit();
        // Threaded Objects
        VideoThread thread;
        ofTexture videoTexture;
        Mat source;
};
