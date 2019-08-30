//
//  PointCloud.hpp
//  suisuiduck
//
//  Created by 諸星智也 on 2019/08/31.
//

#ifndef PointCloud_hpp
#define PointCloud_hpp

#include <stdio.h>
#include "ofxCv.h"
#include "ofxKinect.h"
#include "ofxGui.h"

class PointCloud{
public:
    void setup();
    void update();
    void draw(float _getFFT);
    ofxKinect kinect;       // Kinectインスタンス
    ofImage kinectImage;    // Kinectカメラ映像
    ofImage depthImage;     // Kinect深度映像
    ofEasyCam cam;          // カメラ
    
    ofxPanel gui;
    ofxFloatSlider positionZ;
    ofxFloatSlider scaleZ;
    ofxFloatSlider pointSize;
    ofxIntSlider step;
};


#endif /* PointCloud_hpp */
