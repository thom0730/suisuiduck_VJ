//
//  PointCloud.cpp
//  suisuiduck
//
//  Created by 諸星智也 on 2019/08/31.
//

#include "PointCloud.hpp"
//--------------------------------------------------------------
void PointCloud::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
 
    kinect.setRegistration(true); // カメラ画像と深度カメラのずれを解消
    kinect.init(); // Kinect初期化
    kinect.open(); // Kinect開始
    
    gui.setup();
    gui.add(pointSize.setup("Point Size", 3.0, 0.0, 10.0));
    gui.add(positionZ.setup("Z Position", -1000.0, -2000.0, 0.0));
    gui.add(scaleZ.setup("Z Scale", 1.0, 0.0, 4.0));
    gui.add(step.setup("Pixel Step", 2, 1, 8));
    
}
void PointCloud::update(){
    // Kinect状態更新
    kinect.update();
}
void PointCloud::draw(float _getFFT){
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
    
    gui.draw();
}
