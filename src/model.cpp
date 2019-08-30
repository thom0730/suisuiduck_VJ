//
//  model.cpp
//  suisuiduck
//
//  Created by 諸星智也 on 2019/08/31.
//

#include "model.hpp"
//--------------------------------------------------------------
void model::setup(){
    model_path = "CIT.obj";
    mAssimpModelLoader.setScale(10, 10, 10);
    mAssimpModelLoader.loadModel(model_path);
    
}
void model::update(){
    mAssimpModelLoader.update();
    cam.lookAt(ofVec3f(0,0,0));
    //camera.setPosition(500*cos(ofGetElapsedTimef()), 100, 500*sin(ofGetElapsedTimef()/10));

    
    
}
void model::draw(float _getFFT){
    cout << "cam position"<<cam.getPosition() << endl;
    ofBackground(0);
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    //camera.begin();
    cam.begin();
    ofRotateX(-90);
    ofSetLineWidth(1);
    mAssimpModelLoader.drawVertices(); //モデルの頂点を描画
    mAssimpModelLoader.drawFaces();  //モデルの面を描画
    //mAssimpModelLoader.drawWireframe();  //モデルを描画
    //camera.end();
    cam.end();
    ofPopMatrix();
}

