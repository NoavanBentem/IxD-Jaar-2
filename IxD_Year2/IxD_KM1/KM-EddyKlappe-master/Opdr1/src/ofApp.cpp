#include "ofApp.h"

#define PIN_LED 12
#define PIN_POTMETER 1

void ofApp::setup() {
    // set listener - call ofApp::setupArduino when arduino is ready for use
    ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
    
    // connect to the Arduino
    // use the same device name used in the Arduino IDE
    arduino.connect("/dev/cu.usbmodem1411");
    arduino.sendFirmwareVersionRequest(); // workaround for ofArduino/firmata bug
   
    x = ofRandom (0, 20);
    y = ofRandom (0, 20);

    
    speedX = ofRandom (-10, 10);
    speedY = ofRandom (-10, 10);

    
    radius = 50;
    
    color = ofColor::olive;
    
    sucessTimeDelta = 2000;

}

void ofApp::update() {
    arduino.update();
    //    ofLog() << "isArduinoReady" << arduino.isArduinoReady() << endl;
    
    if (x<0){
        speedX = -speedX;
        arduino.sendDigital(PIN_LED, ARD_HIGH);
        sucessTimer= ofGetElapsedTimeMillis();
        arduino.sendDigital(PIN_LED, ARD_LOW);
        
    }
    if (x>600){
        speedX = -speedX;
        arduino.sendDigital(PIN_LED, ARD_HIGH);
        sucessTimer= ofGetElapsedTimeMillis();
        arduino.sendDigital(PIN_LED, ARD_LOW);
    }
    
    if (y<0){
        speedY = -speedY;
        arduino.sendDigital(PIN_LED, ARD_HIGH);
        sucessTimer= ofGetElapsedTimeMillis();
        arduino.sendDigital(PIN_LED, ARD_LOW);
    }
    if (y>600){
        speedY = -speedY;
        arduino.sendDigital(PIN_LED, ARD_HIGH);
        sucessTimer= ofGetElapsedTimeMillis();
        arduino.sendDigital(PIN_LED, ARD_LOW);
    }
    
    
    x += speedX;
    y += speedY;
    
}

void ofApp::draw() {

    ofSetColor(color);
    ofDrawSphere(x, y, radius);

}

void ofApp::setupArduino(const int& version) {
    // remove listener because we don't need it anymore
    ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);
    
    // print firmware name and version to the console
    ofLog() << "Arduino firmware found: " << arduino.getFirmwareName()
    << " v" << arduino.getMajorFirmwareVersion() << "." << arduino.getMinorFirmwareVersion();
    
    arduino.sendDigitalPinMode(PIN_LED, ARD_OUTPUT);
    arduino.sendAnalogPinReporting(PIN_POTMETER, ARD_ANALOG);
    
    // set listeners for pin events
    ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

void ofApp::digitalPinChanged(const int& pinNum) {
    // get value with arduino.getDigital(pinNum)
    ofLogNotice() << "Digital Pin " << pinNum << " value: " << arduino.getDigital(pinNum) << endl;
}

void ofApp::analogPinChanged(const int& pinNum) {
    // get value with arduino.getAnalog(pinNum));
    ofLogNotice() << "Analog Pin " << pinNum << " value: " << arduino.getAnalog(pinNum) << endl;
}


void ofApp::mousePressed(int x, int y, int button) {
    // switch the LED on
    arduino.sendDigital(PIN_LED, ARD_HIGH);
}

void ofApp::mouseReleased(int x, int y, int button) {
    // switch the LED off
    arduino.sendDigital(PIN_LED, ARD_LOW);
}
