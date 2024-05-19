 //rain sensor 
 
#define BLYNK_TEMPLATE_ID "TMPL0V3dtmm5"

#define BLYNK_DEVICE_NAME "Agriculture and Irrigation system"
#define BLYNK_AUTH_TOKEN "qJSUzdH0WAAWlzzstmLNgmnbhTv3caSz"

#include<ESP8266WiFi.h> //nodemcu library
#include<BlynkSimpleEsp8266.h> //blynk library
char auth[]= BLYNK_AUTH_TOKEN; // declare one character
char ssid[]="Jalsa Karone Jentilal"; //declare  character variable called as ssid for wifi name
char pass[]="qwertyuiop";// declare character variable for wifi password
int analogPin = 0; // output pin  of rain sensor connected to analog pin A0
int rainval = 0; // define a variable rainval initial value of 0 


void setup ()
{

Serial.begin (9600); // set the baud rate to 9600
Blynk.begin(auth,ssid,pass); 

}

void loop ()
{
 

 Serial.println("pushti");
 
rainval = analogRead (analogPin); // read the analog value to the variable rainval
if (rainval> 700)  //if analog value is greater than the 700 then it shows the notification

{
  
Serial.println(" it is raining"); 
Blynk.logEvent("rain_alert","raining outside"); //event name and  notification message as raining outside

}
else 
{
Serial.println(" it is not raining");
}

Blynk.virtualWrite(V3,rainval);// virtual pin of dashborad as V3
Serial.println (rainval); // Serial print variable data //print the rainval value i serial monitor
Blynk.run(); // for keeping connection with blynk like sending data and receiving  data
delay (5000); //delay  between  2 samples 

}