//
//  duck.cpp
//  suisuiduck
//
//  Created by 諸星智也 on 2019/08/30.
//

#include "duck.hpp"
//--------------------------------------------------------------
void duck::setup(){
    
    model.loadModel("CIT.obj");
    model.setPosition(ofGetWidth()/2, ofGetHeight()/2, 0);
    //we need to call this for textures to work on models
    ofDisableArbTex();
    //this makes sure that the back of the model doesn't show through the front
    ofEnableDepthTest();
    light.enable();
    light.setPosition(model.getPosition() + ofPoint(0, 0, 1600));
    
}

//--------------------------------------------------------------
void duck::update(){
    
}

//--------------------------------------------------------------
void duck::draw(float _getFFT){
    int _i = 3;
    vbomesh.clear();
    
    //get the model attributes we need
    ofVec3f scale = model.getScale();
    ofVec3f position = model.getPosition();
    float normalizedScale = model.getNormalizedScale();
    ofVboMesh mesh = model.getMesh(0);
    ofTexture texture;
    ofxAssimpMeshHelper& meshHelper = model.getMeshHelper( 0 );
    bool bHasTexture = meshHelper.hasTexture();
    if( bHasTexture ) {
        texture = model.getTextureForMesh(0);
    }
    
    ofMaterial material = model.getMaterialForMesh(0);
    
    ofPushMatrix();
    
    //translate and scale based on the positioning.
    ofTranslate(position);
    ofRotate( ofGetElapsedTimeMillis()/20, 0, 1, 0);
    ofRotate(180,0,0,0);
    
    
    
    ofScale(normalizedScale, normalizedScale, normalizedScale);
    ofScale(scale.x,scale.y,scale.z);
    
    //modify mesh with some noise
    float liquidness = 5;
    //float amplitude = mouseY/100.0;
    float amplitude = 0;
    
    if(_i<15){
        if(_getFFT<1.3){
            amplitude = _getFFT/10;
        }else{
            amplitude = _getFFT*_i;
        }
    }else{
        amplitude = _getFFT*_i;
    }
    
    float speedDampen = 5;
    vector<ofVec3f>& verts = mesh.getVertices();
    for(unsigned int i = 0; i < verts.size(); i++){
        verts[i].x += ofSignedNoise(verts[i].x/liquidness, verts[i].y/liquidness,verts[i].z/liquidness, ofGetElapsedTimef()/speedDampen)*amplitude;
        verts[i].y += ofSignedNoise(verts[i].z/liquidness, verts[i].x/liquidness,verts[i].y/liquidness, ofGetElapsedTimef()/speedDampen)*amplitude;
        verts[i].z += ofSignedNoise(verts[i].y/liquidness, verts[i].z/liquidness,verts[i].x/liquidness, ofGetElapsedTimef()/speedDampen)*amplitude;
    }
    
    //draw the model manually
    if(bHasTexture) texture.bind();
    material.begin();
    //mesh.drawWireframe(); //you can draw wireframe too
    mesh.drawFaces();
    material.end();
    if(bHasTexture) texture.unbind();
    
    ofPopMatrix();
    //gui.draw();
}
