#pragma once

#include "ofMain.h"
#include "ofxSQLiteCpp.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void mouseMoved(int x, int y );
    
        int years[5] = {1820, 1910, 1945, 1968, 2005};
    
        float hhTotaalLerpValue;
        float hhSingleLerpValue;
        float hhMultipleLerpValue;
        float lerpYear;
    
        ofTrueTypeFont font;
		
    private:
        SQLite::Database* db;
        int yearIndex = 0;
    
};
