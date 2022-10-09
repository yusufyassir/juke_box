#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(2, 3); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

int songnum;

void setup() {
  // put your setup code here, to run once:
 mySoftwareSerial.begin(9600);
 myDFPlayer.begin(mySoftwareSerial);
 myDFPlayer.volume(25);
 
// myDFPlayer.play(17);
 Serial.begin(19200);
 
 
}

void loop() {
  // put your main code here, to run repeatedly:
  songnum = Serial.parseInt();
  Serial.println(songnum);
  if (songnum == 24){
        myDFPlayer.play(24);
  }
  else if (songnum == 6){
        myDFPlayer.play(6);                
  }
}
