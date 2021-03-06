#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void mouseMoved(int x, int y );
    
        void audioOut(float * ouput, int bufferSize, int nChannels);
    
        ofSoundStream soundStream;
        float phase;
    
};
