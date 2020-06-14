#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
    ofIcoSpherePrimitive primitive;
    float spinX = 1;
    float spinY = 2;
    float sphereRadius = 100;
    
    bool drawWireframe = true ;
};
