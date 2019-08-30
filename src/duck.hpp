//
//  duck.hpp
//  suisuiduck
//
//  Created by 諸星智也 on 2019/08/30.
//

#ifndef duck_hpp
#define duck_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#define NUM 800

class duck {
    
    public:
    void setup();  //初期化メソッド
    void update();  //更新
    void draw(float _getFFT); //描画
    
    ofxAssimpModelLoader model;
    ofLight light;
    
    ofVboMesh vbomesh;
    ofVec3f vec[NUM];
    
};
#endif
