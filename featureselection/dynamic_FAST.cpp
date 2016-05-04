#include <iostream>
#include <fstream>
// #include "cv.h"
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
    // cout << "rows :" << frame.rows << "\n";
    Mat src, dest;
    cout << src.rows << "\n";
    vector<KeyPoint> keypoints;
    vector<cv::KeyPoint>::iterator it;
    vector<cv::Point2f> points;
    ofstream outfile1,outfile2,outfile3;
    int threshold=5;
    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera
        // cout << "rows :" << frame.rows << "\n";
        // SIFT
        //
        src = frame;
        cvtColor(src, src, CV_BGR2GRAY);
        GaussianBlur(src, src, Size(7,7), 1.5, 1.5);
        // Canny(src, src, 0, 30, 3);
        FAST(src,keypoints,threshold,true);
        drawKeypoints(src, keypoints, dest);
        for(it=keypoints.begin(); it!=keypoints.end();it++){
                    points.push_back(it->pt);
        }
        Mat pointmatrix(points);
        outfile1.open("points.txt");
        outfile1 << pointmatrix;
        outfile1.close();
        outfile3.open("src.txt");
        outfile3 << src;
        outfile3.close();
        imshow("FAST", dest);
        if(waitKey(30) >= 0) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
