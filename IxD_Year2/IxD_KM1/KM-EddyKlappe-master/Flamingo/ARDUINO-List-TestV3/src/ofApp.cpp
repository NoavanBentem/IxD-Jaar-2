#include "ofApp.h"
#include "ofEvents.h"

void ofApp::setup(){
    
    // Verbinding maken met arduino
    serial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
    
    int baud = 9600;
    serial.setup(0, 9600);
    
    ofBackground(0);

    const int NUM_PARTICLES = 1;

    clicked = false;
}

void ofApp::update(){
    if (clicked){
        // Haalt gelezen code van de Arduino op
        unsigned char bytesReturned[30];
        serial.readBytes( bytesReturned, 30);
        memcpy(bytesReadString, bytesReturned, 30);
        
        // Zet de bytes om naar 3 cijferige codes voor rgb waarde
        // codes worden geplaatst in variabele
        rArduino = ofToInt(ofToString(bytesReadString[0]) + ofToString(bytesReadString[1]) + ofToString(bytesReadString[2]));
        gArduino = ofToInt(ofToString(bytesReadString[3]) + ofToString(bytesReadString[4]) + ofToString(bytesReadString[5]));
        bArduino = ofToInt(ofToString(bytesReadString[6]) + ofToString(bytesReadString[7]) + ofToString(bytesReadString[8]));
        
        // Als de code meer dan 255 is wordt de laatste cijfer er af gehaald
        // dit voorkomt dat alle unieke codes en voledig witte bal laten zien
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
        
        // hier wordt de unieke bal in de list gezet
        for(int i=0; i<NUM_PARTICLES; i++){
            Particle particle;
            particle.setup(rArduino, gArduino, bArduino);
            particles.push_back(particle);
        }
        clicked = false;
    }
    
    for(int i=0; i<particles.size(); i++){
        particles[i].update();
    }
    
}

void ofApp::draw(){
    for(int i=0; i<particles.size(); i++){
        particles[i].draw();
    }
    
    // zet de tekst onder aan de pagina
    ofSetColor(255);
    ofDrawBitmapString("Data. Used for good.", 20, ofGetHeight() - 65);
    ofDrawBitmapString("Want to learn more? Go to flamingo.com", 20, ofGetHeight() - 50);
    ofDrawBitmapString("#FLAMINGO", 20, ofGetHeight() - 20);

}

// Hier wordt de bal aangemaakt
void Particle::setup(int rArduino, int gArduino, int bArduino){
    // grote van de bal
    radius = 6;
    
    // bepaald de begin positie
    pos.x = ofRandom(radius, ofGetWidth() - radius);
    pos.y = ofRandom(radius, ofGetHeight() - radius);
    
    // Bepaald welke kant de bal opgaat en met welke snelheid
    velocity.x = ofRandom(-5, 5);
    velocity.y = ofRandom(-5, 5);
    
    // geeft de bal de eerder berekende unieke kleurcode
    colour.r = rArduino;
    colour.g = gArduino;
    colour.b = bArduino;
}

// ballen bouncen tegen de zijkanten
void Particle::update(){
    // update de positie
    pos.x += velocity.x;
    pos.y += velocity.y;
    
    // berkend de min en max voor x en y
    float minX = 0;
    float minY = 0;
    float maxX = ofGetWidth();
    float maxY = ofGetHeight();
    
    // Berekend of de bal de zijkant raakt
    ofVec2f reverseX(-1, 1);
    ofVec2f reverseY(1, -1);
    
    if (pos.x > maxX || pos.x < minX){
        velocity *= reverseX;
    }
    if (pos.y > maxY || pos.y < minY){
        velocity *= reverseY;
    }
}

// tekent de ballen op het scherm
void Particle::draw(){
    ofSetColor(colour);
    ofDrawCircle(pos.x, pos.y, radius);
}

// stuurt gelezen code van Arduino naar openFrameworkss
void ofApp::mousePressed(int x, int y, int button){
    clicked = true;
}
