#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetWindowTitle("Portal_Noa-van-Bentem");
    
    ofBackground(0);
    ofEnableDepthTest();
    ofEnableAlphaBlending();
    
    //**************************************
    ofSetColor(200, 200);
    backCircleBW.load("backCircleBW.jpg");
    
    plane.set(MESH_WIDTH, MESH_HEIGHT);
    plane.setResolution(MESH_SIZE_X, MESH_SIZE_Y);
    plane.setPosition(0, 0, -400);
    plane.mapTexCoordsFromTexture(backCircleBW.getTexture());
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    backCircle();
}

//--------------------------------------------------------------
void ofApp::draw(){

    cam.begin();
    ofEnableAlphaBlending();
    backCircleBW.bind();
    ofDisableAlphaBlending();

    plane.draw();
   
    cam.end();
}

//--------------------------------------------------------------
void ofApp::backCircle(){
    ofMesh& mesh = plane.getMesh();
    
    for (int y = 0; y < MESH_SIZE_Y; y++) {
        for (int x = 0; x < MESH_SIZE_X; x++) {
            int index = x + MESH_SIZE_X * y;
            
            ofPoint vertex = mesh.getVertex(index);
            vertex.z = ofNoise(x * amountNoise, y * amountNoise, ofGetElapsedTimef() * amountNoise) * 100;
            
            mesh.setVertex(index, vertex);
        }
    }
}



