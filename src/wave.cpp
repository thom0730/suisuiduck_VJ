//
//  wave.cpp
//  suisuiduck
//
//  Created by 諸星智也 on 2019/08/31.
//

#include "wave.hpp"
//--------------------------------------------------------------
void wave::setup(){
    ofSetFrameRate(60);
    ofSetWindowTitle("openframeworks");
    
    ofBackground(239);
    ofSetLineWidth(2);
    ofEnableDepthTest();
    
}
void wave::update(){
    
    
}
void wave::draw(float _getFFT){
    this->cam.begin();
    
    int size = 30;
    for (int x = -ofGetWidth(); x <= ofGetWidth(); x += size) {
        
        for (int y = -ofGetHeight(); y <= ofGetHeight(); y += size) {
            ofVec3f v = ofVec2f(x, y);
            
            float z = ofMap(ofNoise(v.length() * 0.003 - ofGetFrameNum() * 0.01), 0, 1, -300, 300);
            
            
            float f = ofMap( _getFFT, 0, 1, 0, 255 );
            
            ofSetColor(_getFFT);
            ofFill();
            ofDrawBox(ofVec3f(x, y, z), size - 2);
            
            ofSetColor(39);
            ofNoFill();
            ofDrawBox(ofVec3f(x, y, z), size);
        }
    }
    
    this->cam.end();
}

