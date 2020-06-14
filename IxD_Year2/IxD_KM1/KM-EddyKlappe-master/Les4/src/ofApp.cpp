#include "ofApp.h"

void ofApp::setup(){
    ofBackground(ofColor::black);
    
    primitive = ofIcoSpherePrimitive(sphereRadius, 2);
}

void ofApp::update(){
    auto triangles = primitive.getMesh().getUniqueFaces();
    float displacement = sin(ofGetElapsedTimef() * 4) * 10;
    for (int i = 0; i < triangles.size(); ++i){
    ofVec3f faceNormal = triangles[i].getFaceNormal();
        for (int j = 0; j < 3; j++){
            triangles[i].setVertex(j, triangles[i].getVertex(j)+ faceNormal * displacement);
    }
    }
    
    primitive.getMesh().setFromTriangles(triangles);
}

void ofApp::draw(){
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    
    primitive.rotateDeg(spinX,1,0,0);
    primitive.rotateDeg(spinY,0,1,0);

    
    if (drawWireframe){
        primitive.drawWireframe();
    }
    else{
        primitive.draw();
    }
}

void ofApp::keyPressed(int key){
    if (key ==' '){
        drawWireframe = !drawWireframe;
    }
}
