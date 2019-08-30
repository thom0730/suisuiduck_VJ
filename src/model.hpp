//
//  model.hpp
//  suisuiduck
//
//  Created by 諸星智也 on 2019/08/31.
//

#ifndef model_hpp
#define model_hpp
#include "ofxAssimpModelLoader.h"

#include <stdio.h>
#include "ofMain.h"

class model{
public:
    void setup();
    void update();
    void draw(float _getFFT);
    void keyPressed(int key);
    void keyReleased(int key);
    
    
    ofCamera camera;
    ofEasyCam cam;      
    ofxAssimpModelLoader mAssimpModelLoader;
    string model_path;
    
};
#endif /* model_hpp */
