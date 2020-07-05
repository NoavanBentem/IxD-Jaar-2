#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
		void mousePressed(int x, int y, int button);
        void buttonsDraw();
        void defaultButtons();

        ofPoint beefButton;
        ofPoint tofuButton;
        ofPoint cheeseButton;
        bool beefBool;
        bool tofuBool;
        bool cheeseBool;
        int radius;
};
