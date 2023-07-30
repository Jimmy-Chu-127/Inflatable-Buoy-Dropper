#include "heltec.h" 
#include "images.h"
#include <ESP32Servo.h>

#define TURN_TIME 175
#define BAND    915E6  //you can set band here directly,e.g. 868E6,915E6
String rssi = "RSSI --";
String packSize = "--";
String packet ;

Servo servo1;  // create servo object to control a servo
Servo servo2;
Servo servo3;
// twelve servo objects can be created on most boards
int pos = 0;    // variable to store the servo position
bool val = true;
bool val2 = true;

int servo1Pin = 13;
int servo2Pin = 12;
int servo3Pin = 2;
int i = 180;


void logo(){
  Heltec.display->clear();
  Heltec.display->drawXbm(0,5,logo_width,logo_height,logo_bits);
  Heltec.display->display();
}

void LoRaData(){
  Heltec.display->clear();
  Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
  Heltec.display->setFont(ArialMT_Plain_10);
  Heltec.display->drawString(0 , 15 , "Received "+ packSize + " bytes");
  Heltec.display->drawStringMaxWidth(0 , 26 , 128, packet);
  Heltec.display->drawString(0, 0, rssi);  
  Heltec.display->display();
}

void cbk(int packetSize) {
  packet ="";
  packSize = String(packetSize,DEC);
  for (int i = 0; i < packetSize; i++) { packet += (char) LoRa.read(); }
  rssi = "RSSI " + String(LoRa.packetRssi(), DEC) ;
  LoRaData();
}

void setup() { 
   //WIFI Kit series V1 not support Vext control
  Heltec.begin(true /*DisplayEnable Enable*/, true /*Heltec.Heltec.Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);
 
  Heltec.display->init();
  Heltec.display->flipScreenVertically();  
  Heltec.display->setFont(ArialMT_Plain_10);
  logo();
  delay(1500);
  Heltec.display->clear();
  
  Heltec.display->drawString(0, 0, "Heltec.LoRa Initial success!");
  Heltec.display->drawString(0, 10, "Wait for incoming data...");
  Heltec.display->display();
  delay(1000);
  //LoRa.onReceive(cbk);
  LoRa.receive();
  ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
	servo1.setPeriodHertz(50);    // standard 50 hz servo
	servo1.attach(servo1Pin, 500, 2400); // attaches the servo on pin 18 to the servo object
  servo2.setPeriodHertz(50);    // standard 50 hz servo
	servo2.attach(servo2Pin, 500, 2400); // attaches the servo on pin 18 to the servo object
  servo3.setPeriodHertz(50);    // standard 50 hz servo
	servo3.attach(servo3Pin, 500, 2500);
  servo1.write(70);
  servo3.write(0);
  Serial.begin(9600);
}

void loop() {
  int packetSize = LoRa.parsePacket();
 if (packetSize) 
 { 
   if (val2){
    servo1.write(130);
    servo2.write(120);
    delay(1000);
    // servo1.detach();
    // servo2.detach();
    val2 = false;
   }
    int sensorReading = analogRead(36);
    Serial.println(val);
    if (sensorReading < 3000 && (val==true))
    {
		servo3.write(180);    // tell servo to go to position in variable 'pos'
    delay(1000);
    val = false;
	}
  
    }
   }
    
	


