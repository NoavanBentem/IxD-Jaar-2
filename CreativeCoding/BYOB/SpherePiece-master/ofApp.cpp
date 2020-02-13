#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(80);
    ofSetWindowTitle("SpherePiece");
    
    ofBackground(255);
    ofSetColor(255, 255, 255);
    ofEnableDepthTest();
    ofSetLineWidth(4);
    ofEnableAlphaBlending();
    
    auto ico_sphere = ofIcoSpherePrimitive(250, 3);
    this->triangles = ico_sphere.getMesh().getUniqueFaces();
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    this->cam.begin();
    ofRotateY(ofGetFrameNum());
    
    for(auto& triangle : this->triangles){
        glm::vec3 avg = (triangle.getVertex(0) + triangle.getVertex(1) + triangle.getVertex(2)) / 3;
        auto noise_value = ofNoise(avg.x * 0.0015, avg.y * 0.0015, avg.z + 0.0015, ofGetFrameNum() * 0.0025);
        auto tmp_radius = 280.f;
        auto rotate = 0.f;
        if(noise_value >= 0.6){
            tmp_radius += ofMap(noise_value, 0.6, 1, 0, 400);
            rotate = ofMap(noise_value, 0.6, 1, 0, 360 * 4);
        }
        auto tmp_avg = glm::normalize(avg) * tmp_radius;
        
        ofPushMatrix();
        ofTranslate(tmp_avg);
        ofRotateX(rotate);
        ofRotateY(rotate);
        
        vector<glm::vec3> vertices;
        vector<glm::vec3> fill_vertices;
        for(int j = 0; j < 3; j++){
            glm::vec3 location = glm::vec3(triangle.getVertex(j).x, triangle.getVertex(j).y, triangle.getVertex(j).z) - avg;
            vertices.push_back(location);
            fill_vertices.push_back(location * 0.95);
        }
        
        ofFill();
        ofSetColor(46, 160, 160, 180);
        ofBeginShape();
        ofVertices(fill_vertices);
        ofEndShape(true);
        
        ofNoFill();
        ofSetColor(252, 215, 68, 70);
        
        ofBeginShape();
        ofVertices(vertices);
        ofEndShape(true);
        
        ofPopMatrix();
    }
    
    this->cam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
