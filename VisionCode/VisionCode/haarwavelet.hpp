//
//  haarwavelet.hpp
//  VisionCode
//
//  Created by Jackson on 1/22/17.
//  Copyright © 2017 Jackson. All rights reserved.
//

#ifndef haarwavelet_hpp
#define haarwavelet_hpp
#include <stdio.h>
#include <iostream>
#include <math.h> 

#define CAMERA_WIDTH   1280
#define CAMERA_HEIGHT 720

class HaarWavelet {
    
    
        public:
        double NormalizationFactor = 1/sqrt(8);
        double HaarMatrix[8][8] = {
                {1,1,1,1,1,1,1,1},
                {1,1,1,1,-1,-1,-1,-1},
                {sqrt(2),sqrt(2),-sqrt(2),-sqrt(2),0,0,0,0},
                {0,0,0,0,sqrt(2),sqrt(2),-sqrt(2),-sqrt(2)},
                {2,-2,0,0,0,0,0,0},
                {0,0,2,-2,0,0,0,0},
                {0,0,0,0,2,-2,0,0},
                {0,0,0,0,0,0,2,-2}
        };
        double HaarMatixTranspose[8][8] = {
                {1,1,sqrt(2),0,2,0,0,0},
                {1,1,sqrt(2),0,-2,0,0,0},
                {1,1,-sqrt(2),0,0,2,0,0},
                {1,1,-sqrt(2),0,0,-2,0,0},
                {1,-1,0,sqrt(2),0,0,2,0},
                {1,-1,0,sqrt(2),0,0,-2,0},
                {1,-1,0,-sqrt(2),0,0,0,2},
                {1,-1,0,-sqrt(2),0,0,0,-2}
        };
        void populate();
        // Populate Haar Matrix
 
    
    
    
    

};

#endif /* haarwavelet_hpp */
