//
//  Box.hpp
//  suisuiduck
//
//  Created by 諸星智也 on 2019/08/30.
//

#ifndef Box_hpp
#define Box_hpp

#include <stdio.h>
#include "ofMain.h"

class Box{
    public:
    void setup();
    void update();
    void draw(float _getFFT);
    void keyPressed(int key);
    void keyReleased(int key);

    
    ofBoxPrimitive box;  //立方体
    ofMesh mesh;
    ofLight light;
    
};
#endif /* Box_hpp */
