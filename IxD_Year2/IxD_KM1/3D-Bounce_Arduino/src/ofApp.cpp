#include "ofApp.h"

#define PIN_LED 12
#define PIN_BUTTON 11
#define PIN_POTMETER 1
#define PIN_LDR 0

void ofApp::setup()
{
    ofSetFrameRate(30);
    ofBackground(ofColor::black);
    
    // set listener - call ofApp::setupArduino when arduino is ready for use
    ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
    
    // connect to the Arduino
    // use the same device name used in the Arduino IDE
    arduino.connect("/dev/cu.usbmodem1411"); //Noa's arduino likes to switch between 1411 and 1421
    arduino.sendFirmwareVersionRequest(); // workaround for ofArduino/firmata bug
}

void ofApp::update()
{
    arduino.update();
    ldrValue = arduino.getAnalog(0);
    
    rotateX = rotateX + 1;
    //rotateY += 2;
    //rotateZ += 3;
    
    
}

void ofApp::draw()
{
    //ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2); //Centers shit out
    
    if (doRotate)
    {
        //ofRotateXDeg(rotateX);
        ofRotateYDeg(ldrValue);
        //ofRotateZDeg(rotateZ);
    }
    
    if (bounce)
    {
        // X position
        if (posX > 1000 or posX < 25)
        {
            moveRight = !moveRight;
            speed = ofRandom(5, 15);
        }
        
        if (moveRight)
        {
            posX = posX + speed;
        }
        
        if (!moveRight)
        {
            posX = posX - speed;
        }
        // Y position
        if (posY > 720 or posY < 25)
        {
            moveDown = !moveDown;
            speed = ofRandom(5, 15);
        }
        
        if (moveDown)
        {
            posY = posY + speed;
        }
        
        if (!moveDown)
        {
            posY = posY - speed;
        }
        
        // Z position
        if (posZ > 100 or posZ < 1)
        {
            moveDepth = !moveDepth;
            speed = ofRandom(5, 15);
        }
        
        if (moveDepth)
        {
            posZ = posZ + speed;
        }
        
        if (!moveDepth)
        {
            posZ = posZ - speed;
        }
    }
    
    if (drawGrid)
    {
        ofDrawGrid(200);
    }
    
    ofNoFill();
    ofDrawIcoSphere(posX, posY, posZ, 50);
}

void ofApp::keyPressed(int key)
{
    if (key == 'g') {
        drawGrid = !drawGrid;
    }
    
    if (key == 'r') {
        doRotate = !doRotate;
    }
    
    if (key == ' ') {
        bounce = !bounce;
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
    ofSetColor(ofColor::red);
}

void ofApp::mouseReleased(int x, int y, int button) {
    // switch the LED off
    ofNoFill();
    ofDrawIcoSphere(posX, posY, posZ, 50);
    arduino.sendDigital(PIN_LED, ARD_LOW);
}

