#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetFrameRate(20);
    ofBackground(ofColor:: black);

}

//--------------------------------------------------------------
void ofApp::update()
{
    rotateX = rotateX + 1;
    rotateY += 2;
    rotateZ += 3;
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    
    if (doRotate)
    {
        ofRotateXDeg(rotateX);
        ofRotateYDeg(rotateY);
        ofRotateZDeg(rotateZ);
    }
    
    if (drawGrid)
    {
        ofDrawGrid(200);
    }
    
    ofSetColor(ofColor::white);
    ofDrawSphere(100, 100, 100, 50);
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if(key == 'g')
    {
        drawGrid = !drawGrid;
    }
    
    if(key == ' ')
    {
        doRotate = !doRotate;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{

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
