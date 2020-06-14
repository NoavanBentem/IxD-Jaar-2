#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);

    font.load("DIN.otf", 64);
    
    serial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
    
    int baud = 9600;
    serial.setup(0, 9600); //open the first device
    bSendSerialMessage = false;

}

//--------------------------------------------------------------
void ofApp::update(){
        int bytesRequired = 8;
        unsigned char bytes[bytesRequired];
        int bytesRemaining = bytesRequired;
        
        // loop until we've read everything
        //while ( bytesRemaining > 0 ){
            
            // try to read - note offset into the bytes[] array, this is so
            // that we don't overwrite the bytes we already have
            //int bytesArrayOffset = bytesRequired - bytesRemaining;
            int result = serial.readBytes( &bytes[8],
                                   8 );
            
            
            bytesRemaining = result;
            
            //arduinoSerial = result;
        //}
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(150);

    string msg;
    msg += "click to test serial:\n";
    msg += "read: " + ofToString(bytesRemaining) + "\n";
    font.drawString(msg, 50, 100);
    
    ofSetColor(150);
    ofDrawBitmapString("hello world", 300 , 300);
    
    ofSetColor(150);
    ofDrawBitmapString("read: " + ofToString(bytesRemaining), 500 , 300);
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
    int bytesRemaining = 10;
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

long ofSerial::readBytes(unsigned char *buffer, size_t length){

        }


