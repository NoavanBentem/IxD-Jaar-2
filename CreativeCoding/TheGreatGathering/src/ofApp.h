#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void circularCilinder();
    
        glm::vec3 make_point(float R, float r, float u, float v);
    
        ofEasyCam cam;
        vector<glm::vec3> locations;
};
