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
    CvCapture* capture;
    Mat frame;
    //-- 2. Read the video stream
	   capture = cvCaptureFromCAM( -1 );
	   if( capture )
       {
           while( true )
           {
               frame = cvQueryFrame( capture );
               
               //-- 3. Apply the classifier to the frame
               if( !frame.empty() )
               { imshow("OpenCV Video Feed", frame ) ; }
               else
               { printf(" --(!) No captured frame -- Break!"); break; }
               
               int c = waitKey(10);
               if( (char)c == 'c' ) { break; }
           }
       }
	   return 0;
}

void VideoFeed::ipcapture() {
    vector<KeyPoint> keypoints;
    vector<cv::KeyPoint>::iterator it;
    vector<cv::Point2f> points;
    int threshold=15;
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
