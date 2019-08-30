//
//  Box.cpp
//  suisuiduck
//
//  Created by 諸星智也 on 2019/08/30.
//

#include "Box.hpp"
//--------------------------------------------------------------
void Box::setup(){

    this->box.set(90);  //立方体の大きさ(100,100,100)
    this->box.setResolution(10);  //数値が大きいほど立方体を構成するメッシュの量が増える
    mesh = this->box.getMesh();  //boxの頂点情報群を取得しmeshに格納
    for(int i = 0; i < mesh.getVertices().size(); i++){  //各々の頂点に対して
        mesh.addColor(ofFloatColor(1.0, 1.0, 1.0, 1.0));  //色情報初期化
        ofVec3f loc = mesh.getVertices()[i] * ofRandom(0.5,1.0);  //位置情報を0.5~1.0で掛ける
        mesh.setVertex(i, loc);  //新しい位置情報としてセット
//        ofColor c;
//        c.setHsb(ofRandom(255),255,255);  //HSBで色定義
//        mesh.setColor(i,c);  //新しい色情報としてセット
    }
    ofDisableArbTex();
    //this makes sure that the back of the model doesn't show through the front
    ofEnableDepthTest();
    light.enable();
    
}
void Box::update(){
    
    
}
void Box::draw(float _getFFT){
     mesh = this->box.getMesh();  //boxの頂点情報群を取得しmeshに格納
    for(int i = 0; i < mesh.getVertices().size(); i++){  //各々の頂点に対して
        mesh.addColor(ofFloatColor(1.0, 1.0, 1.0, 1.0));  //色情報初期化
        ofVec3f loc = mesh.getVertices()[i] *_getFFT*10* ofRandom(0.5,1.0);  //位置情報を0.5~1.0で掛ける
        mesh.setVertex(i, loc);  //新しい位置情報としてセット
    }
    mesh.drawWireframe();  //メッシュのフレームを描画
   // mesh.draw();  //メッシュのフレームを描画
//    ofPushStyle();
//    ofSetColor(31, 127, 255);
//    ofEnableLighting();
//    ofEnableDepthTest();
//    box.setPosition(ofGetWidth()/2, ofGetHeight()/2, 0);
//    box.rotate(0.9, 0.5, 1.0, 0.2);
//    //box.setScale(_getFFT);
//    box.draw();
//    ofDisableDepthTest();
//    ofDisableLighting();
//    ofPopStyle();

}
