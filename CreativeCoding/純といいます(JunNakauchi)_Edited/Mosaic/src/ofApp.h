#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        int whiteness = 200;
        int darkness = 255;
        float squareSize = 200;
        int colorSquares = 1;

        int size;
        vector<glm::vec2> location_list;
        vector<float> noise_seed_list;
        vector<float> noise_step_list;
        vector<int> param_list;
		
};
