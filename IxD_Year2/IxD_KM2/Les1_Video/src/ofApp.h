#pragma once

#include "ofMain.h"
#define CAM_WIDTH 1000
#define CAM_HEIGHT 1000

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
    
        bool changeColor = false;
        bool snow = false;
        bool flipVideo = false;
		
        ofVideoGrabber grabber;
        ofPixels workspace; //verzameling puntjes
        ofImage image;
};
