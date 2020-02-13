#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp
{
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		
        ofVideoGrabber grabber;
        ofxCvHaarFinder haarFinder;
        ofxCvHaarFinder haarFinderEyes;
        ofxCvHaarFinder haarFinderBody;
    
        ofImage image;
        ofImage imageEyes;
        ofImage imageBody;
};
