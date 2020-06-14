#pragma once

#include "ofMain.h"
#include "ofEvents.h"

class ofApp : public ofBaseApp {
    
public:
    unsigned long actualTime, sucessTimer;
    unsigned int sucessTimeDelta;
    void setup();
    void update();
    void draw();
    
    float rotateX;
    float rotateY;
    float rotateZ;
    
    bool doRotate;
    void keyPressed(int key);
    
    //ofxPanel gui;
    
    ofParameter<bool> drawGrid;
    ofParameter<bool> useLight;
    //bool drawGui = true;
    
    ofLight light;
    ofEasyCam cam;
    
    ofArduino arduino;
    
    void setupArduino(const int& version);
    
    void digitalPinChanged(const int& pinNum);
    
    void analogPinChanged(const int& pinNum);
};
