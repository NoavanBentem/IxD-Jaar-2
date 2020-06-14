#pragma once

#include "ofMain.h"
#include "ofEvents.h"


class Particle : public ofBaseApp {
public:
    void setup(int rArduino, int gArduino, int bArduino);
    void update();
    void draw();
    
    ofVec2f pos;
    ofVec2f velocity;
    ofColor colour;
    float radius;
};

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    
    char        bytesRead[30];
    char        bytesReadString[40];
    
    int rArduino;
    int gArduino;
    int bArduino;
    
    ofSerial    serial;
    
    vector<Particle> particles;
    bool        clicked;
    
};



