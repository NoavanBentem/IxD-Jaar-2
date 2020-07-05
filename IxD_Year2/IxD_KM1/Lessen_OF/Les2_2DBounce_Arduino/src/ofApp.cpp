#include "ofApp.h"

#define PIN_LED 11
#define PIN_BUTTON 12
#define PIN_POTMETER 1
#define PIN_LDR 0

void ofApp::setup() {
    // set listener - call ofApp::setupArduino when arduino is ready for use
    ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);

    // connect to the Arduino
    // use the same device name used in the Arduino IDE
    arduino.connect("/dev/cu.usbmodem1411");
    arduino.sendFirmwareVersionRequest(); // workaround for ofArduino/firmata bug
    
    
    //==========================BounceSetup
    x = ofRandom(0, ofGetWidth());
    y = ofRandom(0, ofGetHeight());
    
    speedX = ofRandom(-10, 10);
    speedY = ofRandom(-10, 10);
    
    radius = 40;
    color = ofColor::red;
}

void ofApp::update() {
    arduino.update();
//    ofLog() << "isArduinoReady" << arduino.isArduinoReady() << endl;
    state();
    
    
    //=============BounceUpdate
    if (x < 0) {
        x = 0;
        speedX = -speedX;
        touch = !touch;
    }
    
    if (x > ofGetWidth()) {
        x = ofGetWidth();
        speedX = -speedX;
        touch = !touch;
    }
    if (y < 0) {
        y = 0;
        speedY = -speedY;
        touch = !touch;
    }
    
    if (y > ofGetHeight()) {
        y = ofGetHeight();
        speedY = -speedY;
        touch = !touch;
    }
    
    //ofLog(touch);
    ofLog(OF_LOG_NOTICE) << "HEY" << touch;
    
    x += speedX;
    y += speedY;
}

void ofApp::draw() {
    //=================DrawingOneBall
    ofSetColor(color);
    ofDrawCircle(x, y, radius);
}

void ofApp::state(){
    if (touch == 1){
        arduino.sendDigital(PIN_LED, ARD_HIGH);
    } else{
        arduino.sendDigital(PIN_LED, ARD_LOW);
    }
}

void ofApp::setupArduino(const int& version) {
    // remove listener because we don't need it anymore
    ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);

    // print firmware name and version to the console
    ofLog() << "Arduino firmware found: " << arduino.getFirmwareName()
            << " v" << arduino.getMajorFirmwareVersion() << "." << arduino.getMinorFirmwareVersion();

    arduino.sendDigitalPinMode(PIN_LED, ARD_OUTPUT);
    arduino.sendDigitalPinMode(PIN_BUTTON, ARD_INPUT);
    arduino.sendAnalogPinReporting(PIN_LDR, ARD_ANALOG);
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
