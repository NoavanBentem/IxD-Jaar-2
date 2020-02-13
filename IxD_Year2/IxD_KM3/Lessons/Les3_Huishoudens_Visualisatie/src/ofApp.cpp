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
    SQLite::Statement query(*db, "SELECT * FROM huishoudens WHERE jaar=?");
    
    //binding first query ? to years bound to mouse
    int year = years[yearIndex];
    query.bind(1, year);
    
    //Lerping the years in text
    lerpYear = ofLerp(lerpYear, years[yearIndex], 0.1);
    ofSetColor(ofColor::black);
    font.drawString(ofToString((int)lerpYear), 200, 500);
    
    while (query.executeStep())
    {
    
    
    //Huishoudens totaal visualisation
    ofSetColor(ofColor::orange);
    hhTotaalLerpValue = ofLerp(hhTotaalLerpValue, query.getColumn("huishoudens_totaal").getDouble(), 0.1);
    ofDrawCircle(100, 100, hhTotaalLerpValue * 0.01);
    
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{
    yearIndex = ofMap(x, 0, ofGetWidth(), 0, 1);
    
}

