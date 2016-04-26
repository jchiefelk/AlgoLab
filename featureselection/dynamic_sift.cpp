#include <iostream>
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
 
    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera

        // SIFT
        //
        src = frame;
        cvtColor(src, src, CV_BGR2GRAY);
        SIFT sift(500,1,0.1);
        sift(src, src, keypoints, descriptors, false);
        drawKeypoints(src, keypoints, dest);
        imshow("Sift", dest);
        // Video
        // cvtColor(frame, edges, COLOR_BGR2GRAY);
        // GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
        // Canny(edges, edges, 0, 30, 3);
        // imshow("edges", edges);
        if(waitKey(30) >= 0) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
