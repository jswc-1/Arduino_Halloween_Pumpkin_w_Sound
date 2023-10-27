#include <Arduino.h>
#include "DYPlayerArduino.h"

// Initialise the player, it defaults to using Serial.
DY::Player player;

// Alternatively initialise on another serial port.
// DY::Player player(&Serial2);
//                1      2      3    4      5     6      7     8      9
int intSec[] = {14000, 3500, 14500, 4500, 15500, 3000, 13000, 13000, 12000};
int sensor =2;
int val=0;

void setup() {
  player.begin();
  player.setVolume(15); // 50% Volume
  Serial.begin(9600);
  pinMode(sensor, INPUT); 
}

void loop() {
  val=0;
  val = digitalRead(sensor);

  if (val == HIGH)
  {
    int i; 

    i = random(0,8);
    Serial.println(i+1); 
    Serial.println(intSec[i]); 
    playClip(i+1, intSec[i] );
    
    delay(10);

  }
  
  
  
}




void playClip(int clipNum, int delayCount)
{
  player.playSpecified(clipNum);
  delay(delayCount);
}