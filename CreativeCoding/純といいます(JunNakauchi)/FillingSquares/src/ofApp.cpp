#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetWindowTitle("openFrameworks");
    
    ofBackground(39);
    ofSetLineWidth(5);
    
    this->start_param = ofRandom(100, 200);
}


//--------------------------------------------------------------
void ofApp::update() {
    
    if (ofGetFrameNum() % 100 == 0) {
        
        this->start_param += ofRandom(25, 50);
        this->color.setHsb(this->color.getHue() + ofRandom(10, 30), 255, 255);
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    
    ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
    
    auto len = 100;
    auto width = ofGetFrameNum() % 100;
    vector<glm::vec2> vertices;
    
    for (auto param = this->start_param - width * 0.5; param <= this->start_param + width * 0.5; param++) {
        
        vertices.push_back(this->make_point(len, param));
    }
    
    ofFill();
    ofSetColor(this->color, 64);
    ofBeginShape();
    ofVertices(vertices);
    ofEndShape(true);
    
    ofNoFill();
    ofSetColor(this->color);
    ofBeginShape();
    ofVertices(vertices);
    ofEndShape(true);
    
}

//--------------------------------------------------------------
glm::vec2 ofApp::make_point(int len, int param) {
    
    param = param % 100;
    if (param < 25) {
        
        return glm::vec2(ofMap(param, 0, 25, -len * 0.5, len * 0.5), -len * 0.5);
    }
    else if (param < 50) {
        
        return glm::vec2(len * 0.5, ofMap(param, 25, 50, -len * 0.5, len * 0.5));
    }
    else if (param < 75) {
        
        return glm::vec2(ofMap(param, 50, 75, len * 0.5, -len * 0.5), len * 0.5);
    }
    else {
        
        return glm::vec2(-len * 0.5, ofMap(param, 75, 100, len * 0.5, -len * 0.5));
    }
}
