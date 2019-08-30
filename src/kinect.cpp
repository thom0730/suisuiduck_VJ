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

    kinect.setRegistration(true); // カメラ画像と深度カメラのずれを解消
    
    kinect.init();
    kinect.open();
    // GUI初期設定
    gui.setup();
    //for CV
    gui.add(thresh.setup("Threshhold", 127, 0, 255));
    gui.add(minRadius.setup("Min Radius", 10, 0, 400));
    gui.add(maxRadius.setup("Max Radius", 200, 0, 400));
    
    //for Pointcloud
    gui.add(pointSize.setup("Point Size", 3.0, 0.0, 10.0));
    gui.add(positionZ.setup("Z Position", -1000.0, -2000.0, 0.0));
    gui.add(scaleZ.setup("Z Scale", 1.0, 0.0, 4.0));
    gui.add(step.setup("Pixel Step", 2, 1, 8));
    
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
void kinect::draw(int _key , float _getFFT){
    //CV
    if(_key == 5){
        // 深度画像描画
        ofSetColor(255);
        kinect.drawDepth(0, 0, ofGetWidth(), ofGetHeight());
        // 輪郭抽出結果描画
        ofSetColor(255, 255, 0);
        ofPushMatrix();
        ofScale(ofGetWidth() / float(kinect.width), ofGetHeight() / float(kinect.height));
        contourFinder.draw();
        ofPopMatrix();
        
    }else if(_key == 6) {
        int w = 640;
        int h = 480;
        ofMesh mesh; // Meshを準備
        mesh.setMode(OF_PRIMITIVE_POINTS); // Meshの頂点を点で描画
        
        // 指定した間隔で全てのピクセルの位置と色を取得
        for(int y = 0; y < h; y += step) {
            for(int x = 0; x < w; x += step) {
                if(kinect.getDistanceAt(x, y) > 0) {
                    mesh.addColor(kinect.getColorAt(x,y));
                    mesh.addVertex(kinect.getWorldCoordinateAt(x, y));
                }
            }
        }
        glPointSize(pointSize); // 描画する点の大きさ
        
        cam.begin();  // カメラ開始
        ofPushMatrix();
        ofScale(1, -1, -1 * scaleZ); // 上下と前後を反転
        ofTranslate(0, 0, positionZ); // 全体位置を後ろへ
        ofEnableDepthTest(); // 奥の物体を隠すように
        mesh.draw(); // メッシュ描画
        ofDisableDepthTest();
        ofPopMatrix();
        cam.end();
        
    }
    gui.draw();

    
}
