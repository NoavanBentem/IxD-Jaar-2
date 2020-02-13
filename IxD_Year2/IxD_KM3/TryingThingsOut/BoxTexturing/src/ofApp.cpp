#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // this uses depth information for occlusion
    // rather than always drawing things on top of each other
    ofEnableDepthTest();
    
    // ofBox uses texture coordinates from 0-1, so you can load whatever
    // sized images you want and still use them to texture your box
    // but we have to explicitly normalize our tex coords here
    ofEnableNormalizedTexCoords();
    
    // loads the OF logo from disk
    ofLogo.load("boxTex.png");
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
    
    cam.begin();
    
        float boxSize = 100;

        ofLogo.bind();
        ofFill();
        ofSetColor(255);
        ofDrawBox(boxSize);
        ofLogo.unbind();
        
        ofNoFill();
        
        ofPopMatrix();
  
    
    cam.end();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

