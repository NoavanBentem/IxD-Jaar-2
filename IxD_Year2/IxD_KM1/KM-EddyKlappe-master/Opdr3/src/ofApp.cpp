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
    
    ofBackground(ofColor::black);
    
    //gui.setup();
    //gui.add(drawGrid.set("Grid", false));
    //gui.add(useLight.set("Light", true));
    
    light.setDirectional();
    light.setDiffuseColor(ofColor::white);
    light.enable();
    doRotate = false;
}

void ofApp::update() {
    arduino.update();
    //    ofLog() << "isArduinoReady" << arduino.isArduinoReady() << endl;
    
    rotateX += 2;
    rotateY += 2;
    rotateZ += 2;
}

void ofApp::draw() {
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

    if (doRotate){
    //ofRotateXDeg(rotateX);
    ofRotateYDeg(rotateY);
    //ofRotateZDeg(rotateZ);
    }
    
    ofEnableDepthTest();
    
    cam.setVFlip(true);
    
    if (useLight) {
        ofEnableLighting();
    } else {
        ofDisableLighting();
    }
    
    ofSetColor(ofColor::yellow);
    ofDrawSphere(0, 0, 0, 100);
    
    ofSetColor(ofColor::blue);
    ofDrawSphere(200, 0, 0, 50);
    
    if (drawGrid) ofDrawGrid(200);
    
    ofDisableDepthTest();
   
    //Ledje gaat branden als hij 1 keer om de planeet is gegaan.
    if (rotateY == 360){
        rotateY = 0;
        arduino.sendDigital(PIN_LED, ARD_HIGH);
        sucessTimer= ofGetElapsedTimeMillis();
        arduino.sendDigital(PIN_LED, ARD_LOW);
    }
    
    //if (drawGui) {
        //ofDisableLighting();
       // gui.draw();
    //}
}

void ofApp::keyPressed(int key) {
    if (key == 'l') useLight = !useLight;
    if (key == 'g') drawGrid = !drawGrid;
    //if (key == ' ') drawGui = !drawGui;
    if (key == ' ') doRotate = !doRotate;
    
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
