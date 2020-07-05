#include <MD_TCS230.h>
#include <FreqCount.h>
#include <FastLED.h>

// Pin definitions color sensor
#define  S2_OUT  12
#define  S3_OUT  13
#define  OE_OUT   8    // LOW = ENABLED 
//Note --->  OUT = pin 8

// Pin definition leds
#define ledPinR 2
#define ledPinG 3
#define ledPinB 4

const int buttonPin = 11; 

#define NUM_LEDS 60 
#define PIN 10 
CRGB leds[NUM_LEDS];
#define BRIGHTNESS 40

MD_TCS230  CS(S2_OUT, S3_OUT, OE_OUT);

int buttonState = 0; 
bool red = false;
bool green = false;
bool blue = false;

long randNumber; 

void setup() 
{
  CS.begin();
  
  pinMode(ledPinR, OUTPUT);
  pinMode(ledPinG, OUTPUT);
  pinMode(ledPinB, OUTPUT);

  pinMode(buttonPin, INPUT);

  digitalWrite(ledPinR, LOW);
  digitalWrite(ledPinG, LOW);
  digitalWrite(ledPinB, LOW);

  int fadeAmount = 5;  // Set the amount to fade I usually do 5, 10, 15, 20, 25 etc even up to 255.
  int brightness = 0;
  
  FastLED.addLeds<WS2811, PIN, GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );

  Serial.begin(9600);

  randomSeed(analogRead(0));
  
}

void loop() 
{
  //FadeInOut(0xff, 0x00, 0x80);

  // When there is no bool true pick a bool 
  if (red == false && green == false && blue == false)
  {
    randNumber = random(3);
    Serial.println(randNumber);

    if (randNumber == 0)
    {
      red == true;
      Serial.println("RED TRUE");
    }

    if (randNumber == 1)
    {
      green == true;
      Serial.println("GREEN TRUE");
    }

    if (randNumber == 2)
    {
      blue == true;
      Serial.println("BLUE TRUE");
    }
    else
    {
      red = false;
      green = false;
      blue = false;
    }
    randNumber = 3;
  }

  // Shows right colored led when the bool is true
  if (red == true)
  {
    digitalWrite(ledPinR, HIGH);
    digitalWrite(ledPinG, LOW);
    digitalWrite(ledPinB, LOW);
  }

  if (green == true)
  {
    digitalWrite(ledPinR, LOW);
    digitalWrite(ledPinG, HIGH);
    digitalWrite(ledPinB, LOW);
  }

  if (blue == true)
  {
    digitalWrite(ledPinR, LOW);
    digitalWrite(ledPinG, LOW);
    digitalWrite(ledPinB, HIGH);
  }
  readSensor();
  colorCheck(); 
}

void colorToPick()
{
    randNumber = random(3);
    Serial.println(randNumber);

    if (randNumber == 0)
    {
      red == true;
      Serial.println("RED TRUE");
    }

    if (randNumber == 1)
    {
      green == true;
      Serial.println("GREEN TRUE");
    }

    if (randNumber == 2)
    {
      blue == true;
      Serial.println("BLUE TRUE");
    }
    else
    {
      red = false;
      green = false;
      blue = false;
    }
    randNumber = 3;
}

void readSensor()
{
  static  bool  waiting;
  
  if (!waiting)
  {
    CS.read();
    waiting = true;
  }
  else
  {
    if (CS.available()) 
    {
      colorData  rgb;
      
      CS.getRGB(&rgb);
 
      waiting = false;
    }
  }
}


void colorCheck()
{
  colorData  rgb;
      
  CS.getRGB(&rgb);
  
  if(rgb.value[TCS230_RGB_R] > 200 and red == true)
  {
    FadeInOut(0xff, 0x00, 0x80);
      
    Serial.println("RED");
  }
      
      //                    Checks for green
  if(rgb.value[TCS230_RGB_G] > 200 and red == true)
  {
    
    FadeInOut(0xff, 0x00, 0x80);
    red = false;
      
    Serial.println("GREEN");
  }
      
  //                    Checks for blue
  if(rgb.value[TCS230_RGB_B] > 200 and red == true)
  {
      
    FadeInOut(0xff, 0x00, 0x80);
    green = false;
      
    Serial.println("BLUE");
  }
}





//--------------------------------------------------------
void showStrip() {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   strip.show();
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   FastLED.show();
 #endif
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   strip.setPixelColor(Pixel, strip.Color(red, green, blue));
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H 
   // FastLED
   leds[Pixel].r = red;
   leds[Pixel].g = green;
   leds[Pixel].b = blue;
 #endif
}

void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue); 
  }
  showStrip();
}






void FadeInOut(byte red, byte green, byte blue){
  float r, g, b;
      
  for(int k = 0; k < 256; k=k+1) { 
    r = (k/256.0)*red;
    g = (k/256.0)*green;
    b = (k/256.0)*blue;
    setAll(r,g,b);
    showStrip();
  }
     
  for(int k = 255; k >= 0; k=k-2) {
    r = (k/256.0)*red;
    g = (k/256.0)*green;
    b = (k/256.0)*blue;
    setAll(r,g,b);
    showStrip();
  }
}
void StripStop(byte red, byte green, byte blue)
{
  float r, g, b;
  
  for(int k = 255; k >= 0; k=k-2) 
    {
      r = (k/256.0)*red;
      g = (k/256.0)*green;
      b = (k/256.0)*blue;
      setAll(r,g,b);
      showStrip();
    }
}

