//
//  videothread.h
//  ofAlgoLab
//
//  Created by Jackson on 5/4/16.
//
//

#pragma once
#include "ofThread.h"
#include "video.hpp"

class VideoThread: public ofThread
{
    public:
    VideoFeed Video;
    
    /// Start the thread.
    void start()
    {
        // Mutex blocking is set to true by default
        // It is rare that one would want to use startThread(false).
        startThread();
        Video.start();
    }
    
    /// Signal the thread to stop.  After calling this method,
    /// isThreadRunning() will return false and the while loop will stop
    /// next time it has the chance to.
    void stop()
    {
        stopThread();
    }
    
    /// Our implementation of threadedFunction.
    void threadedFunction()
    {
        while(isThreadRunning())
        {
            // Attempt to lock the mutex.  If blocking is turned on,
            if(lock())
            {
                // The mutex is now locked and the "count"
                // variable is protected.  Time to modify it.
                

                
                // Unlock the mutex.  This is only
                // called if lock() returned true above.
                unlock();
                
                // Sleep for 1 second.
                sleep(1000);
            }
            else
            {
                // If we reach this else statement, it means that we could not
                // lock our mutex, and so we do not need to call unlock().
                // Calling unlock without locking will lead to problems.
                ofLogWarning("threadedFunction()") << "Unable to lock mutex.";
            }
        }
    }
    
    
};
