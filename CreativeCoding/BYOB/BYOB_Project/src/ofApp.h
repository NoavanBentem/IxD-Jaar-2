#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

    public:
        void setup();
        void update();
        void draw();
    
        void keyPressed(int key);
    
        ofIcoSpherePrimitive primitive;
    
        ofLight light;
        ofEasyCam cam;
    
        float spinX = 1;
        float spinY = 2;
        float sphereradius = 100;
    
        float potValue;
    
        bool drawWireframe = false;
};
