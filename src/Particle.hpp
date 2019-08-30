#include <stdio.h>
#include "ofMain.h"

#define NUM_BILLBOARDS 40000

class Particle {
    
public:
    
    void setup();  //初期化メソッド
    void update(float _getFFT);  //更新
    void draw(); //描画
    
    ofImage texture;
    ofVbo billboardVbo;
    ofVec3f billboardVerts[NUM_BILLBOARDS];
    ofFloatColor billboardColor[NUM_BILLBOARDS];
    ofVec3f billboardVels[NUM_BILLBOARDS];
    
private:
    
};

