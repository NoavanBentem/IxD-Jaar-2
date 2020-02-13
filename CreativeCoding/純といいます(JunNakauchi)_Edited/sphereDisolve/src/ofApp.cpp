#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetWindowTitle("openframeworks");
    
    ofBackground(239);
    ofSetColor(39);
    ofSetLineWidth(3);
    ofEnableDepthTest();
    
    auto ico_sphere = ofIcoSpherePrimitive(150, 2);
    auto triangles = ico_sphere.getMesh().getUniqueFaces();
    for (auto& triangle : triangles) {
        
        auto avg = glm::vec3(triangle.getVertex(0) + triangle.getVertex(1) + triangle.getVertex(2)) / 3;
        this->locations.push_back(avg);
    }
}

//--------------------------------------------------------------
void ofApp::update() {
    
    ofSeedRandom(39);
    sphereSize = ofLerp(sphereSize, 4, 0.1);
    if (ofGetElapsedTimef() > 4){
        pointWobble = ofLerp(pointWobble, 0.1, 0.0003);
    
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    
    this->cam.begin();
    ofRotateY(ofGetFrameNum() * 0.5);
    
    vector<glm::vec3> tmp_locations;
    for (auto& location : this->locations) {
        
        auto radius = (((int)ofMap(ofNoise(location.x * 0.008, location.y * 0.008, location.z * 0.008, ofGetFrameNum() * pointWobble), 0, 1, 0, 150) + ofGetFrameNum()) % sphereDistance) + 0;
        if (radius < 200) {
            
            radius = 200;
        }
        
        auto tmp_location = glm::normalize(location) * radius;
        tmp_locations.push_back(tmp_location);
    }
    
    for (auto& location : tmp_locations) {
        
        ofDrawSphere(location, sphereSize);
        for (auto& other : tmp_locations) {
            
            if (location == other) { continue; }
            float distance = glm::distance(location, other);
            if (distance < 45){
                
                ofDrawLine(location, other);
            }
        }
    }
    
    this->cam.end();
}
