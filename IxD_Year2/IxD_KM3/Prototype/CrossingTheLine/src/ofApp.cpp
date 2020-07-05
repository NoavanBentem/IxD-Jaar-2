#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetCircleResolution(50);
    
    font.load("SourceCodePro-Medium.ttf", 10);
    
    //Try & catch zijn er om crashen te voorkomen
    try{
        
        string databasePath = ofToDataPath("UserData_Expectations.db", true);
        db = new SQLite::Database(databasePath);
        
    } catch(const std::exception& e) {
        ofLogError() << e.what() << endl;
    }
    
    //Assingning query results to variables
    queryValueAssignment("Name");
    queryValueAssignment("Email");
    queryValueAssignment("PhoneNumber");
    
    queryValueAssignment("NameFriends");
    queryValueAssignment("EmailFriends");
    queryValueAssignment("PhoneNumberFriends");
    
    radius = 25;
    
    //Button setup
    beefButton.set(ofGetWidth()/2, 660);
    tofuButton.set(ofGetWidth()/2-300, 660);
    cheeseButton.set(ofGetWidth()/2+300, 660);
    radiusButton = 10;
    beefBool = false;
    tofuBool = false;
    cheeseBool = false;
}

//--------------------------------------------------------------
void ofApp::update()
{
    
}

//--------------------------------------------------------------
void ofApp::draw()
{
    
    
    // Drawing background grid
    ofSetColor(ofColor::black);
    drawGrid();
    base();
    
    buttonsDraw();
}
    

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (beefButton.distance(ofPoint(x,y)) < radiusButton) {
        defaultButtons();
        beefBool = true;
    }
    
    if (tofuButton.distance(ofPoint(x,y)) < radiusButton) {
        defaultButtons();
        tofuBool = true;
    }
    
    if (cheeseButton.distance(ofPoint(x,y)) < radiusButton) {
        defaultButtons();
        cheeseBool = true;
    }
}

void ofApp::buttonsDraw(){
    
    if (beefBool)
    {
        //============
        wantedDraw();
        ofFill();
        ofSetColor(ofColor::gray);
    }
    else
    {
        ofNoFill();
        ofSetColor(255);
    }
    ofCircle(beefButton, radiusButton);
    
    if (tofuBool)
    {
        //=============
        expectedDraw();
        ofFill();
        ofSetColor(ofColor::gray);
    }
    else
    {
        ofNoFill();
        ofSetColor(255);
    }
    ofCircle(tofuButton, radiusButton);
    
    if (cheeseBool)
    {
        //=============
        boundaries();
        
        ofFill();
        ofSetColor(ofColor::gray);
    }
    else
    {
        ofNoFill();
        ofSetColor(255);
    }
    ofCircle(cheeseButton, radiusButton);
}

void ofApp::defaultButtons()
{
    beefBool = false;
    tofuBool = false;
    cheeseBool = false;
}

//--------------------------------------------------------------
void ofApp::drawGrid(){
    //Be square for all your friends (I mean it stay home)
    ofSetLineWidth(1);
    //Top line
    ofDrawLine(ofGetWidth()/spacingX, ofGetHeight()/12, ofGetWidth()/spacingX*5, ofGetHeight()/12);
    //Bottom line
    ofDrawLine(ofGetWidth()/spacingX*5, ofGetHeight()/12*11, ofGetWidth()/spacingX, ofGetHeight()/12*11);
    
    //Line/Pos 1
    ofDrawLine(ofGetWidth()/spacingX, ofGetHeight()/12, ofGetWidth()/spacingX, ofGetHeight()/12*11);
    //Line/pos 2
    ofDrawLine(ofGetWidth()/spacingX*2, ofGetHeight()/12, ofGetWidth()/spacingX*2, ofGetHeight()/12*11);
    //Line/pos 4
    ofDrawLine(ofGetWidth()/spacingX*4, ofGetHeight()/12, ofGetWidth()/spacingX*4, ofGetHeight()/12*11);
    //Line/pos 5
    ofDrawLine(ofGetWidth()/spacingX*5, ofGetHeight()/12, ofGetWidth()/spacingX*5, ofGetHeight()/12*11);
    
    // Thé line (3), don't you cross it!
    ofSetLineWidth(3);
    ofDrawLine(ofGetWidth()/spacingX*3, ofGetHeight()/12, ofGetWidth()/spacingX*3, ofGetHeight()/12*11);
}

