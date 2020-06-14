#include "ofMain.h"
#include "ofxSQLiteCpp.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    void mouseMoved(int x, int y);
    void drawGrid();
    void infoTextExpected();
    void infoTextWanted();
    void queryValueAssignment(string UserData);
    void checkQueryValues();
    void drawingCircles(string queryInput);
    void expectedDraw();
    void wantedDraw();
    void base();
    
    ofxPanel gui;
    
    //void keyPressed(int key);
    //void mouseMoved(int x, int y );
    
    string expected[5] = {"Expected", "Expected/Neutral", "Nautral", "Unexpected/Neutral", "Unexpected"};
    string yesNos[5] = {"Yes", "Yes/Neutral", "Neutral", "No/Neutral", "No"};
    float lerpExpected;
    float lerpYesNo;
    
    string nameExpected;
    string nameWanted;
    string emailExpected;
    string emailWanted;
    string phoneNumberExpected;
    string phoneNumberWanted;
    
    string nameFriendsExpected;
    string nameFriendsWanted;
    string emailFriendsExpected;
    string emailFriendsWanted;
    string phoneNumberFriendsExpected;
    string phoneNumberFriendsWanted;
    
    
    string queryInput;
    
    //Buttons
    ofPoint button;
    int buttonSize = 50;
    int buttonRadius;
    
    int buttonState = 0;
    
    
    
    //circle drawing
    int posX;
    int posY;
    int radius;
    
    int textX;

    
    int spacingY = 7;
    int spacingX = 6;
    
    
    ofPoint yourNameButton;
    
    ofTrueTypeFont font;
    
private:
    SQLite::Database* db;
    //int yesNoIndex;
    
};
