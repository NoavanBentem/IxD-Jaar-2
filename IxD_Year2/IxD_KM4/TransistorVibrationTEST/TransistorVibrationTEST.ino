#include <Servo.h>
#include "FastLED.h"

Servo servo;
int pos = 0;

#define NUM_LEDS 1 
CRGB leds[NUM_LEDS];
#define PIN 12

int vibr = 3;
int heat = 8;
int led = 13;


int button = 10; 
int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  FastLED.addLeds<WS2811, PIN, GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  
  servo.attach(9);
  servo.write(pos);
  
  pinMode(vibr, OUTPUT);
  digitalWrite(vibr, HIGH);
  
  pinMode(heat, OUTPUT);
  pinMode(led, OUTPUT);

  pinMode(button, INPUT);
}

void loop() {
  //If touch state is activated
  recieveTouch();

  //If sendTouch state is activated
}

void tighten(){
  for(pos = 0; pos < 180; pos += 1){
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(50); // goes from 0 degrees to 180 degrees
  }
}

void loosen(){
  for(pos = 180; pos > 0; pos -= 1){
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30); // goes from 0 degrees to 180 degrees
  }
}
void heartbeat(){
  // heartbeat vibration
  digitalWrite(vibr, LOW);
  delay(60);
  digitalWrite(vibr, HIGH);
  delay(200);
  digitalWrite(vibr, LOW);
  delay(60);
  digitalWrite(vibr, HIGH);
  delay(1200);
}


void startWarmth(){
  // I don't know why, but I think it's because of my transistor. My HIGH/LOW commands are turned around
  digitalWrite(heat, LOW);
  digitalWrite(led, HIGH);
}

void stopWarmth(){
  digitalWrite(heat, HIGH);
  digitalWrite(led, LOW);
}

void recieveTouch(){
  startWarmth();
  delay(3000);
  //Colour of led is determined by user who is sending touch
  leds[0] = CRGB::Green;
  FastLED.show();
  digitalWrite(led, HIGH);
  tighten();
  delay(10000);
  stopWarmth();
  loosen();
  
}