void ofApp::queryValueAssignment(string UserData){
    try{
        //=============> Query expected
        SQLite::Statement queryExpected(*db, "SELECT * FROM UserDataExpected WHERE UserData=?");
        queryExpected.bind(1, UserData);
        
        while (queryExpected.executeStep()) {
            int grootsteExpected = -1;
            int grootsteIndexExpected = -1;
            string grootsteKolomNaamExpected = "";
            for (int i = 0; i < 5; i++) {
                int value = queryExpected.getColumn(expected[i].c_str()).getInt();
                //ofLog() << "i=" << i << "  column=" << expected[i] << " value=" << value << endl;
                if (value > grootsteExpected) {
                    grootsteExpected = value;
                    grootsteIndexExpected = i;
                    grootsteKolomNaamExpected = expected[i];
                }
            }
        // Assigning values to the userdata variables
            if(UserData == "Name"){
                nameExpected = grootsteKolomNaamExpected;
            }else if(UserData == "Email"){
                emailExpected = grootsteKolomNaamExpected;
            }else if(UserData == "PhoneNumber"){
                phoneNumberExpected = grootsteKolomNaamExpected;
            }else if(UserData == "NameFriends"){
                nameFriendsExpected = grootsteKolomNaamExpected;
            }else if(UserData == "EmailFriends"){
                emailFriendsExpected = grootsteKolomNaamExpected;
            }else if(UserData == "PhoneNumberFriends"){
                phoneNumberFriendsExpected = grootsteKolomNaamExpected;
            }
            
            /*ofLog() << " Grootste expected waarde voor " << UserData << " is " << grootsteExpected << " in kolom " << grootsteKolomNaamExpected << " (kolom #" << grootsteIndexExpected
            << ")" << endl;
             */}
        queryExpected.reset();
    } catch (const std::exception& e) {
        ofLog() << e.what() << endl;
    }
    
    try{
        //=============> Query wanted to give
        SQLite::Statement queryWant(*db, "SELECT * FROM WantedToGive WHERE UserData=?");
        queryWant.bind(1, UserData);
        
        while (queryWant.executeStep()) {
            int grootsteWant = -1;
            int grootsteIndexWant = -1;
            string grootsteKolomNaamWant = "";
            for (int i = 0; i < 5; i++) {
                int value = queryWant.getColumn(yesNos[i].c_str()).getInt();
                //ofLog() << "i=" << i << "  column=" << yesNos[i] << " value=" << value << endl;
                if (value > grootsteWant) {
                    grootsteWant = value;
                    grootsteIndexWant = i;
                    grootsteKolomNaamWant = yesNos[i];
                }
            }
            // Assigning values to the userdata variables
            if(UserData == "Name"){
                nameWanted = grootsteKolomNaamWant;
            }else if(UserData == "Email"){
                emailWanted = grootsteKolomNaamWant;
            }else if(UserData == "PhoneNumber"){
                phoneNumberWanted = grootsteKolomNaamWant;
            }else if(UserData == "NameFriends"){
                nameFriendsWanted = grootsteKolomNaamWant;
            }else if(UserData == "EmailFriends"){
                emailFriendsWanted = grootsteKolomNaamWant;
            }else if(UserData == "PhoneNumberFriends"){
                phoneNumberFriendsWanted = grootsteKolomNaamWant;
            }
            
            /*ofLog() << " Grootste wantedToGive waarde voor " << UserData << " is " << grootsteWant << " in kolom " << grootsteKolomNaamWant << " (kolom #" << grootsteIndexWant
            << ")" << endl;
             */
        }
        queryWant.reset();
    } catch (const std::exception& e) {
        ofLog() << e.what() << endl;
    }
}

