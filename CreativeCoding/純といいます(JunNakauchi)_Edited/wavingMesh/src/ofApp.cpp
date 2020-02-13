#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetWindowTitle("openFrameworks");
    
    ofBackground(0);
    ofSetLineWidth(3);
    ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    this->cam.begin();
    
    auto len = 600;
    for (auto z = len * -10; z <= len * 10; z += waveSpacing) {
        
        vector<glm::vec3> vertices_1;
        for (auto param = len * -3; param <= len * 3; param += waveRoundness) {
            
            auto height_1 = ofMap(ofNoise(param * 0.005, ofGetFrameNum() * 0.01 + z * 0.005), 0, waveHeight, len * -0.35, 0);
            auto height_2 = ofMap(ofNoise(param * 0.005, ofGetFrameNum() * 0.01 + z * 0.005), 0, waveHeight, 0, len * 0.35);
            vertices_1.push_back(glm::vec3(param, height_1, z));
        }
        
        vertices_1.push_back(glm::vec3(len * 0.5, len * -0.5, z));
        
        ofFill();
        ofSetColor(239);
        ofBeginShape();
        ofVertices(vertices_1);
        ofEndShape(true);
        
        ofNoFill();
        ofSetColor(0);
        ofBeginShape();
        ofVertices(vertices_1);
        ofEndShape(true);
    }
    
    this->cam.end();
}
