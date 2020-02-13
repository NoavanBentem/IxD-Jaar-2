#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetWindowTitle("CircleDance");
    
    ofBackground(234, 255, 250);
    ofSetLineWidth(4);
    ofEnableDepthTest();
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSeedRandom(200);
    this->locations.clear();
    
    int radius = 350;
    float noise_seed_x, noise_seed_y;
    for(int i = 0; i < 5; i++){
        noise_seed_x = ofRandom(1000);
        noise_seed_y = ofRandom(1000);
        for(int deg = 0; deg < 360; deg += 3){
            auto point = glm::vec3(radius * cos(deg * DEG_TO_RAD),
                                   radius * sin(deg * DEG_TO_RAD), 0);
            auto rotation_x = glm::rotate(glm::mat4(),
                                          ofMap(ofNoise(noise_seed_x, ofGetFrameNum() * 0.0005), 0, 1.5, -PI, PI),
                                          glm::vec3(1, 0, 0));
            auto rotation_y = glm::rotate(glm::mat4(),
                                          ofMap(ofNoise(noise_seed_y, ofGetFrameNum() * 0.0005), 0, 1.5, -PI, PI),
                                          glm::vec3(0, 1, 0));
            this->locations.push_back(glm::vec4(point, 0) * rotation_x * rotation_y);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    this->cam.begin();
    for(auto& location : this->locations){
        ofSetColor(221, 48, 129, 220);
        ofDrawSphere(location, 7);
        for(auto& other : this->locations){
            float distance = glm::distance(location, other);
            if(distance < 120){
                ofSetColor(224, 159, 189, ofMap(distance, 100, 120, 239, 0));
                ofDrawLine(location, other);
            }
        }
    }
    this->cam.end();
}
