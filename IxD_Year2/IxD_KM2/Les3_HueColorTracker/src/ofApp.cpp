#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    grabber.setup(GRABBER_WIDTH, GRABBER_HEIGHT);
    
    rgbImage.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
    hsvImage.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
    hueImage.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
    satImage.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
    valImage.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
    filtered.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);

}

//--------------------------------------------------------------
void ofApp::update()
{
    grabber.update();
    
    if(grabber.isFrameNew())
    {
        rgbImage.setFromPixels(grabber.getPixels());
        rgbImage.mirror(false, true);
        
        hsvImage = rgbImage;
        hsvImage.convertRgbToHsv();
        hsvImage.convertToGrayscalePlanarImages(hueImage, satImage, valImage);
        
        for(int i = 0; i < GRABBER_WIDTH * GRABBER_HEIGHT; i++)
        {
            if(ofInRange(hueImage.getPixels()[i], selectedColour - HUE_MARGIN, selectedColour + HUE_MARGIN))
            {
                filtered.getPixels()[i] = 255;
            }
            else
            {
                filtered.getPixels()[i] = 0;
            }
        }
        
        filtered.flagImageChanged();
        
    }
    
    contours.findContours(filtered, 50, GRABBER_WIDTH*GRABBER_HEIGHT/2, 1, false); // 1 stands for one object(blobs)
}

//--------------------------------------------------------------
void ofApp::draw()
{
    rgbImage.draw(0,0, ofGetWidth(), ofGetHeight());
    
    hsvImage.draw(0,0);
    hueImage.draw(0,GRABBER_HEIGHT);                //
    valImage.draw(GRABBER_WIDTH,GRABBER_HEIGHT);    // Value image, black and white
    satImage.draw(GRABBER_WIDTH * 2,GRABBER_HEIGHT);// Saturation?
    filtered.draw(0, GRABBER_HEIGHT);
    
    contours.draw(0,0, ofGetWidth(), ofGetHeight());
    
    ofSetColor(ofColor::red, 100);
    for(int i = 0; i < contours.blobs.size(); i++)
    {
        ofDrawCircle(contours.blobs[i].centroid.x * ofGetWidth()/GRABBER_WIDTH, contours.blobs[i].centroid.y * ofGetHeight()/GRABBER_HEIGHT, 20); //Centroid is to find the center (bounding box)
    }
    ofSetColor(ofColor::white);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    selectedColour = hueImage.getPixels()[y * GRABBER_WIDTH + x]; // Going trough lines of pixels to find the right spot
    cout << "Selected:" << selectedColour << endl;
    
}

