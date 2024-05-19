
#include<ESP8266WiFi.h>

#define RELAYPIN D1

void setup() {

Serial.begin(9600);
}

void loop()
 {
pinMode(D1,OUTPUT);   
digitalWrite(D1,LOW);
Serial.println("relay is on");
delay(1000);
 
pinMode(D1,INPUT); 
digitalWrite(D1,HIGH);
Serial.println("relay is OFF");
delay(1000);
}
