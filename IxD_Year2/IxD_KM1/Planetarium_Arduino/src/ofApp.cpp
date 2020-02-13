#include "ofApp.h"

#define PIN_LED 12
#define PIN_BUTTON 11
#define PIN_POTMETER 1
//#define PIN_LDR 0

void ofApp::setup()
{
    // set listener - call ofApp::setupArduino when arduino is ready for use
    ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
    
    // connect to the Arduino
    // use the same device name used in the Arduino IDE
    arduino.connect("/dev/cu.usbmodem1411"); //Noa's arduino likes to switch between 1411 and 1421
    arduino.sendFirmwareVersionRequest(); // workaround for ofArduino/firmatabug
    
    ofSetFrameRate(20);
    ofBackground(ofColor:: black);
    
    //===========================
    ofDisableAlphaBlending();
    ofEnableDepthTest();
    light.enable();
    light.setPosition(ofVec3f(0, 0, 0));
    light.lookAt(ofVec3f(0,0,0));
}

void ofApp::update()
{
    arduino.update();
    //ofLog() << "isArduinoReady" << arduino.isArduinoReady() << endl;
    potValue = arduino.getAnalog(1);
    //================================================
    //buttonValue = arduino.getDigital(11);
    
    rotateY += (potValue / 10);
    
    
    // creating offset value for planets
    rotateOffset1 += 0.1;
    rotateOffset2 -= 0.2;
    
    
}

void ofApp::draw()
{
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    gui.draw();
    
    if (doRotate)
    {
        ofRotateYDeg(rotateY);
    }
    
    if (drawGrid)
    {
        ofDrawGrid(200);
    }
    
    if(useLight)
    {
        ofEnableLighting();
    }
    if(!useLight)
    {
        ofDisableLighting();
    }
    
    
    // Drawing our planets
    ofSetColor(ofColor::yellow);
    ofDrawSphere(0, 0, 0, 80);
    
    ofSetColor(ofColor::indianRed);
    ofDrawSphere(120, 0, rotateOffset1, 20);
    
    ofSetColor(ofColor::seaGreen);
    ofDrawSphere(170, 0, 0, 10);
    
    ofSetColor(ofColor::skyBlue);
    ofDrawSphere(230, 0, rotateOffset2, 15);
    
    //=====================
    if(potValue < 10)
    {
        ofDrawBitmapString("Push R to rotate, G for orientation and L for some light", -60, -200);
    }
    if(potValue > 10 and potValue < 200)
    {
        ofDrawBitmapString("HELLO WORLD", -60, -200);
    }
    
    if(potValue > 200 and potValue < 600)
    {
        ofDrawBitmapString("WHIEEE", -30, 200);
    }
    
    if(potValue > 600 and potValue < 1000)
    {
        ofDrawBitmapString("DIZZY WORLD", -60, -200);
    }
    
    if(potValue > 1000)
    {
        ofDrawBitmapString("PLS STOP", -60, -200);
    }
    
    
}

void ofApp::setupArduino(const int& version)
{
    // remove listener because we don't need it anymore
    ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);
    
    // print firmware name and version to the console
    ofLog() << "Arduino firmware found: " << arduino.getFirmwareName()
    << " v" << arduino.getMajorFirmwareVersion() << "." << arduino.getMinorFirmwareVersion();
    
    arduino.sendDigitalPinMode(PIN_LED, ARD_OUTPUT);
    arduino.sendDigitalPinMode(PIN_BUTTON, ARD_INPUT);
    //arduino.sendAnalogPinReporting(PIN_LDR, ARD_ANALOG);
    arduino.sendAnalogPinReporting(PIN_POTMETER, ARD_ANALOG);  // Geeft value terug
    
    // set listeners for pin events
    ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

void ofApp::digitalPinChanged(const int& pinNum)
{
    // get value with arduino.getDigital(pinNum)
    ofLogNotice() << "Digital Pin " << pinNum << " value: " << arduino.getDigital(pinNum) << endl;
}

void ofApp::analogPinChanged(const int& pinNum)
{
    // get value with arduino.getAnalog(pinNum));
    ofLogNotice() << "Analog Pin " << pinNum << " value: " << arduino.getAnalog(pinNum) << endl;
}


void ofApp::mousePressed(int x, int y, int button)
{
    // switch the LED on
    arduino.sendDigital(PIN_LED, ARD_HIGH);
}

void ofApp::mouseReleased(int x, int y, int button)
{
    // switch the LED off
    arduino.sendDigital(PIN_LED, ARD_LOW);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    //controlling our gui with buttons
    if(key == 'g') drawGrid = !drawGrid;
    
    if(key == 'r') doRotate = !doRotate;
    
    if(key == 'l') useLight = ! useLight;
    
}


