#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetBackgroundColor(ofColor::white);
    ofSetCircleResolution(50);
    
    font.load("SourceCodePro-Medium.ttf", 64);
    
    //Try & catch to prevent crashing
    try{
        
    string databasePath = ofToDataPath("roslingdb.db", true);
    db = new SQLite::Database(databasePath);
        
    } catch(const std::exception& e) {
        ofLogError() << e.what() << endl;
    }
}
    

//--------------------------------------------------------------
void ofApp::update()
{
    
}

//--------------------------------------------------------------
void ofApp::draw()
{
    //query
    SQLite::Statement query(*db, "SELECT * FROM population WHERE year=?");
    
    //binding first query ? to years bound to mouse
    int year = years[yearIndex];
    query.bind(1, year);
    
    while (query.executeStep())
    {
        //NL Visualisation
        ofSetColor(ofColor::aqua);
        popNLlerpValue = ofLerp(popNLlerpValue, query.getColumn("nl").getDouble(), 0.05);       // Lerpvalue and actual value from database
        ofDrawCircle(100, 200, popNLlerpValue * 5);                                             // Drawing circle with database value
        
    
        //AU Visualisation
        ofSetColor(ofColor::skyBlue);
        popAUlerpValue = ofLerp(popAUlerpValue, query.getColumn("au").getDouble(), 0.05);
        ofDrawCircle(450, 200, popNLlerpValue * 5);
    
        //ZH Visualisation
        ofSetColor(ofColor::seaGreen);
        popZHlerpValue = ofLerp(popZHlerpValue, query.getColumn("zh").getDouble(), 0.05);
        ofDrawCircle(900, 200, popZHlerpValue * 5);
        
        // Drawing values in numbers and names
        ofSetColor(ofColor::black);                                             // Set color
        ofDrawBitmapString(query.getColumn("nl").getDouble(), 100, 700);        // Show value of circle in numbers
        font.drawString("NL", 100, 600);                                        // Draw text
        
        ofDrawBitmapString(query.getColumn("au").getDouble(), 450, 700);
        font.drawString("AU", 450, 600);
        
        ofDrawBitmapString(query.getColumn("zh").getDouble(), 900, 700);
        font.drawString("ZH", 900, 600);
                    
        //Lerping the years in text
        lerpYear = ofLerp(lerpYear, years[yearIndex], 0.1);
        ofSetColor(ofColor::black);
        font.drawString(ofToString((int)lerpYear), 400, 500);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{
    yearIndex = ofMap(x, 0, ofGetWidth(), 0, 5);
    
    wealthIndex = ofMap(y, 0, ofGetWidth(), 0, 5);
}

