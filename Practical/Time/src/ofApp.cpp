#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
    if(ofGetElapsedTimef() > 3){
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

}
// ofThread loopt naast het normale progamma, daardoor kan je 2 dingen tegelijkertijd doen
class Scheduler: public ofThread {
public:
    Scheduler() {
        timer.setPeriodicEvent(1000000000); // this is 1 second in nanoseconds
        startThread();
    }
    
private:
    ofTimer timer;
    void threadedFunction() {
        while(isThreadRunning()) {
            timer.waitNext();
            // Do your thing here. It will run once per second.
        }
    }
};