void ofApp::checkQueryValues(){
    ofLog() << nameExpected << "<---- NAME EXPECTED";
    ofLog() << emailExpected << "<---- EMAIL EXPECTED";
    ofLog() << phoneNumberExpected << "<---- PHONE EXPECTED";
    ofLog() << nameFriendsExpected << "<---- NAME FRIENDS EXPECTED";
    ofLog() << emailFriendsExpected << "<---- EMAIL FRIENDS EXPECTED";
    ofLog() << phoneNumberFriendsExpected << "<---- PHONE FRIENDS EXPECTED";
    
    ofLog() << nameWanted << "<---- NAME Wanted";
    ofLog() << emailWanted << "<---- EMAIL Wanted";
    ofLog() << phoneNumberWanted << "<---- PHONE Wanted";
    ofLog() << nameFriendsWanted << "<---- NAME FRIENDS Wanted";
    ofLog() << emailFriendsWanted << "<---- EMAIL FRIENDS Wanted";
    ofLog() << phoneNumberFriendsWanted << "<---- PHONE FRIENDS Wanted";
    ofLog() << "===========================================================";
    //*pats oneself on shoulder* Proud of you son
}

void ofApp::drawingCircles(string queryInput){
    if (queryInput == "Expected" or queryInput == "Yes"){
        //ofLog() << "SUCCES"; //I'm on a roll
        posX = ofGetWidth()/spacingX;
    }else if (queryInput == "Expected/Neutral" or queryInput == "Yes/Neutral"){
        posX = ofGetWidth()/spacingX*2;
    }else if (queryInput == "Nautral" or queryInput == "Neutral"){
        posX = ofGetWidth()/2;
    }else if (queryInput == "Unexpected/Neutral" or queryInput == "No/Neutral"){
        posX = ofGetWidth()/spacingX*4;
    }else if (queryInput == "Unexpected" or queryInput == "No"){
        posX = ofGetWidth()/spacingX*5;
    }

    ofDrawCircle(posX, posY, radius);
}

void ofApp::expectedDraw(){
    textX = 30;
    ofFill();
    ofSetColor(ofColor::darkGrey);
    posY = ofGetHeight()/spacingY;
    drawingCircles(queryInput = nameExpected);
    
    posY = ofGetHeight()/spacingY*2;
    drawingCircles(queryInput = nameFriendsExpected);
    
    posY = ofGetHeight()/spacingY*3;
    drawingCircles(queryInput = emailExpected);
    
    posY = ofGetHeight()/spacingY*4;
    drawingCircles(queryInput = emailFriendsExpected);
    
    posY = ofGetHeight()/spacingY*5;
    drawingCircles(queryInput = phoneNumberExpected);
    
    posY = ofGetHeight()/spacingY*6;
    drawingCircles(queryInput = phoneNumberFriendsExpected);
}

void ofApp::wantedDraw(){
    textX = 30;
    ofFill();
    ofSetColor(ofColor::grey);
    posY = ofGetHeight()/spacingY;
    drawingCircles(queryInput = nameWanted);
    
    posY = ofGetHeight()/spacingY*2;
    drawingCircles(queryInput = nameFriendsWanted);
    
    posY = ofGetHeight()/spacingY*3;
    drawingCircles(queryInput = emailWanted);
    
    posY = ofGetHeight()/spacingY*4;
    drawingCircles(queryInput = emailFriendsWanted);
    
    posY = ofGetHeight()/spacingY*5;
    drawingCircles(queryInput = phoneNumberWanted);
    
    posY = ofGetHeight()/spacingY*6;
    drawingCircles(queryInput = phoneNumberFriendsWanted);
}

