//
//  kinect.cpp
//  suisuiduck
//
//  Created by 諸星智也 on 2019/08/31.
//

#include "kinect.hpp"
//--------------------------------------------------------------
void kinect::setup(){
    //画面設定
    ofSetFrameRate(60);
    ofBackground(0);
    // Kinect初期化
    kinect.init();
    kinect.open();
    // GUI初期設定
    gui.setup();
    gui.add(thresh.setup("Threshhold", 127, 0, 255));
    gui.add(minRadius.setup("Min Radius", 10, 0, 400));
    gui.add(maxRadius.setup("Max Radius", 200, 0, 400));
    
}
void kinect::update(){
    // CV設定
    contourFinder.setMinAreaRadius(minRadius);
    contourFinder.setMaxAreaRadius(maxRadius);
    // Kinect状態更新
    kinect.update();
    if (kinect.isFrameNew()) {
        // ofxCvで輪郭抽出
        cv::Mat mat = cv::Mat(kinect.height, kinect.width, CV_8UC1, &kinect.getDepthPixels(), 0);
        contourFinder.setThreshold(thresh);
        contourFinder.findContours(mat);
    }
    
}
void kinect::draw(float _getFFT){
    // 深度画像描画
    ofSetColor(255);
    kinect.drawDepth(0, 0, ofGetWidth(), ofGetHeight());
    // 輪郭抽出結果描画
    ofSetColor(255, 255, 0);
    ofPushMatrix();
    ofScale(ofGetWidth() / float(kinect.width), ofGetHeight() / float(kinect.height));
    contourFinder.draw();
    ofPopMatrix();
    gui.draw();

    
}
