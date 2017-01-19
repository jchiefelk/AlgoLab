//
//  threadWorker.h
//  ofAlgoLab
//
//  Created by Jackson on 1/18/17.
//
//

#ifndef threadWorker_h
#define threadWorker_h
#include "ofMain.h"
#include <stdio.h>
#include "ipthread.h"
#include "videothread.h"


class ThreadWorker {
    public:
    int x;
    VideoThread thread1;
    IPThread thread2;
    void firstThread(){
        thread1.start();
    }
    
    void secondThread() {
        thread2.start();
    }
    
};

#endif /* threadWorker_h */
