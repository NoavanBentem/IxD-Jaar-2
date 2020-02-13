#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void draw_div_rect(glm::vec2 draw_location, int a, int b);
    
        float scale = 0.5;
        float var = 50;
};
