//
//  WebCam.cpp
//  suisuiduck
//
//  Created by 諸星智也 on 2019/08/30.
//

#include "WebCam.hpp"
//--------------------------------------------------------------
void WebCam::setup(){
    videoGrabber.setup(1024/2, 768/2);
    xInterval = float(ofGetWidth()) / videoGrabber.getWidth();
    yInterval = float(ofGetHeight()) / videoGrabber.getHeight();
    
    ofEnableDepthTest();
    ofEnableSmoothing();
    mesh.setMode(OF_PRIMITIVE_TRIANGLES);
    mesh.enableColors();
    mesh.enableIndices();
    light.enable();
}
void WebCam::update(){

}

void WebCam::draw(){
    videoGrabber.update();
    
    if(videoGrabber.isFrameNew()){
        unsigned char * pixels = videoGrabber.getPixels().getData();
        
        mesh.clearVertices();
        mesh.clearColors();
        mesh.clearIndices();
        for(int h = 0; h < videoGrabber.getHeight(); h++){
            for(int w = 0; w < videoGrabber.getWidth(); w++){
                float r = (float)pixels[int(h * videoGrabber.getWidth() + w) * 3] / 256.0;
                float g = (float)pixels[int(h * videoGrabber.getWidth() + w) * 3 + 1] / 256.0;
                float b = (float)pixels[int(h * videoGrabber.getWidth() + w) * 3 + 2] / 256.0;
                ofFloatColor color = ofFloatColor(r, g, b);
                float z = ofMap(color.getBrightness(), 0, 1, 300, -300);
                mesh.addColor(color);
                mesh.addVertex(ofVec3f(w * xInterval, h * yInterval, z));
            }
        }
        for(int h = 0; h < videoGrabber.getHeight() - 1; h++){
            for(int w = 0; w < videoGrabber.getWidth() - 1; w++){
                mesh.addIndex(h * videoGrabber.getWidth() + w);
                mesh.addIndex(h * videoGrabber.getWidth() + w + 1);
                mesh.addIndex((h + 1) * videoGrabber.getWidth() + w + 1);
                mesh.addIndex(h * videoGrabber.getWidth() + w);
                mesh.addIndex((h + 1) * videoGrabber.getWidth() + w);
                mesh.addIndex((h + 1) * videoGrabber.getWidth() + w + 1);
            }
        }
    }
    
    mesh.draw();
    //    mesh.drawWireframe();}
}
void WebCam::draw(float _getFFT){
    videoGrabber.update();
    
    if(videoGrabber.isFrameNew()){
        unsigned char * pixels = videoGrabber.getPixels().getData();
        
        mesh.clearVertices();
        mesh.clearColors();
        mesh.clearIndices();
        for(int h = 0; h < videoGrabber.getHeight(); h++){
            for(int w = 0; w < videoGrabber.getWidth(); w++){
                float r = (float)pixels[int(h * videoGrabber.getWidth() + w) * 3] / 256.0;
                float g = (float)pixels[int(h * videoGrabber.getWidth() + w) * 3 + 1] / 256.0;
                float b = (float)pixels[int(h * videoGrabber.getWidth() + w) * 3 + 2] / 256.0;
                ofFloatColor color = ofFloatColor(r, g, b);
                float z = ofMap(color.getBrightness(), 0, 1, 300, -300);
                mesh.addColor(color);
                mesh.addVertex(ofVec3f(w * xInterval, h * yInterval, z)*_getFFT);
            }
        }
        for(int h = 0; h < videoGrabber.getHeight() - 1; h++){
            for(int w = 0; w < videoGrabber.getWidth() - 1; w++){
                mesh.addIndex(h * videoGrabber.getWidth() + w);
                mesh.addIndex(h * videoGrabber.getWidth() + w + 1);
                mesh.addIndex((h + 1) * videoGrabber.getWidth() + w + 1);
                mesh.addIndex(h * videoGrabber.getWidth() + w);
                mesh.addIndex((h + 1) * videoGrabber.getWidth() + w);
                mesh.addIndex((h + 1) * videoGrabber.getWidth() + w + 1);
            }
        }
    }
    
    //mesh.draw();
    mesh.drawWireframe();
}
