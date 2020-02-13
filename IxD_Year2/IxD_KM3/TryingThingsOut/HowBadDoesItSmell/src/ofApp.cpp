#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofBackgroundGradient(ofColor::white, ofColor::gray);
    
    ofSetVerticalSync(true);
    
    gui.setup();
    gui.add(weightSlider.setup("Weight", 30, 3, 150));
    
    // this uses depth information for occlusion
    // rather than always drawing things on top of each other
    ofEnableDepthTest();
    
    // ofBox uses texture coordinates from 0-1, so you can load whatever
    // sized images you want and still use them to texture your box
    // but we have to explicitly normalize our tex coords here
    ofEnableNormalizedTexCoords();
    
    // loads the images from disk
    imageBeef.load("beef.png");
    imageTofu.load("tofu.png");
    imageCheese.load("cheese.png");
    
    
    //Button setup
    beefButton.set(ofGetWidth()/2, 650);
    tofuButton.set(ofGetWidth()/2-100, 650);
    cheeseButton.set(ofGetWidth()/2+100, 650);
    radius = 30;
    beefBool = false;
    tofuBool = false;
    cheeseBool = false;
    
    fontSize = 50;
    fontCloud.load("CLOUDY_FONT.ttf", fontSize);
    
    
    //Try & catch to prevent the crashings
    try{
        
        string databasePath = ofToDataPath("protein_vs_ghg.db", true);
        db = new SQLite::Database(databasePath);
        
    } catch(const std::exception& e) {
        ofLogError() << e.what() << endl;
    }
}

//--------------------------------------------------------------
void ofApp::update()
{
    if (beefBool){
        
    }else{
        //or do sth else
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    gui.draw();
    visual();
}

//--------------------------------------------------------------

void ofApp::defaultButtons()
{
    beefBool = false;
    tofuBool = false;
    cheeseBool = false;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == 'a') {
        ofImage screenshot;
        screenshot.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        screenshot.save("yourChoice.png");
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    if (beefButton.distance(ofPoint(x,y)) < radius) {
        defaultButtons();
        beefBool = true;
    }
    
    if (tofuButton.distance(ofPoint(x,y)) < radius) {
        defaultButtons();
        tofuBool = true;
    }
    
    if (cheeseButton.distance(ofPoint(x,y)) < radius) {
        defaultButtons();
        cheeseBool = true;
    }
}

void ofApp::visual(){
    //query
    SQLite::Statement query(*db, "SELECT Protein, GHG_Emissions FROM Protein_GHG_Emissions where protein = ?");
    
    float boxSize = 10;
    
    //Button actions
    if (beefBool)
    {
        query.bind(1, "Beef(beef_herd)");
        ofFill();
        ofSetColor(ofColor::sandyBrown);
        
        //cam.begin();
        imageBeef.bind();
        ofFill();
        ofSetColor(255);
        ofDrawBox(boxSize*(3.8/2), 600, 500);
        imageBeef.unbind();
        ofNoFill();
        //cam.end();
    }
    else
    {
        ofFill();
        ofSetColor(ofColor::seaGreen);
    }
    ofCircle(beefButton, radius);
    
    if (tofuBool)
    {
        query.bind(1, "Tofu");
        ofFill();
        ofSetColor(ofColor::sandyBrown);
        
        cam.begin();
        imageTofu.bind();
        ofFill();
        ofSetColor(255);
        ofDrawBox(boxSize*(12.5/2));
        imageTofu.unbind();
        ofNoFill();
        cam.end();
    }
    else
    {
        ofFill();
        ofSetColor(ofColor::seaGreen);
    }
    ofCircle(tofuButton, radius);
    
    if (cheeseBool)
    {
        query.bind(1, "Cheese");
        ofFill();
        ofSetColor(ofColor::sandyBrown);
        
        cam.begin();
        imageCheese.bind();
        ofFill();
        ofSetColor(255);
        ofDrawBox(boxSize*(8/2));
        imageCheese.unbind();
        ofNoFill();
        cam.end();
    }
    else
    {
        ofFill();
        ofSetColor(ofColor::seaGreen);
    }
    ofCircle(cheeseButton, radius);
    
    //Drawing GHG Emissions with data from database
    while (query.executeStep())
    {
        ofSetColor(ofColor::black);
        //fontSize = query.getColumn("GHG_Emissions").getDouble();
        fontCloud.drawString(ofToString((int)query.getColumn("GHG_Emissions").getDouble()), ofGetWidth()/2, 150);
    }
}
