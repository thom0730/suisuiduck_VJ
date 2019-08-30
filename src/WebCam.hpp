//
//  WebCam.hpp
//  suisuiduck
//
//  Created by 諸星智也 on 2019/08/30.
//

#ifndef WebCam_hpp
#define WebCam_hpp

#include <stdio.h>
#include "ofMain.h"

class WebCam{
public:
    void setup();
    void update();
    void draw();
    void draw(float _getFFT);
    void keyPressed(int key);
    void keyReleased(int key);

    ofVideoGrabber videoGrabber;
    ofMesh mesh;
    float xInterval, yInterval;
    ofLight light;
    
};

#endif /* WebCam_hpp */
