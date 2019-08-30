#pragma once

#include "ofMain.h"

#include "ofxRollingCam.h"
#include "ofxPostGlitch.h"
#include "ofxOsc.h"

#include "Particle.hpp"
#include "duck.hpp"
#include "Box.hpp"
#include "WebCam.hpp"
#include "kinect.hpp"

#define HOST "127.0.0.1"
#define PORT 7401
#define Threshold 0.7

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void getOSC();
        void RollingDraw();
        void AllSetUp();
        void AllUpdate();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    int sceneFLG;
    
    //OSC
    ofxOscReceiver receiver;
    float getFFT;
    //RollingCam
    ofxRollingCam rollCam;
    
    //Glitch
    ofxPostGlitch postGlitch;
    ofFbo buffer;
    
    
    //独自クラス
    Particle particle;
    duck duck;
    Box boxclass;
    WebCam webcam;
    kinect kinect;
    
		
};
