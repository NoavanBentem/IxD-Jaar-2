#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofBackground(ofColor::black);
    
    gui.setup();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    gui.add(drawWireframe.set("Wireframe", false));
    gui.add(useLight.set("Light", false));
    gui.add(doRotate.set("Rotate", false));
    gui.add(move.set("Move", true));
    gui.add(lockPin.set("Lock Pin", true));
    gui.add(rotateSpeedX.set("X", 0, 0, 5.0));
    gui.add(rotateSpeedY.set("Y", 0, 0, 5.0));
    gui.add(rotateSpeedZ.set("Z", 0, 0, 9.0));
    gui.add(funkSpeed.set("PointOfset", 0, 0, 9.0));
    gui.add(moreSpeed.set("Funk", 0, 0, 9.0));
    
    light.setDirectional();
    light.setDiffuseColor(ofColor::white);
    light.enable();
    
    primitive = ofIcoSpherePrimitive(sphereradius, 2);
}

//--------------------------------------------------------------
void ofApp::update()
{
    auto triangles = primitive.getMesh().getUniqueFaces();
    float displacement = sin(ofGetElapsedTimef()* funkSpeed) * moreSpeed;
    
    if(move)
    {
        for (int i = 0; i <triangles.size(); i++)
        {
            ofVec3f faceNormal = triangles[i].getFaceNormal();
            
            
            for (int j = 1; j < 3; j++)
            {
                triangles[i].setVertex(j, triangles[i].getVertex(j)+ faceNormal * displacement);
            }
            
        }
    }
    primitive.getMesh().setFromTriangles(triangles);
    
    rotateX = rotateSpeedX;
    rotateY = rotateSpeedY;
    rotateZ = rotateSpeedZ;
}

//--------------------------------------------------------------
void ofApp::draw()
{
    gui.draw();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    
    if(drawWireframe)
    {
        primitive.drawWireframe();
    }
    else
    {
        primitive.draw();
    }
    
    if (useLight) {
        ofEnableLighting();
    } else {
        ofDisableLighting();
    }
    
    if (doRotate)
    {
        primitive.rotateDeg(spinX, rotateX, 0, 0);
        primitive.rotateDeg(spinY, 0, rotateY, 0);
        //ofRotateXDeg(rotateX);
        //ofRotateYDeg(rotateY);
        //ofRotateZDeg(rotateZ);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    
}

