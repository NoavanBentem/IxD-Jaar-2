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
    
    void mousePressed(int x, int y, int button);
    
    void mouseReleased(int x, int y, int button);
    
    ofEasyCam cam;
    
private:
    ofParameter<bool> drawGrid = true;
    
    float x;
    float y;

    float speedX;
    float speedY;
    
    float rotateX;
    float rotateY;

    int radius;
    
    ofColor color;
    ofArduino arduino;
    
    void setupArduino(const int& version);
    
    void digitalPinChanged(const int& pinNum);
    
    void analogPinChanged(const int& pinNum);
    
};

