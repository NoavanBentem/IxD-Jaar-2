#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetCircleResolution(50);
    
    font.load("SourceCodePro-Medium.ttf", 64);
    
    //Try & catch zijn er om crashen te voorkomen
    try{
        
    string databasePath = ofToDataPath("huishoudens.db", true);
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
    SQLite::Statement query(*db, "SELECT * FROM huishoudens WHERE year=?");
        
    //binding first query ? to years bound to mouse
    int year = years[yearIndex];
    query.bind(1, year);
    
    while (query.executeStep())
    {
    //NL Visualisation
    ofSetColor(ofColor::orange);
    popNLlerpValue = ofLerp(popNLlerpValue, query.getColumn("hh_total").getDouble(), 0.05);
    ofDrawCircle(100, 100, popNLlerpValue * 5);
        
    ofDrawBitmapString(query.getColumn("hh_total").getDouble(), 100, 700);
    
    /*
    //AU Visualisation
        //lerpvalue and actual value from database
    ofSetColor(ofColor::blue);
    popAUlerpValue = ofLerp(popAUlerpValue, query.getColumn("au").getDouble(), 0.05);
    ofDrawCircle(300, 100, popNLlerpValue * 5);
        
    ofDrawBitmapString(query.getColumn("au").getDouble(), 300, 700);
    
    //ZH Visualisation
    ofSetColor(ofColor::red);
    popZHlerpValue = ofLerp(popZHlerpValue, query.getColumn("zh").getDouble(), 0.05);
    ofDrawCircle(500, 100, popZHlerpValue * 5);
        
    ofDrawBitmapString(query.getColumn("zh").getDouble(), 500, 700);
    */
        
    //Lerping the years in text
    lerpYear = ofLerp(lerpYear, years[yearIndex], 0.1);
    ofSetColor(ofColor::black);
    font.drawString(ofToString((int)lerpYear), 200, 500);
     
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
    
    //wealthIndex = ofMap(y, 0, ofGetWidth(), 0, 5);
}

