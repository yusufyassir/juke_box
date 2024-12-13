#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 10
#define RST_PIN 3
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

SoftwareSerial mySoftwareSerial(5, 6); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

int songnum;

void setup() {
  // put your setup code here, to run once:
 mySoftwareSerial.begin(9600);
 myDFPlayer.begin(mySoftwareSerial);
 myDFPlayer.volume(25);
 
// myDFPlayer.play(17);
   Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
 
 
}

void loop() {
  // put your main code here, to run repeatedly:
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "83 9A E4 2A") //change here the UID of the card/cards that you want to give access
  {
      myDFPlayer.play(15);
  }
  if (content.substring(1) == "53 21 53 2A")   {
      myDFPlayer.play(10);
  }
    if (content.substring(1) == "B3 2A D7 2A")   {
      myDFPlayer.play(12);
  }
    if (content.substring(1) == "43 53 C7 29")   {
      myDFPlayer.play(13);
  }
    if (content.substring(1) == "F3 27 CF 29")   {
      myDFPlayer.play(14);
  }
    if (content.substring(1) == "C3 64 1B AD")   {
      myDFPlayer.play(11);
  }
}
