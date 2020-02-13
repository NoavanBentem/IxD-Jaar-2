#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void mousePressed(int x, int y, int button);

    
    ofImage ofLogo; // the OF logo
    ofLight light; // creates a light and enables lighting
    ofEasyCam cam; // add mouse controls for camera movement
};

