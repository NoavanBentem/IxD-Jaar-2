#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);

    // set the background to black for max contrast
    ofBackground(0);
    
    const int NUM_PARTICLES = 1;
    
    
    clicked = false;
    
    
    serial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
    
    int baud = 9600;
    serial.setup(0, 9600);
}

//--------------------------------------------------------------
void ofApp::update(){
    if (clicked){
        unsigned char bytesReturned[30];
        serial.readBytes( bytesReturned, 30);
        memcpy(bytesReadString, bytesReturned, 30);
        
        rArduino = ofToInt(ofToString(bytesReadString[0]) + ofToString(bytesReadString[1]) + ofToString(bytesReadString[2]));
        gArduino = ofToInt(ofToString(bytesReadString[3]) + ofToString(bytesReadString[4]) + ofToString(bytesReadString[5]));
        bArduino = ofToInt(ofToString(bytesReadString[6]) + ofToString(bytesReadString[7]) + ofToString(bytesReadString[8]));
        
        if (rArduino >255){
            rArduino = ofToInt(ofToString(bytesReadString[0]) + ofToString(bytesReadString[1]));
        }
        if (gArduino >255){
            gArduino = ofToInt(ofToString(bytesReadString[3]) + ofToString(bytesReadString[4]));
        }
        if (bArduino >255){
            bArduino = ofToInt(ofToString(bytesReadString[6]) + ofToString(bytesReadString[7]));
        }
        
        
        const int NUM_PARTICLES = 1;
        
        for(int i=0; i<NUM_PARTICLES; i++){
            Particle particle;
            particle.setup();
            particles.push_back(particle);
        }
        clicked = false;
    }
    
    for(int i=0; i<particles.size(); i++){
        particles[i].update();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<particles.size(); i++){
        particles[i].draw();
    }
}

// set up a particle
void Particle::setup(){
    // assign a randomised radius
    // we assume this is 'infinitesimally small' and therefore
    // the ignore the actual radius except for visualising
    radius = 3;
    
    // assign it's starting position
    pos.x = ofRandom(radius, ofGetWidth() - radius);
    pos.y = ofRandom(radius, ofGetHeight() - radius);
    
    // assign it's velocity
    velocity.x = ofRandom(-10, 10);
    velocity.y = ofRandom(-10, 10);
    
    // give it a randomised colour
    colour.r = rArduino;
    colour.g = gArduino;
    colour.b = bArduino;
}

// particles bounce off the edges of the container with no forces
void Particle::update(){
    // update the position using the particles velocity
    pos.x += velocity.x;
    pos.y += velocity.y;
    
    // calculate min and max for both x and y
    // to keep the maths simple, ignore the radius
    float minX = 0;
    float minY = 0;
    float maxX = ofGetWidth();
    float maxY = ofGetHeight();
    
    // need to detect whether the particle has reached the
    // edge of the container by comparing the particles
    // position with one edge at a time. Each time an edge
    // is reached the velocity
    
    ofVec2f reverseX(-1, 1);
    ofVec2f reverseY(1, -1);
    
    // right
    if (pos.x > maxX || pos.x < minX){
        velocity *= reverseX;
    }
    
    if (pos.y > maxY || pos.y < minY){
        velocity *= reverseY;
    }
}

// draw the particle (the easy bit!)
void Particle::draw(){
    ofSetColor(colour);
    ofDrawCircle(pos.x, pos.y, radius);
}

void ofApp::mousePressed(int x, int y, int button){
    clicked = true;
}
