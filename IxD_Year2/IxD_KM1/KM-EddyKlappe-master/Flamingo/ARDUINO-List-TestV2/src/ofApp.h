#pragma once

#include "ofMain.h"

class Particle : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    
    ofVec2f pos;
    ofVec2f velocity;
    ofColor colour;
    float radius;
    
    int rArduino;
    int gArduino;
    int bArduino;
};

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
    vector<Particle> particles;
    bool        clicked;            // a flag for sending serial
    char        bytesRead[30];                // data from serial, we will be trying to read 3
    char        bytesReadString[40];            // a string needs a null terminator, so we need 3 + 1 bytes
    
    int rArduino;
    int gArduino;
    int bArduino;
    
    ofSerial    serial;
};

