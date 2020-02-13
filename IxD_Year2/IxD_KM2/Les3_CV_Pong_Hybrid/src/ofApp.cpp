#include "ofApp.h"
#define GRABBER_WIDTH 640
#define GRABBER_HEIGHT 480

void ofApp::setup() {
    ofSetBackgroundColor(ofColor::black);
    ofSetCircleResolution(20);
    
    //--------------------------------------------------------------------------------------------------------------------------
    grabber.setup(GRABBER_WIDTH, GRABBER_HEIGHT);
    haarFinder.setup("haarcascade_frontalface_default.xml");
    edwinImage.load("edwin.png");
}

void ofApp::update() {
    paddleY = MIN(MAX(mouseY - PADDLE_HEIGHT / 2, 0), ofGetHeight() - PADDLE_HEIGHT);
    bool wasReset = ball.update(paddleY);
    if (wasReset)
    {
        missedCount++;
    }
    
    //--------------------------------------------------------------------------------------------------------------------------
    grabber.update();
    if(grabber.isFrameNew())
    {
        haarFinder.findHaarObjects(grabber.getPixels(), 100, 100);
    }
}

void ofApp::draw() {
    ball.draw();

    ofDrawRectangle(ofGetWidth() - PADDLE_WIDTH, paddleY, PADDLE_WIDTH, PADDLE_HEIGHT);
    
    ofDrawRectangle(ofGetWidth() - PADDLE_WIDTH, paddleY, PADDLE_WIDTH, PADDLE_HEIGHT);

    ofDrawBitmapString("Missed: " + ofToString(missedCount), 10, 10);
    
    //--------------------------------------------------------------------------------------------------------------------------
    for(int i = 0; i < haarFinder.blobs.size(); i++)
    {
        ofRectangle boundingBox = haarFinder.blobs[i].boundingRect;
        ofDrawRectangle(boundingBox);
        
        
        edwinImage.draw(boundingBox);
    }
}

void ofApp::keyPressed(int key) {
    ball.reset();
    
    if(key == 'OF_KEY_UP')
}
