// Working colour turning sketch with hexcilia. no local comms
#include <Wire.h>
#include <Servo.h>
#include "Adafruit_TCS34725.h"
//
Servo servo1;  // create servo object to control a servo
Servo servo2;
Servo servo3;
Servo servo4;
byte gammatable[256];
int val;
int digitalout=13;
int inN=8;
int inSE=16;
int inS=17;
int inSW=18;
int inNW=19;
int masterjumper=A0;
int inNE=A1;

#define redpin 3
#define greenpin 5
#define bluepin 6
// for a common anode LED, connect the common pin to +5V
// for common cathode, connect the common to ground
// set to false if using a common cathode LED
#define commonAnode true

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
/////////////////////////////

void setup() {


  
  Serial.begin(9600);
  Serial.println("Color View Test!");
  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1); // halt!
  }
  
  for (int i=0; i<256; i++) {
    float x = i;
    x /= 255;
    x = pow(x, 2.5);
    x *= 255;
      
    if (commonAnode) {
      gammatable[i] = 255 - x;
    } else {
      gammatable[i] = x;      
    }
  }
}

void loop() {

  //startup position
    servo1.attach(3);
    servo2.attach(5); 
    servo3.attach(6);
    delay(50);
    
    servo1.write(0);            // tip return
    delay(100);    
    servo2.write(90);           // middle return
    delay(100);
    servo3.write(90);
    delay(100);
    servo1.detach();
    servo2.detach();
    servo3.detach();
    delay(50);    
     
     
     
  uint16_t clear, red, green, blue;
  tcs.setInterrupt(false);      // turn on LED
  delay(50);  // takes 50ms to read 
  tcs.getRawData(&red, &green, &blue, &clear);
  tcs.setInterrupt(true);  // turn off LED
      

if (clear > 1500){
  servo1.attach(3);
  servo2.attach(5); 
  servo3.attach(6);
 // servo4.attach(9);
      Serial.print("colour detected!  ");
      // Figure out some basic hex code for visualization
      uint32_t sum = clear;
      float r, g, b;
      r = red; r /= sum;
      g = green; g /= sum;
      b = blue; b /= sum;
      r *= 256; g *= 256; b *= 256;
      Serial.print("\t");
      if (r>g && r>b){ Serial.print("\tmostly red\t");
        val = 30;}
      if (g>r && g>b){ Serial.print("\tmostly green\t");
        val = 90;}
      if (b>r && b>g){ Serial.print("\tmostly blue\t");
        val = 170;}  
     Serial.println();
     
 ////// 
    // val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
    // val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
     servo3.write(val);                  // sets the servo position according to the scaled value
     delay(100); 
     Serial.println(val);
     Serial.println("sensor value");
     delay(50);  
     
     
     
     servo1.write(160);            // tip bending
     delay(200);    
     //Serial.println("power stroke");
     servo2.write(150);           // middle stroke
     delay(200);                       
     //Serial.println("tip beinding");
     servo1.write(0);            // tip return
     delay(100);    
     //Serial.println("return stroke");  
     servo2.write(90);           // middle return
     delay(100);   
     //Serial.println("tip return");
  servo1.detach();
  servo2.detach(); 
  servo3.detach();
  delay(50);
  }
}
