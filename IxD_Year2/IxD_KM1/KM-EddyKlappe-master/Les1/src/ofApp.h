#pragma once

#include "ofMain.h"
#include "ofEvents.h"

class ofApp : public ofBaseApp{
private:
    float x;
    float y;
    float speedX;
    float speedY;
    int radius;
    
    ofColor color;
    ofArduino arduino;
    
    void setupArduino(const int& version);
    void analogPinChanged(const int& pinNum);
    void digitalPinChanged(const int& pinNum);
    
public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
};
