//
//  vision.hpp
//  ofAlgoLab
//
//  Created by Jackson on 5/4/16.
//
//

#ifndef vision_hpp
#define vision_hpp

#include <stdio.h>

#include "opencv2/opencv.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace std;
using namespace cv;

class VideoFeed
{
public:
    Mat src,dest;
    // Functions
    void start();
    void ipcapture();
};

#endif /* vision_hpp */
