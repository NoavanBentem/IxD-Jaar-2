#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetWindowTitle("TheGreatGathering_NoavanBentem");
    
    ofBackground(0);
    ofEnableDepthTest();
    ofEnableAlphaBlending();
    ofSetLineWidth(1.5);
}

//--------------------------------------------------------------
void ofApp::update(){
    circularCilinder();
}

//--------------------------------------------------------------
void ofApp::draw(){
    this->cam.begin();
    
    for (auto& location : this->locations) {
        
        ofSetColor(255);
        ofDrawSphere(location, 3);
        for (auto& other : this->locations) {
            
            if (location == other) { continue; }
            float distance = glm::distance(location, other);
            if (distance < 50) {
                
                ofSetColor(255);
                ofDrawLine(location, other);
            }
        }
        
    }
    
    this->cam.end();
}

//--------------------------------------------------------------
glm::vec3 ofApp::make_point(float R, float r, float u, float v) {
    
    
    u *= DEG_TO_RAD;
    v *= DEG_TO_RAD;
    
    float x = (R + r * cos(u)) * cos(v);
    float y = (R + r * cos(u)) * sin(v);
    float z = r * sin(u);
    
    return glm::vec3(x, y, z);
    
}


//===============================================================
void ofApp::circularCilinder(){
    ofSeedRandom(39);
    this->locations.clear();
    while (this->locations.size() < 500) {
        
        float R = 600;
        float r = 600;
        float u = ofRandom(0, 360) + ofGetFrameNum() * ofRandom(0.5, 2);
        float v = ofRandom(0, 360);
        
        this->locations.push_back(this->make_point(R, r, u, v));
    }
}
