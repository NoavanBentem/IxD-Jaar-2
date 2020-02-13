#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void sphereMeshLines();
    void sphereMesh();
    void cilinderParticles();
    void sphereDisolve();
    
    ofEasyCam cam;
    vector<glm::vec3> locations;
    
    int lineCount = 90;
    int particleLineWidth = 1;
    
    float lineAmount = 0;
    float lineLength = 0;
    
    float amountNoise = 0.1;
    
    int sphereDistance = 600;
    float pointWobble = 0.005;
    int lines = 50;
    
    bool drawMesh;
    bool drawSphereDisolve;
		
};
