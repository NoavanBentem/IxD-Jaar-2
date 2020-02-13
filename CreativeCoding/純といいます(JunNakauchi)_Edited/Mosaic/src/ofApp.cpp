#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetWindowTitle("BYOB_LivingSquares_NoavanBentem");
    
    ofBackground(239);
    ofSetLineWidth(3);
    ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
    
    this->size = squareSize;
    for (auto x = size * 0.5; x < ofGetWidth() + size * 0.5; x += size) {
        
        for (auto y = size * 0.5; y < ofGetHeight() + size * 0.5; y += size) {
            
            this->location_list.push_back(glm::vec2(x, y));
            this->noise_seed_list.push_back(ofRandom(1000));
            this->noise_step_list.push_back(ofRandom(1000));
            this->param_list.push_back(0);
        }
    }
}

//--------------------------------------------------------------
void ofApp::update() {
    
    if(squareSize > 5){
        squareSize = ofLerp(squareSize, 5, 0.05);
        //ofLog(OF_LOG_NOTICE, "JA IK HOOR HET TE DOEN");
    }
    
    glm::vec2 noise_location = glm::vec2(ofMap(ofNoise(110, ofGetFrameNum() * 0.005), 0, 1, 0, ofGetWidth()), ofMap(ofNoise(3, ofGetFrameNum() * 0.005), 0, 1, 0, ofGetHeight()));
    
    int index = 0;
    for (auto& location : location_list) {
        
        if (glm::distance(location, noise_location) < 80) {
            
            this->param_list[index] += this->param_list[index] < 100 ? 5 : 0;
        }
        else {
            
            this->param_list[index] -= this->param_list[index] > 0 ? 100 : 0;
        }
        
        this->noise_step_list[index] += this->param_list[index] > 10 ? ofMap(this->param_list[index], 0, 100, 0.01, 0.05) : 0;
        
        index++;
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofColor color;
    int index = 0;
    for (auto& location : location_list) {
        
        color.setHsb(ofMap(ofNoise(this->noise_seed_list[index], this->noise_step_list[index]), 1, 0, 0, 200), whiteness, darkness);
        
        ofSetColor(color, ofMap(this->param_list[index], 100, 100, 200, colorSquares));
        ofDrawRectangle(location, this-size, this->size);
        
        index++;
    }
}
