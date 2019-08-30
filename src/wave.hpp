//
//  wave.hpp
//  suisuiduck
//
//  Created by 諸星智也 on 2019/08/31.
//

#ifndef wave_hpp
#define wave_hpp

#include <stdio.h>
#include "ofMain.h"

class wave{
public:
    void setup();
    void update();
    void draw(float _getFFT);
    void keyPressed(int key);
    void keyReleased(int key);
    
    
    ofEasyCam cam;
    
};


#endif /* wave_hpp */
