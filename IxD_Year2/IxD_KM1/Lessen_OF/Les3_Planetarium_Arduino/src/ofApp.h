#pragma once

#include "ofMain.h"
#include "ofEvents.h"
#include "ofxGui.h"
class ofApp : public ofBaseApp {
    
public:
    
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void keyPressed(int key);
    
private:
    ofArduino arduino;
    ofxPanel gui;
    
    float rotateX;
    float rotateY;
    float rotateZ;
    float rotateOffset1;
    float rotateOffset2;
    
    
    float potValue;
    float buttonValue;
    
    ofParameter<bool> drawGrid = false;
    ofParameter<bool> doRotate = false;
    ofParameter<bool> useLight = false;
    
    ofParameter<float> rotateSpeedY = 1;
    
    
    void setupArduino(const int& version);
    void digitalPinChanged(const int& pinNum);
    void analogPinChanged(const int& pinNum);
    
    //=====================
    ofLight light;
    ofTexture mTex;
    ofEasyCam cam;
};

