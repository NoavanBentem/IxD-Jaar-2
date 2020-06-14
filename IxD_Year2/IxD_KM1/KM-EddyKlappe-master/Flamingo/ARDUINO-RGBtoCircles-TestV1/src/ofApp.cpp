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
        
        r = ofToInt(ofToString(bytesReadString[0]) + ofToString(bytesReadString[1]) + ofToString(bytesReadString[2]));
        g = ofToInt(ofToString(bytesReadString[3]) + ofToString(bytesReadString[4]) + ofToString(bytesReadString[5]));
        b = ofToInt(ofToString(bytesReadString[6]) + ofToString(bytesReadString[7]) + ofToString(bytesReadString[8]));
        
        if (r >255){
            r = ofToInt(ofToString(bytesReadString[0]) + ofToString(bytesReadString[1]));
        }
        if (g >255){
            g = ofToInt(ofToString(bytesReadString[3]) + ofToString(bytesReadString[4]));
        }
        if (b >255){
            b = ofToInt(ofToString(bytesReadString[6]) + ofToString(bytesReadString[7]));
        }
        
        bSendSerialMessage = false;
    }
}

void ofApp::draw(){
    ofSetColor(100);
    ofDrawBitmapString("read: " + ofToString(bytesReadString), 100, 100);
    
    ofSetColor(r, g, b);
    ofDrawCircle(50, 50, 50);
    
    ofDrawBitmapString("R: " + ofToString(r), 300, 100);
    ofDrawBitmapString("G: " + ofToString(g), 300, 150);
    ofDrawBitmapString("B: " + ofToString(b), 300, 200);
    
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

