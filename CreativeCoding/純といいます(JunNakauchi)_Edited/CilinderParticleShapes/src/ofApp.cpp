#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetWindowTitle("openFrameworks");
    
    ofBackground(239);
    ofSetColor(39);
    ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {
    
    ofSeedRandom(500);
}

//--------------------------------------------------------------
void ofApp::draw() {
    
    this->cam.begin();
    ofRotateX(90);
    
    auto radius = 1000;
    auto deg_span = 3;
    vector<glm::vec3> locations;
    for (int deg = 0; deg < 360; deg += deg_span) {
        
        locations.push_back(glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), -radius));
        locations.push_back(glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), radius));
    }
    
    for (int i = 0; i < 600; i++) {
        
        int z = (int)(ofRandom(radius * 2) + ofGetFrameNum() * ofRandom(1, 3)) % radius * 2 - radius;
        int deg = (int)ofRandom(0, 360) / deg_span * deg_span;
        
        locations.push_back(glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), z));
    }
    
    for (auto& location : locations) {
        
        ofSetColor(39, ofMap(location.y, -radius, radius, 255, 32));
        ofDrawSphere(location, 3);
        for (auto& other : locations) {
            
            if (location == other) { continue; }
            float distance = glm::distance(location, other);
            if (distance < lineCount) {
                
                ofDrawLine(location, other);
            }
        }
    }
    
    this->cam.end();
}