void ofApp::boundaries(){
    //-----1
    ofFill();
    ofSetColor(ofColor::green);
    posY = ofGetHeight()/spacingY;
    drawingCircles(queryInput = nameExpected);
    
    //----- 2
    //ofNoFill();
    ofSetColor(ofColor::orange);
    posY = ofGetHeight()/spacingY*2;
    drawingCircles(queryInput = nameFriendsExpected);
    
    posY = ofGetHeight()/spacingY*2;
    drawingCircles(queryInput = nameFriendsWanted);
    
    /*
    ofFill();
    ofSetColor(ofColor::darkGrey);
    posY = ofGetHeight()/spacingY*2;
    drawingCircles(queryInput = nameFriendsExpected);
    ofSetColor(ofColor::grey);
    posY = ofGetHeight()/spacingY*2;
    drawingCircles(queryInput = nameFriendsWanted);
     */
    
    //-----3
    ofSetColor(ofColor::green);
    posY = ofGetHeight()/spacingY*3;
    drawingCircles(queryInput = emailWanted);
    
    //-----4
    ofSetColor(ofColor::darkRed);
    posY = ofGetHeight()/spacingY*4;
    drawingCircles(queryInput = emailFriendsExpected);
    
    posY = ofGetHeight()/spacingY*4;
    drawingCircles(queryInput = emailFriendsWanted);
    
    //-----5
    ofSetColor(ofColor::yellow);
    posY = ofGetHeight()/spacingY*5;
    drawingCircles(queryInput = phoneNumberExpected);
    
    posY = ofGetHeight()/spacingY*5;
    drawingCircles(queryInput = phoneNumberWanted);
    
    //-----6
    ofSetColor(ofColor::red);
    posY = ofGetHeight()/spacingY*6;
    drawingCircles(queryInput = phoneNumberFriendsExpected);
    
    posY = ofGetHeight()/spacingY*6;
    drawingCircles(queryInput = phoneNumberFriendsWanted);
}

void ofApp::base(){
    //Title text
    textX = 40;
    
    //ofSetColor(255);
    //font.drawString("ARE WE CROSSING OUR OWN LINES WHEN IT COMES DOWN TO USERDATA WE SHARE WITH SOCIAL MEDIA?", 100, 10);
    
    //Data input
    ofSetColor(0);
    font.drawString("Yes", ofGetWidth()/spacingX, ofGetHeight()/13);
    font.drawString("Maybe", ofGetWidth()/spacingX*2, ofGetHeight()/13);
    font.drawString("Neutral", ofGetWidth()/spacingX*3, ofGetHeight()/13);
    font.drawString("Probably not", ofGetWidth()/spacingX*4, ofGetHeight()/13);
    font.drawString("No", ofGetWidth()/spacingX*5, ofGetHeight()/13);
    
    //Data names
    textX = 30;
    posY = ofGetHeight()/spacingY;
    ofSetColor(0);
    font.drawString("Your Name", textX, posY);
    
    posY = ofGetHeight()/spacingY*2;
    ofSetColor(0);
    font.drawString("Friends Name", textX, posY);
    
    posY = ofGetHeight()/spacingY*3;
    ofSetColor(0);
    font.drawString("Your Email", textX, posY);
    
    posY = ofGetHeight()/spacingY*4;
    ofSetColor(0);
    font.drawString("Friends Email", textX, posY);
    
    posY = ofGetHeight()/spacingY*5;
    ofSetColor(0);
    font.drawString("Your Phone Number", textX, posY);
    
    posY = ofGetHeight()/spacingY*6;
    ofSetColor(0);
    font.drawString("Friends Phone Number", textX, posY);
    
    // button text
    textX = 20;
    
    ofSetColor(255);
    font.drawString("WANTED TO SHARE?", 280, 690);
    
    font.drawString("EXPECTED TO SHARE?", 580, 690);
    
    font.drawString("EXPECTATION VS REALITY", 880, 690);
    
}
