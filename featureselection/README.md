<h2> Feature Selection </h2>

<p>
So after some research on several interest point detection algorithms OpenCV offers, our conlcusion is that FAST is best for my needs.  I experimented with both Harris and SIFT.  Harris can be slow, and the number of interest points it detects relative to SIFT at the same speed is subpar.  SIFT is not ideal for my use because it costs money to use in commericial producrs, yeah fuck that shit
</p>

<p>
FAST is great because its FREE, and its very efficient.  The C++ code below will detect interst points from your Laptops camera.
</p>

<pre>

#include <iostream>
#include <fstream>
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
        src = frame;
        cvtColor(src, src, CV_BGR2GRAY);
        GaussianBlur(src, src, Size(7,7), 1.5, 1.5);
        FAST(src,keypoints,threshold,true);
        drawKeypoints(src, keypoints, dest);
        imshow("FAST", dest);
        //
        // Print Keypoints to File
        /**
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
        **/
        if(waitKey(30) >= 0) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
</pre>

