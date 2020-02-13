#pragma once

#include "ofMain.h"

#define MESH_WIDTH 480
#define MESH_HEIGHT 300
#define MESH_SIZE_X 50
#define MESH_SIZE_Y 30

class ofApp : public ofBaseApp{

	public:
        void setup();
        void update();
        void draw();
        void keyPressed(int key) override;
    
        ofPlanePrimitive plane;
        ofImage image;
        bool drawWireframe;
    
        ofEasyCam cam;
		
};
