//
//  Particle.cpp
//  suisuiduck
//
//  Created by 諸星智也 on 2019/08/30.
//

#include "Particle.hpp"

void Particle::setup ()  {
    // 頂点情報の初期化
    for (int i=0; i<NUM_BILLBOARDS; i++) {
        
        // 移動速度
        billboardVels[i].set(ofRandomf(), -1.0, ofRandomf());
        
        // 初期位置
        billboardVerts[i].set(ofRandom(-500, 500), ofRandom(-500, 500), ofRandom(-500, 500));
        
        // 色
        billboardColor[i].set(1, 1, 1, 0.7);
    }
    
    // VBOにパーティクルの色と座標を格納
    billboardVbo.setVertexData(billboardVerts, NUM_BILLBOARDS, GL_DYNAMIC_DRAW);
    billboardVbo.setColorData(billboardColor, NUM_BILLBOARDS, GL_DYNAMIC_DRAW);
    
    // テクスチャー画像を設定
    ofDisableArbTex();
    texture.loadImage("particle32.png");
}

//円の位置を更新するメソッド
void Particle::update(float _getFFT) {
    
    // パーティクルの座標を更新
    float t   = (ofGetElapsedTimef()) * 0.9f;
    float div = 250.0;
    
    for (int i=0; i<NUM_BILLBOARDS; i++) {
        
        // ノイズを生成し移動速度に
        ofVec3f vec(ofSignedNoise(t, billboardVerts[i].y/div, billboardVerts[i].z/div),
                    ofSignedNoise(billboardVerts[i].x/div, t, billboardVerts[i].z/div),
                    ofSignedNoise(billboardVerts[i].x/div, billboardVerts[i].y/div, t));
        
        vec *= 0.3f;
        
        // 速度をもとにパーティクル位置を更新
        billboardVels[i] += vec;
        billboardVerts[i] += billboardVels[i];
        billboardVels[i]  *= 0.94f;
        //billboardVels[i] *= _getFFT;
    }
    
    // VBOの頂点と色の情報を更新
    billboardVbo.setVertexData(billboardVerts, NUM_BILLBOARDS, GL_DYNAMIC_DRAW);
    billboardVbo.setColorData(billboardColor, NUM_BILLBOARDS, GL_DYNAMIC_DRAW);
}

void Particle::draw(){
    ofPushStyle();
    ofBackground(0);
    ofEnableLighting();
    ofEnableDepthTest();
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);
    //cam.begin();
    {
        // パーティクル描画設定
        glDepthMask(GL_FALSE);
        ofEnablePointSprites();
        texture.getTextureReference().bind();
        
        // パーティクルのZ軸の位置によって大きさを変化させる
        static GLfloat distance[] = { 0.0, 0.0, 1.0 };
        glPointParameterfv(GL_POINT_DISTANCE_ATTENUATION, distance);
        glPointSize(30000);
        
        // パーティクルを描画
        ofEnableBlendMode(OF_BLENDMODE_ADD);
        billboardVbo.draw(GL_POINTS, 0, NUM_BILLBOARDS);
        texture.getTextureReference().unbind();
        ofDisablePointSprites();
        glDepthMask(GL_TRUE);
    }
    ofPopMatrix();
    ofDisableDepthTest();
    ofDisableLighting();
    ofPopStyle();

}
