#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;

int main(){

    VideoCapture cap(0);

    while(true){
        Mat Webcam;
        cap.read(Webcam);
        imshow("Webcam", Webcam);
    }

}
  