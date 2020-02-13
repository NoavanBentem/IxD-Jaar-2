#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

        glm::vec2 make_point(int len, int param);
        
        float start_param;
        ofColor color;
		
};
