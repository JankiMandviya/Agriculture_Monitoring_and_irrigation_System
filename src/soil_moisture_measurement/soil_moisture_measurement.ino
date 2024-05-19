
//soil moisture  sensor
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


#define BLYNK_TEMPLATE_ID "TMPL0V3dtmm5"
#define BLYNK_DEVICE_NAME "Agriculture and Irrigation system"
#define BLYNK_AUTH_TOKEN "qJSUzdH0WAAWlzzstmLNgmnbhTv3caSz"//copy from server

#define SOILPIN D6

char ssid[] = "Jalsa Karone Jentilal";
char pass[] = "qwertyuiop";
char auth[] = BLYNK_AUTH_TOKEN;


int presentstate = 0;  //checks the present data of  soil moisture
void setup() {

  pinMode(SOILPIN, INPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  
  Blynk.run();
  presentstate = digitalRead(SOILPIN);
  Blynk.virtualWrite(V4, presentstate);
  Serial.println(presentstate);

  if (presentstate == 1)  //1 means soil is dry and 0 means soil is moist enough
  {
    Serial.println("need water");

  }

  else {

    Serial.println("no need of water ");
  }





  delay(3000);
}
