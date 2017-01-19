//
//  mainthread.cpp
//  ofAlgoLab
//
//  Created by Jackson on 1/18/17.
//
//

#include "mainthread.hpp"

void MainThread::collectData() {
    threadedObject1.start();
}


void MainThread::FastObjectDetection(){
    cout << threadedObject1.image;
}
