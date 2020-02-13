#pragma once

#include "ofMain.h"
#include "ofxSQLiteCpp.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        ofxPanel gui;
        ofxIntSlider weightSlider;
    
        int yourWeight;
    
    
        ofImage imageBeef; // images for textures
        ofImage imageTofu;
        ofImage imageCheese;
        ofLight light; // creates a light and enables lighting
        ofEasyCam cam; // add mouse controls for camera movement
    
        ofTrueTypeFont fontCloud;
        float fontSize;
    
        ofPoint beefButton;
        ofPoint tofuButton;
        ofPoint cheeseButton;
        bool beefBool;
        bool tofuBool;
        bool cheeseBool;
        int radius;
    
        void defaultButtons();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
        void visual();
    
    private:
        SQLite::Database* db;
};
