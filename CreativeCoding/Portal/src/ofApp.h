#pragma once

#include "ofMain.h"

#define MESH_WIDTH 2100
#define MESH_HEIGHT 1200
#define MESH_SIZE_X 100
#define MESH_SIZE_Y 60

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void backCircle();
    
    ofEasyCam cam;
    vector<glm::vec3> locations;
    
    float amountNoise = 0.1;
    
    ofPlanePrimitive plane;
    ofImage backCircleBW;

};
