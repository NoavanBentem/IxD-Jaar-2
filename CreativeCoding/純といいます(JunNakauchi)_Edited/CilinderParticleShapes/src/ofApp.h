#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        int lineCount = 90;

		ofEasyCam cam;
		
};
