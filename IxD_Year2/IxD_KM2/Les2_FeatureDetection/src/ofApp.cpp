#include "ofApp.h"
#define GRABBER_WIDTH 640
#define GRABBER_HEIGHT 480
//--------------------------------------------------------------
void ofApp::setup()
{
    grabber.setup(GRABBER_WIDTH, GRABBER_HEIGHT);
    
    haarFinder.setup("haarcascade_frontalface_default.xml");
    haarFinderEyes.setup("haarcascade_eyes.xml");
    haarFinderBody.setup("haarcascade_fullbody.xml");

    
    image.load("edwin.png");
    imageEyes.load("eyes.png");
    imageBody.load("alien.png");
}

//--------------------------------------------------------------
void ofApp::update()
{
    grabber.update(); //Gets images from webcam
    
    if(grabber.isFrameNew())
    {
        haarFinder.findHaarObjects(grabber.getPixels(), 100, 100);
        haarFinderEyes.findHaarObjects(grabber.getPixels(), 75, 75);//Searching for eyes of certain size(75, 75)
        haarFinderBody.findHaarObjects(grabber.getPixels(), 50, 150);

    }
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw()
{
    grabber.draw(0,0); //
    
    ofNoFill();
    ofSetColor(ofColor::lawnGreen);
    for(int i = 0; i < haarFinder.blobs.size(); i++) //Blobs are things to find
    {
        ofRectangle boundingBox = haarFinder.blobs[i].boundingRect;
        ofDrawRectangle(boundingBox);
        
        image.draw(boundingBox);
    }
    
    
    for(int i = 0; i < haarFinderEyes.blobs.size(); i++) //Blobs are things to find
    {
        ofRectangle boundingBoxEyes = haarFinderEyes.blobs[i].boundingRect;
        ofDrawRectangle(boundingBoxEyes);
        
        imageEyes.draw(boundingBoxEyes);
    }
    
    for(int i = 0; i < haarFinderBody.blobs.size(); i++) //Blobs are things to find
    {
        ofRectangle boundingBoxBody = haarFinderBody.blobs[i].boundingRect;
        ofDrawRectangle(boundingBoxBody);
        
        imageBody.draw(boundingBoxBody);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

