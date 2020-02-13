#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    for(int i = 0; i < VOICES; i++)
    {
        ofLog() << "Loading voice" << i << endl;
        voicePlayer[i].load("voice" + ofToString (i + 1) + ".wav");
        voicePlayer[i].setLoop(true);
        
        voicePlayer[i].play();
        voicePlayer[i].setPaused(true);
    }
    
    ofSoundSetVolume(0.2);
}

//--------------------------------------------------------------
void ofApp::update()
{
    float time = ofGetElapsedTimef();
    float x = time * 0.1f + 30;
    for(int i = 0; i < VOICES; i++)
    {
        float y = i * 0.2f;
        float volume = ofNoise(x, y);
        voicePlayer[i].setVolume(volume);
        
        //ofLog() << ofNoise(x, y) << endl; // Wat wie waar
        //voicePlayer[i].setSpeed(ofNoise(x, y)); // Demonische setting
    }
    ofSoundUpdate();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(ofColor :: black);
    
    for(int i = 0; i < VOICES; ++i)
    {
        ofSetColor(i * 20 + 128, i * 80, i * 10 + 60);
        ofDrawRectangle(100, i * 30 + 200, voicePlayer[i].getVolume() * 300, 5);
        
        ofSetColor(i * 40, i * 80, i * 5 + 120);
        ofDrawRectangle(10, i * 20 + 600, voicePlayer[i].getSpeed() * 500, 15);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if(key >= '1' && key <= '6')
    {
        playing[key - '1'] = !playing[key - '1'];
        voicePlayer[key - '1'].setPaused(playing[key - '1']);
    }
    
    else if (key >= 'q')
    {
        voicePlayer[0].setSpeed(voicePlayer[0].getSpeed() + 0.1f);
    }
    
    
    else if (key == 'a')
    {
        voicePlayer[0].setSpeed(voicePlayer[0].getSpeed() - 0.1f);
    }
}

