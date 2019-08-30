#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    rollCam.setup();//rollCam's setup.
    rollCam.setCamSpeed(0.1);//rollCam's speed set;
    
    receiver.setup(PORT);
    buffer.allocate(ofGetWidth(), ofGetHeight());
    postGlitch.setup(&buffer);
    
    //各関数
    AllSetUp();

}

//--------------------------------------------------------------
void ofApp::update(){
    rollCam.update();
    getOSC();
    RollingDraw();
    
    AllUpdate();

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    //Glitch かける系
    if(sceneFLG==1){}
    
    buffer.begin();
    ofClear(0);
    if(sceneFLG==1){
        rollCam.begin();
        particle.draw();
        rollCam.end();
    }
    if(sceneFLG==2){
        rollCam.begin();
        boxclass.draw(getFFT);
        rollCam.end();
    }
    if(sceneFLG==3){
        webcam.draw();
    }
    if(sceneFLG==4){
        rollCam.begin();
        webcam.draw(getFFT*20);
        rollCam.end();
    }
    if(sceneFLG==9)duck.draw(getFFT);
    buffer.end();
    postGlitch.generateFx();
    buffer.draw(0,0);
    
    

}
//--------------------------------------------------------------
void ofApp::getOSC(){
    // OSCの個数分繰り返す
    int index = 0;
    while(receiver.hasWaitingMessages()) {
        
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        string value = m.getArgAsString(index);
        // msg += "getAddress: " + m.getAddress() + "\n";
        // msg += "getArgAsString " + ofToString(index) + ": " + value + "\n";
        
        if( index == 0 ){
            getFFT = ofMap( ofToFloat( m.getArgAsString(index) ), -90, 0, 0, 1 );
        }
        index++;
    }
    cout << getFFT << endl;

}
void ofApp::RollingDraw(){
    if(getFFT > Threshold){
        int num = ofRandom(5);
        if(num < 1){
            rollCam.setRandomScale(0.5, 1.5);
            rollCam.setRandomPos(270);
        }else if(num > 1 && num < 2){
            rollCam.setRandomPos(270);
        }else if(num > 2 && num < 3){
            rollCam.setPos(0, 0, 0);
        }else if(num > 3 && num < 4){
            rollCam.setRandomScale(0.5, 1.5);
        }else if(num > 4 && num < 5){
            rollCam.setScale(1);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key=='1')sceneFLG=1;
    if (key=='2')sceneFLG=2;
    if (key=='3')sceneFLG=3;
    if (key=='4')sceneFLG=4;
    if (key=='5')sceneFLG=5;
    if (key=='6')sceneFLG=6;
    if (key=='7')sceneFLG=7;
    if (key=='8')sceneFLG=8;
    if (key=='9')sceneFLG=9;
    
    
    if (key=='z') {//All Random.
        rollCam.setRandomScale(0.5, 1.5);
        rollCam.setRandomPos(270);
    }
    if (key=='x') {//Random rotate.
        rollCam.setRandomPos(270);
    }
    if (key=='c') {//Inputting optional rotate.
        rollCam.setPos(0, 0, 0);
    }
    if (key=='v') {//Random distance.
        rollCam.setRandomScale(0.5, 1.5);
    }
    if (key=='b') {//Inputting optional distance.
        rollCam.setScale(1);
    }
    if (key==' ') {
        ofToggleFullscreen();
        buffer.allocate(ofGetWidth(), ofGetHeight());
        postGlitch.setup(&buffer);
        
        //各関数
        AllSetUp();
    }
    
    
    if (key == 'q') postGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE    , true);
    if (key == 'w') postGlitch.setFx(OFXPOSTGLITCH_GLOW            , true);
    if (key == 'e') postGlitch.setFx(OFXPOSTGLITCH_SHAKER            , true);
    if (key == 'r') postGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER        , true);
    if (key == 't') postGlitch.setFx(OFXPOSTGLITCH_TWIST            , true);
    if (key == 'y') postGlitch.setFx(OFXPOSTGLITCH_OUTLINE        , true);
    if (key == 'u') postGlitch.setFx(OFXPOSTGLITCH_NOISE            , true);
    if (key == 'i') postGlitch.setFx(OFXPOSTGLITCH_SLITSCAN        , true);
    if (key == 'o') postGlitch.setFx(OFXPOSTGLITCH_SWELL            , true);
    if (key == 'p') postGlitch.setFx(OFXPOSTGLITCH_INVERT            , true);
    
    if (key == 'a') postGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, true);
    if (key == 's') postGlitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE    , true);
    if (key == 'e') postGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE    , true);
    if (key == 'f') postGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE    , true);
    if (key == 'g') postGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT    , true);
    if (key == 'y') postGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT    , true);
    if (key == 'j') postGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT    , true);
    


}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == 'q') postGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE    , false);
    if (key == 'w') postGlitch.setFx(OFXPOSTGLITCH_GLOW            , false);
    if (key == 'e') postGlitch.setFx(OFXPOSTGLITCH_SHAKER            , false);
    if (key == 'r') postGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER        , false);
    if (key == 't') postGlitch.setFx(OFXPOSTGLITCH_TWIST            , false);
    if (key == 'y') postGlitch.setFx(OFXPOSTGLITCH_OUTLINE        , false);
    if (key == 'u') postGlitch.setFx(OFXPOSTGLITCH_NOISE            , false);
    if (key == 'i') postGlitch.setFx(OFXPOSTGLITCH_SLITSCAN        , false);
    if (key == 'o') postGlitch.setFx(OFXPOSTGLITCH_SWELL            , false);
    if (key == 'p') postGlitch.setFx(OFXPOSTGLITCH_INVERT            , false);
    
    if (key == 'a') postGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, false);
    if (key == 's') postGlitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE    , false);
    if (key == 'e') postGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE    , false);
    if (key == 'f') postGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE    , false);
    if (key == 'g') postGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT    , false);
    if (key == 'y') postGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT    , false);
    if (key == 'j') postGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT    , false);

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
//--------------------------------------------------------------
void ofApp::AllSetUp(){
    particle.setup();
    duck.setup();
    boxclass.setup();
    webcam.setup();
}
void ofApp::AllUpdate(){
    particle.update(getFFT*100);
    duck.update();
    boxclass.update();
   // webcam.update();
}
