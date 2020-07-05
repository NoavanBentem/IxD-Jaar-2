#include "ofMain.h"
#include "ofxSQLiteCpp.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    void buttonsDraw();
    void defaultButtons();
    
    void drawGrid();
    void infoTextExpected();
    void infoTextWanted();
    void queryValueAssignment(string UserData);
    void checkQueryValues();
    void drawingCircles(string queryInput);
    void expectedDraw();
    void wantedDraw();
    void boundaries();
    void base();
    
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
    ofPoint beefButton;
    ofPoint tofuButton;
    ofPoint cheeseButton;
    bool beefBool;
    bool tofuBool;
    bool cheeseBool;
    int radiusButton;
    
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
