//
//  mainthread.hpp
//  ofAlgoLab
//
//  Created by Jackson on 1/18/17.
//
//

#ifndef mainthread_hpp
#define mainthread_hpp
#include <stdio.h>
#include "videothread.h"
#include "ipthread.h"

class MainThread {
        public:
        Mat image;
        void collectData();
        void FastObjectDetection();
        VideoThread threadedObject1;
        IPThread threadedObject2;
};

#endif /* mainthread_hpp */
