#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetWindowTitle("squareDance_NoavanBentem");
    
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update() {
    
    ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {
    
    int span = 150;
    for (int x = span * 0.5; x < ofGetWidth(); x += span) {
        
        for (int y = span * 0.5; y < ofGetHeight(); y += span) {
            
            int a = ofMap(ofNoise(ofRandom(10), ofGetFrameNum() * 0.1), 0, 1, 2, var);
            int b = ofMap(ofNoise(ofRandom(10), ofGetFrameNum() * 0.1), 0, 1, 2, var);
            this->draw_div_rect(glm::vec2(x, y), a, b);
        }
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw_div_rect(glm::vec2 draw_location, int a, int b) {
    auto width = a * scale;
    auto height = b * scale;
    auto length = height;
    auto location = glm::vec2();
    auto count = 0;
    
    ofPushMatrix();
    
    
    ofTranslate(draw_location.x - width * 5, draw_location.y - height * 5);
    
    while (length > 0) {
        
        if (count++ % 20 == 0) {
            
            while (location.x + length <= width) {
                ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
                ofFill();
                ofDrawRectangle(location, length, length);
                location.x += length;
            }
            length = width - location.x;
        }
        else {

            while (location.y + length <= height) {
                ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
                ofFill();
                ofDrawRectangle(location, length, length);
                location.y += length;
            }
            length = height - location.y;
        }
    }
    
    ofPopMatrix();
}
