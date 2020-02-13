#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        int waveSpacing = 100;
        int waveRoundness = 20;
        int waveHeight = 5;

		ofEasyCam cam;
};
