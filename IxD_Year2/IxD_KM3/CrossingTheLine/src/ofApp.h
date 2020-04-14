#include "ofMain.h"
#include "ofxSQLiteCpp.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    void mouseMoved(int x, int y);
    //void states();
    
    
    //void keyPressed(int key);
    //void mouseMoved(int x, int y );
    
    string yesNos[5] = {"Yes", "YesNeutral", "Neutral", "NoNeutral", "No"};
    char UserData;
    
    int radius;
    float spacingY = 6;
    float spacingX = 6;
    
    
    ofPoint yourNameButton;
    
    ofTrueTypeFont font;
    
private:
    SQLite::Database* db;
    int yesNoIndex;
    
};
