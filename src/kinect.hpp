//
//  kinect.hpp
//  suisuiduck
//
//  Created by 諸星智也 on 2019/08/31.
//

#ifndef kinect_hpp
#define kinect_hpp

#include <stdio.h>
#include "ofMain.h"

#include "ofxCv.h"
#include "ofxKinect.h"
#include "ofxGui.h"

class kinect{
public:
    void setup();
    void update();
    void draw(int _key , float _getFFT);
    void keyPressed(int key);
    void keyReleased(int key);
    
    ofxKinect kinect; //Kinectインスタンス
    ofImage kinectImage; // Kinectカメラ映像
    ofImage depthImage; // Kinect深度映像
    ofxCv::ContourFinder contourFinder; //CV輪郭抽出
    ofEasyCam cam;          // カメラ (デバッグ)
    
    // GUI FOR CV
    ofxPanel gui;
    ofxFloatSlider thresh;
    ofxFloatSlider minRadius;
    ofxFloatSlider maxRadius;
    
    // GUI FOR pointcloud
    ofxFloatSlider positionZ;
    ofxFloatSlider scaleZ;
    ofxFloatSlider pointSize;
    ofxIntSlider step;
};

#endif /* kinect_hpp */
