#include "ofApp.h"

// Make yourself a fabulous ice queen with 'a' and get snowed with 's'. If you want to flip sides push 'a'!

//--------------------------------------------------------------
void ofApp::setup()
{
    //grabber.listDevices();                    //Kijkt naar devices die je kan gebruiken
    
    grabber.setDeviceID(0);                                  //Device selection
    grabber.initGrabber(CAM_WIDTH, CAM_HEIGHT);              //Defines screen resolution
    grabber.setDesiredFrameRate(30);
    
    workspace.allocate(CAM_WIDTH, CAM_HEIGHT, OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void ofApp::update()
{
    grabber.update();
    
    if(grabber.isFrameNew())
    {
        ofPixels& pixels = grabber.getPixels();
        for(int y = 0; y < pixels.getHeight(); y++)
        {
            for(int x=0; x < pixels.getWidth(); x++)
            {
                ofColor col = pixels.getColor(x, y);
                
                if(changeColor){
                    col.g = ofRandom(0, 255) - col.b;
                    col.g = ofRandom(0, 255) - col.r;
                    col.b = ofRandom(0, 255) - col.r;
                }
                
                if(snow){
                    col.r = ofRandom(0, 255) - col.b;
                    col.g = ofRandom(0, 255) - col.r;
                    col.b = ofRandom(0, 255) - col.r;
                }
                
                workspace.setColor(x, y, col);
                workspace.setColor(pixels.getWidth() -x, y, col); //Halfmirror X
            }
        }
        image.setFromPixels(workspace);
    
        if(flipVideo){
            image.mirror(false, true);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    //grabber.draw(300, 0);     //Normal cam
    image.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == 'a') changeColor = !changeColor;
    if (key == 's') snow = !snow;
    if (key == 'f') flipVideo = !flipVideo;
    
}


