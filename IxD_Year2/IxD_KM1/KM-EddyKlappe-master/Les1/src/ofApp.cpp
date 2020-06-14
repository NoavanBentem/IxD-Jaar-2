#include "ofApp.h"

#define PIN_LED 12
#define PIN_POTMETER 1

void ofApp::setup(){
    ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
    arduino.connect("/dev/cu.usbmodem1421 (Arduino/Genuino Uno)");
    arduino.sendFirmwareVersionRequest();
    
    x = ofRandom (0, ofGetWidth());
    y = ofRandom (0, ofGetHeight());
    
    speedX = ofRandom (-10,10);
    speedY = ofRandom (-10, 10);
    
    radius = 50;
    
    color = ofColor::olive;
}

void ofApp::update(){
    arduino.update();
    
    if (x<0){
        speedX = -speedX;
    }
    if (x>ofGetWidth()){
        speedX = -speedX;
    }
    
    if (y<0){
        speedY = -speedY;
    }
    if (y>ofGetHeight()){
        speedY = -speedY;
        arduino.sendDigital(PIN_LED, ARD_HIGH);
    }
    x += speedX;
    y += speedY;
}

void ofApp::draw(){
    ofSetColor(color);
    ofDrawCircle(x, y, radius);
}

void ofApp::setupArduino(const int& version){
    ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);
    
    ofLog() << "Arduino firmware found " << arduino.getMajorFirmwareVersion() << endl;
    
    arduino.sendDigitalPinMode(PIN_LED, ARD_OUTPUT);
    arduino.sendAnalogPinReporting(PIN_POTMETER, ARD_ANALOG);
    
    ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

void ofApp::digitalPinChanged(const int& pinNum){
    ofLog() << "Digital pin " << pinNum << " value: "
    << arduino.getDigital(pinNum) << endl;
}

void ofApp::analogPinChanged(const int& pinNum){
    ofLog() << "Analog pin " << pinNum << " value: "
    << arduino.getAnalog(pinNum) << endl;
}

void ofApp::mousePressed(int x, int y, int button) {
    // switch the LED on
    arduino.sendDigital(PIN_LED, ARD_HIGH);
}

void ofApp::mouseReleased(int x, int y, int button) {
    // switch the LED off
    arduino.sendDigital(PIN_LED, ARD_LOW);
}
