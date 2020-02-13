#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofBackground(ofColor::black);
    primitive = ofIcoSpherePrimitive(sphereradius, 2);
    
    light.setDirectional();
    light.setDiffuseColor(ofColor::white);
    light.enable();
}

//--------------------------------------------------------------
void ofApp::update()
{
    
//    auto triangles = primitive.getMesh().getUniqueFaces();
//    float displacement = sin(ofGetElapsedTimef()* 4) * 10;
//
//    for (int i = 0; i <triangles.size(); i++)
//    {
//        ofVec3f faceNormal = triangles[i].getFaceNormal();
//        for (int j = 1; j < 3; j++)
//        {
//            triangles[i].setVertex(j, triangles[i].getVertex(j)+ faceNormal * displacement);
//        }
//    }
    
    //primitive.getMesh().setFromTriangles(triangles);
}

//--------------------------------------------------------------
void ofApp::draw()
{
    
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    
    primitive.rotateDeg(spinX, 1, 0, 1);
    primitive.rotateDeg(spinY, 0, 0, 1);
    
    
    if(drawWireframe)
    {
        primitive.drawWireframe();
    }
    else
    {
        primitive.draw();
    }
    
    ofSetIcoSphereResolution(10);
    
    
    
    //============
    cam.setVFlip(true);
    cam.begin();
    
    ofEnableLighting();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if(key == ' ')
    {
        drawWireframe = !drawWireframe;
    }
}
