#define BLYNK_TEMPLATE_ID "TMPL0V3dtmm5"  //copy from server
#define BLYNK_DEVICE_NAME "Agriculture and Irrigation system"
#define BLYNK_AUTH_TOKEN "qJSUzdH0WAAWlzzstmLNgmnbhTv3caSz"//copy from server

#define DHTTYPE DHT11 //configure dht type module
#define DHTPIN D2 //  data  pin  of  module to digital pin  of node in d2
#include<ESP8266WiFi.h> // node library
#include<DHT.h> //dht library
#include <BlynkSimpleEsp8266.h> //blynk library


char auth[]= BLYNK_AUTH_TOKEN; // declare one character
char ssid[]="Jalsa Karone Jentilal"; //declare  character variable called as ssid for wifi name
char pass[]="qwertyuiop";// declare character variable for wifi password


DHT dht(DHTPIN,DHTTYPE); //declare object of dht library
void  airdata() //declare void function called as airdata
{

  float t=dht.readTemperature(); // temerature data get and  store in t variable
  float h=dht.readHumidity(); //humidity data get and store in h variable
if(isnan(t) || isnan(h)) // if data is not come then condition gets true  otherwise if data  is  obtained then go to else part
{

Serial.println("fail to get the  data from DHT11");
return;

}

Blynk.virtualWrite(V1,t); //v1 for temperature and  value of t given to v1 
Blynk.virtualWrite(V2,h);//v2 for humidity given to v2


Serial.print("humidity:");
Serial.println(h);
Serial.print("temperature(celcius):");
Serial.println(t);
}


void setup() {
  // put your setup code here, to run once:

Serial.begin(115200);
pinMode(DHTPIN, INPUT);
//pinMode(DHTPIN,OUTPUT);
dht.begin(); //to start the dht
delay(700);
Blynk.begin(auth,ssid,pass); //to  configure the blynk platform

}

void loop() {
  // put your main code here, to run repeatedly:
delay(3000);
airdata(); //calling the  function


}
