#include "heltec.h"
#define BAND    915E6 

int counter = 0;

void setup() {
  
  Heltec.begin(true, true, true, true, BAND);

  
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);
  LoRa.beginPacket();
  LoRa.setTxPower(14,RF_PACONFIG_PASELECT_PABOOST);
  LoRa.print("hello ");
  LoRa.print(counter);
  LoRa.endPacket();
  
  counter++;
  digitalWrite(25, HIGH); 
  delay(1000);                       
  digitalWrite(25, LOW);   
  delay(1000);           
}