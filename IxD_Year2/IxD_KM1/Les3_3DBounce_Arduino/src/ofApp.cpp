#include "ofApp.h"

#define PIN_POTMETER 1



//--------------------------------------------------------------
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

}

//--------------------------------------------------------------
void ofApp::update()
{
    arduino.update();
    //ofLog() << "isArduinoReady" << arduino.isArduinoReady() << endl;
    potValue = arduino.getAnalog(1);
    //================================================
    //buttonValue = arduino.getDigital(11);
    
    color = potValue/10;
    
    rotateX = rotateX + 1;
    rotateY += 2;
    rotateZ += 3;
    
    z = ofRandom(0, ofGetHeight());
    speedZ = ofRandom(0, 10);
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    
    if (doRotate)
    {
        ofRotateXDeg(rotateX);
        ofRotateYDeg(rotateY);
        ofRotateZDeg(rotateZ);
    }
    
    if (drawGrid)
    {
        ofDrawGrid(200);
    }
    
    if(z > 500){
        z = 500;
        speedZ = -speedZ;
    }
    
    if(z < 0){
        z = 0;
        speedZ = -speedZ;
    }
    
    
    ofSetColor(color,color,color);
    ofDrawSphere(100, 100, z, 50);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if(key == 'g')
    {
        drawGrid = !drawGrid;
    }
    
    if(key == ' ')
    {
        doRotate = !doRotate;
    }
}

void ofApp::setupArduino(const int& version)
{
    // remove listener because we don't need it anymore
    ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);
    
    // print firmware name and version to the console
    ofLog() << "Arduino firmware found: " << arduino.getFirmwareName()
    << " v" << arduino.getMajorFirmwareVersion() << "." << arduino.getMinorFirmwareVersion();
    
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



//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
