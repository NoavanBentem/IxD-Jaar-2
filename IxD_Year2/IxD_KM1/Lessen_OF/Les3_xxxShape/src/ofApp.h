#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    
    ofxPanel gui;
    ofLight light;
    ofEasyCam cam;
    
    ofIcoSpherePrimitive primitive;
    
    float spinX = 1;
    float spinY = 2;
    float sphereradius = 100;
    
    ofParameter<bool> drawWireframe;
    ofParameter<bool> useLight;
    ofParameter<bool> doRotate;
    ofParameter<bool> lockPin;
    ofParameter<bool> move;
    
    
    ofParameter<float> rotateSpeedX = 1;
    ofParameter<float> rotateSpeedY = 1;
    ofParameter<float> rotateSpeedZ = 1;
    
    ofParameter<float> funkSpeed = 1;
    ofParameter<float> moreSpeed = 1;
    
    float rotateX;
    float rotateY;
    float rotateZ;
    float funk;
    float more;
};
