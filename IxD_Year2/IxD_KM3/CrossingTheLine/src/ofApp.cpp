#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetCircleResolution(50);
    
    font.load("SourceCodePro-Medium.ttf", 10);
    
    //Try & catch zijn er om crashen te voorkomen
    try{
        
        string databasePath = ofToDataPath("UserData_Expectations.db", true);
        db = new SQLite::Database(databasePath);
        
    } catch(const std::exception& e) {
        ofLogError() << e.what() << endl;
    }
    
    //Button setup
    yourNameButton.set(ofGetWidth()/12, ofGetHeight()/12);
    radius = 25;
}


//--------------------------------------------------------------
void ofApp::update()
{
    
}

//--------------------------------------------------------------
void ofApp::draw()
{
    //query
    SQLite::Statement queryWant(*db, "SELECT '?' FROM WantedToGive WHERE UserData='?'");
    
    //Assigning ?
    string yesNo = yesNos[yesNoIndex];
    queryWant.bind(1, yesNo);
    queryWant.bind(2, UserData);
    
    //query.getColumn("")
    
    yesNo
    
    //Be square for all your friends (I mean it stay home)
    ofSetColor(ofColor::black);
    ofDrawLine(ofGetWidth()/spacingX, ofGetHeight()/12, ofGetWidth()/spacingX, ofGetHeight()/12*11);
    ofDrawLine(ofGetWidth()/spacingX, ofGetHeight()/12, ofGetWidth()/spacingX*5, ofGetHeight()/12);
    ofDrawLine(ofGetWidth()/spacingX*5, ofGetHeight()/12, ofGetWidth()/spacingX*5, ofGetHeight()/12*11);
    ofDrawLine(ofGetWidth()/spacingX*5, ofGetHeight()/12*11, ofGetWidth()/spacingX, ofGetHeight()/12*11);
    
    // The line, don't you cross it!
    ofDrawLine(ofGetWidth()/2, ofGetHeight()/12, ofGetWidth()/2, ofGetHeight()/12*11);
    
    ofSetColor(ofColor::slateGrey);
    ofDrawLine(ofGetWidth()/spacingX*2, ofGetHeight()/12, ofGetWidth()/spacingX*2, ofGetHeight()/12*11);
    ofDrawLine(ofGetWidth()/spacingX*4, ofGetHeight()/12, ofGetWidth()/spacingX*4, ofGetHeight()/12*11);
    
    //Buttons drawing party
    ofSetColor(ofColor::springGreen);
    ofCircle(yourNameButton, radius);
    
    /*
    //Circles
    font.drawString(ofToString("Your name"), 20, ofGetHeight()/spacingY);
    ofSetColor(ofColor::aqua);
    ofDrawCircle(100, ofGetHeight()/spacingY, 25);
    
    
    ofSetColor(ofColor::seaGreen);
    ofDrawCircle(100, ofGetHeight()/spacingY*2, 25);
    
    ofSetColor(ofColor::lawnGreen);
    ofDrawCircle(100, ofGetHeight()/spacingY*3, 25);
    
    ofSetColor(ofColor::paleGreen);
    ofDrawCircle(100, ofGetHeight()/spacingY*4, 25);
    
    ofSetColor(ofColor::forestGreen);
    ofDrawCircle(100, ofGetHeight()/spacingY*5, 25);
    */
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    if (yourNameButton.distance(ofPoint(x,y)) < radius) {
        //defaultButtons();
        //beefBool = true;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
    //yearIndex = ofMap(x, 0, ofGetWidth(), 0, 1);
    
}

