#include "heltec.h"

#define BAND    915E6  
void setup() {
  Heltec.begin(true, true, true, true, BAND);

}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    Serial.print("Received packet '");
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
}