#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    beefButton.set(ofGetWidth()/2, 650);
    tofuButton.set(ofGetWidth()/2-300, 650);
    cheeseButton.set(ofGetWidth()/2+300, 650);
    radius = 30;
    beefBool = false;
    tofuBool = false;
    cheeseBool = false;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    buttonsDraw();
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (beefButton.distance(ofPoint(x,y)) < radius) {
        defaultButtons();
        beefBool = true;
    }
    
    if (tofuButton.distance(ofPoint(x,y)) < radius) {
        defaultButtons();
        tofuBool = true;
    }
    
    if (cheeseButton.distance(ofPoint(x,y)) < radius) {
        defaultButtons();
        cheeseBool = true;
    }
}

void ofApp::buttonsDraw(){
    
    if (beefBool)
    {
        ofSetColor(255);
        ofNoFill();
    }
    else
    {
        ofFill();
        ofSetColor(ofColor::gray);
    }
    ofCircle(beefButton, radius);
    
    if (tofuBool)
    {
        
        ofSetColor(255);
        ofNoFill();
    }
    else
    {
        ofFill();
        ofSetColor(ofColor::gray);
    }
    ofCircle(tofuButton, radius);
    
    if (cheeseBool)
    {
        ofSetColor(255);
        ofNoFill();
    }
    else
    {
        ofFill();
        ofSetColor(ofColor::gray);
    }
    ofCircle(cheeseButton, radius);
}

void ofApp::defaultButtons()
{
    beefBool = false;
    tofuBool = false;
    cheeseBool = false;
}
