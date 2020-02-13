#include "ofApp.h"

void ofApp::setup() {
    image.load("backCircle.jpeg");
    
    plane.set(MESH_WIDTH, MESH_HEIGHT);
    plane.setResolution(MESH_SIZE_X, MESH_SIZE_Y);
    
    plane.mapTexCoordsFromTexture(image.getTexture());
}

void ofApp::update() {
    ofMesh& mesh = plane.getMesh();
    
    for (int y = 0; y < MESH_SIZE_Y; y++) {
        for (int x = 0; x < MESH_SIZE_X; x++) {
            int index = x + MESH_SIZE_X * y;
            
            ofPoint vertex = mesh.getVertex(index);
            vertex.z = ofNoise(x * 0.05, y * 0.05, ofGetElapsedTimef() * 0.5) * 100;
            
            mesh.setVertex(index, vertex);
        }
    }
}

void ofApp::draw() {
    ofBackground(ofColor::black);
    
    //    cam.setVFlip(true);
    cam.begin();
    
    image.bind();
    if (drawWireframe) {
        plane.drawWireframe();
    } else {
        plane.draw();
    }
    image.unbind();
    
    cam.end();
}

void ofApp::keyPressed(int key) {
    if (key == ' ') {
        drawWireframe = !drawWireframe;
    }
    
}
