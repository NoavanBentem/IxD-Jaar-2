#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetFrameRate(20);
    
    soundStream.printDeviceList();
    soundStream.setDeviceID(1);
    soundStream.setup(this, 2, 0, 22050, 512, 4); // kanalen, input, frq, grootte, hoeveel
}

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------

void ofApp::mouseMoved(int x, int y )
{

}

void ofApp :: audioOut(float * output, int bufferSize, int nChannels)
{
    for(int i = 0; i < bufferSize * nChannels; ++i)
    {
        float sample = sin(phase);
        output[i] = sample;
        
        sample = sin(phase * 1.008f);
        output[i+1] = sample;
        
        phase += 0.04;
    }
}


