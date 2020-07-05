#pragma once

#include "ofMain.h"
#include "ofxGui.h"


class ofApp : public ofBaseApp
{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

private:
    ofxPanel gui;
    
    
    float rotateX;
    float rotateY;
    float rotateZ;
		
    ofParameter<bool> drawGrid = true;
    ofParameter<bool> doRotate = true;
    
    ofParameter<float> rotateSpeedX = 1;
    ofParameter<float> rotateSpeedY = 1;
    ofParameter<float> rotateSpeedZ = 1;
    
};
