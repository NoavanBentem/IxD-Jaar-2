#include "ofApp.h"

void ofApp::setup(){
    ofSetVerticalSync(true);
    
    bSendSerialMessage = false;
    ofBackground(255);
    //ofSetLogLevel(OF_LOG_VERBOSE);
    
    serial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
    
    int baud = 9600;
    serial.setup(0, 9600);
    
}

void ofApp::update(){
    
    if (bSendSerialMessage){
        unsigned char bytesReturned[30];
        serial.readBytes( bytesReturned, 30);
        memcpy(bytesReadString, bytesReturned, 30);
        bSendSerialMessage = false;
    }
}

void ofApp::draw(){
    ofSetColor(100);
    ofDrawBitmapString("read: " + ofToString(bytesReadString), 100, 100);
    
}

void ofApp::keyPressed  (int key){
    
}

void ofApp::keyReleased(int key){
    
}

void ofApp::mouseMoved(int x, int y){
    
}

void ofApp::mouseDragged(int x, int y, int button){
    
}

void ofApp::mousePressed(int x, int y, int button){
    bSendSerialMessage = true;
}

void ofApp::mouseReleased(int x, int y, int button){
    
}

void ofApp::mouseEntered(int x, int y){
    
}

void ofApp::mouseExited(int x, int y){
    
}

void ofApp::windowResized(int w, int h){
    
}

void ofApp::gotMessage(ofMessage msg){
    
}

void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

