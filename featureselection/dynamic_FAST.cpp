#include <iostream>
#include <fstream>
#include "cv.h"
#include <opencv2/opencv.hpp>
#include "opencv2/nonfree/nonfree.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;
  

int main(int, char**)
{
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened()){  
        return -1; // check if we succeeded
    }
    Mat edges;
    // namedWindow("edges",1);
    // Sift Code
    Mat src, descriptors,dest;
    vector<KeyPoint> keypoints;
    vector<cv::KeyPoint>::iterator it;
    vector<cv::Point2f> points;
    ofstream outfile1,outfile2,outfile3;
    int threshold=15;
    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera

        // SIFT
        //
        src = frame;
        cvtColor(src, src, CV_BGR2GRAY);
        // SIFT sift(500,1,0.1);
        // sift(src, src, keypoints, descriptors, false);
        FAST(src,keypoints,threshold,true);
        drawKeypoints(src, keypoints, dest);
        imshow("Sift", dest);
 
        if(waitKey(30) >= 0) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
