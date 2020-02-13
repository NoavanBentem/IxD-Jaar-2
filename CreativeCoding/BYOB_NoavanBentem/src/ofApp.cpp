#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetWindowTitle("BYOB_Noa-van-Bentem");
    
    ofBackground(0);
    lineAmount = (200);
    
    auto ico_sphere = ofIcoSpherePrimitive(150, 2);
    auto triangles = ico_sphere.getMesh().getUniqueFaces();
    for (auto& triangle : triangles) {
        
        auto avg = glm::vec3(triangle.getVertex(0) + triangle.getVertex(1) + triangle.getVertex(2)) / 3;
        this->locations.push_back(avg);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSeedRandom(500);
    
    if(ofGetElapsedTimef() > 0 and ofGetElapsedTimef() < 40){
        drawSphereDisolve = true;
    }
    
    if(drawSphereDisolve){
        ofSeedRandom(39);
        
        if (ofGetElapsedTimef() > 4){
            pointWobble = ofLerp(pointWobble, 0.05, 0.0003);
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cilinderParticles();
    
    if(drawMesh){
        this->cam.begin();
        for(auto& location : this->locations){
            for(auto& other : this->locations){
                float distance = glm::distance(location, other);
                if(distance < lineLength){
                    ofSetColor(255, ofMap(distance, 100, 120, 239, 0));
                    ofSetLineWidth(4);
                    ofDrawLine(location, other);
                }
            }
        }
        this->cam.end();
    }
    
    if(drawSphereDisolve){
        sphereDisolve();
    }
}

//--------------------------------------------------------------
void ofApp::cilinderParticles(){
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
        
        ofSetColor(100, ofMap(location.y, -radius, radius, 255, 32));
        ofDrawSphere(location, 3);
        for (auto& other : locations) {
            
            if (location == other) { continue; }
            float distance = glm::distance(location, other);
            if (distance < lineCount) {
                ofSetLineWidth(particleLineWidth);
                ofDrawLine(location, other);
            }
        }
    }
    
    this->cam.end();
}

void ofApp::sphereDisolve(){
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
        ofSetColor(255);
        ofDrawSphere(location, 3);
        for (auto& other : tmp_locations) {
            
            if (location == other) { continue; }
            float distance = glm::distance(location, other);
            if (distance < lines){
                ofSetColor(255);
                ofDrawLine(location, other);
            }
        }
    }
    
    this->cam.end();
}

