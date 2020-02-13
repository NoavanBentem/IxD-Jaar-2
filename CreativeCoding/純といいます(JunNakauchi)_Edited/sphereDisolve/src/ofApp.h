#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        int sphereDistance = 700;
        float sphereSize = 150;
        float pointWobble = 0.005;
    
        ofEasyCam cam;
        vector<glm::vec3> locations;
};
