#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetFrameRate(20);
    ofBackground(ofColor:: black);
    
    gui.setup();
    gui.add(drawGrid.set("Grid", false));
    gui.add(doRotate.set("Rotate", false));
    gui.add(rotateSpeedX.set("X", 0, 0, 9.0));
    gui.add(rotateSpeedY.set("Y", 0, 0, 9.0));
    gui.add(rotateSpeedZ.set("Z", 0, 0, 9.0));
    
}

//--------------------------------------------------------------
void ofApp::update()
{
    rotateX = rotateX + rotateSpeedX;
    rotateY += rotateSpeedY;
    rotateZ += rotateSpeedZ;
}

//--------------------------------------------------------------
void ofApp::draw()
{
    gui.draw();
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

