#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    videoTexture.allocate(320,240, GL_RGB);
    thread.startThread(true, false);
}

void ofApp::update(){
    thread.lock();
    videoTexture.loadData(thread.pixels);
    source = thread.image;
    thread.unlock();
    vector<KeyPoint> keypoints;
    vector<cv::KeyPoint>::iterator it;
    vector<cv::Point2f> points;
    int threshold=3;

    if(source.empty()==0) {
        cout << source.empty();
        cout << "\n";
        // cv::cvtColor(source, source, CV_BGR2GRAY);
        GaussianBlur(source, source, cv::Size(7,7), 1.5, 1.5);
        FAST(source,keypoints,threshold,true);
    }
}
void ofApp::draw() {
    videoTexture.draw(0, 0);
}
void ofApp::exit() {
    thread.stopThread();
}
