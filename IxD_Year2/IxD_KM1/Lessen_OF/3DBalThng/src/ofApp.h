#pragma once

#include "ofMain.h"
#include "ofEvents.h"

class ofApp : public ofBaseApp
{
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
    float rotateSpeedX;
    float rotateSpeedY;
    float rotateSpeedZ;
    bool drawGrid;
    bool doRotate;
    bool bounce;
    bool lighting;
    
    ofLight light;
    ofEasyCam cam;
    
    float rotateX;
    float rotateY;
    float rotateZ;
    
    float posX = 500;
    float posY = 500;
    float posZ = 5;
    float speed = ofRandom(5, 15);
    
    float ldrValue;
    
    bool moveRight = true;
    bool moveDown = true;
    bool moveDepth = true;
    
    
    ofIcoSpherePrimitive sphere;
    
    private:
    ofArduino arduino;
    
    void setupArduino(const int& version);
    
    void digitalPinChanged(const int& pinNum);
    
    void analogPinChanged(const int& pinNum);
    
};
