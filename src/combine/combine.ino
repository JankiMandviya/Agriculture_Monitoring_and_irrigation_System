#define BLYNK_TEMPLATE_ID "TMPL0V3dtmm5"                       //copy from server
#define BLYNK_DEVICE_NAME "Agriculture and Irrigation system"  //copy from server
#define BLYNK_AUTH_TOKEN "qJSUzdH0WAAWlzzstmLNgmnbhTv3caSz"    //copy from server

#define DHTTYPE DHT11  //configure dht type module

#include <ESP8266WiFi.h>  // node library

#include <DHT.h>                 //dht library
#include <BlynkSimpleEsp8266.h>  //blynk library

#define DHTPIN D2   //  data  pin  of  module to digital pin  of node in d2
#define SOILPIN A0  //soil moisture pin in analog  pin of a0
#define RAINPIN D6  //output pin of rain sensor connected to d6 of node
#define PUMPPIN D1 //pump pin connected to  digital pin D1 of  node
float moisturepercentage;

int presentstate = 0;  //checks the present data of  soil moisture

char auth[] = BLYNK_AUTH_TOKEN;         // declare one character
char ssid[] = "Jalsa Karone Jentilal";  //declare  character variable called as ssid for wifi name
char pass[] = "qwertyuiop";             // declare character variable for wifi password

int rainval = 0;  // define a variable val initial value of 0 of rain sensor

//dht part
DHT dht = DHT(DHTPIN, DHTTYPE, 6);  //declare object of dht library

void airdata()  //declare void function called as airdata
{

  float t = dht.readTemperature();  // temerature data get and  store in t variable
  float h = dht.readHumidity();     //humidity data get and store in h variable
  if (isnan(t) || isnan(h))         // if data is not come then condition gets true  otherwise if data  is  obtained then go to else part
  {
    Serial.println("fail to get the  data from DHT11");
    return;
  }

  Blynk.virtualWrite(V1, t);  //v1 for temperature and  value of t given to v1
  Blynk.virtualWrite(V2, h);  //v2 for humidity given to v2
  Serial.print("humidity:");
  Serial.println(h, 1);
  Serial.print("temperature(celcius):");
  Serial.println(t, 1);
}  // ending the airdata  dht function


void raindata() {

  //rain part

  rainval = digitalRead(RAINPIN);  // read the analog value to the variable rainval
  if (rainval == 1)                //if analog value is greater than the 700 then it shows the notification

  {

    Serial.println(" it is raining");
    Blynk.logEvent("rain_alert", "raining outside");  //event name and  notification message as raining outside

  } else  //if rainval==0 it means if it  is not raining then go  in this condition

  {
    Serial.println(" it is not raining");
  }

  Blynk.virtualWrite(V3, rainval);  // virtual pin of dashborad as V3
  Serial.println(rainval);          // Serial print variable data //print the rainval value i serial monitor

}  //ending the rain function


void soilmoisturefunc() {


  //soil moisture part

  presentstate = analogRead(SOILPIN);
  moisturepercentage = (100.0 - ((presentstate / 1024.0) * 100.0));
  Blynk.virtualWrite(V4, moisturepercentage);
  Serial.print("moisture of soil(percentage):");

  Serial.println(moisturepercentage, 2);  //2 means shows the decimal  point upto 2


  //1 means soil is dry and 0 means soil is moist enough
  if (moisturepercentage < 40)  //if it is greater than 500 level of moisture then it needs water
  {
    if (rainval == 0)  //when it is not raining the pump gets turn off

    {
      pinMode(D1,OUTPUT);   
digitalWrite(D1,LOW);
Serial.println("relay is on");
     // digitalWrite(PUMPPIN, HIGH);  //pump led turn on connected to anode
      Serial.println(" water pump is on");
      Blynk.logEvent("pump_alert", "farm is being watered");  //event code= pump_alert and  notification message= farm is being  watered
    }

    else {
      pinMode(D1,INPUT); 
digitalWrite(D1,HIGH);
Serial.println("relay is OFF");
      //digitalWrite(PUMPPIN, LOW);  //pump gets turn off when soil moisture level is greater than 40
      Serial.println("water pump is off");
      Blynk.logEvent("off_alert","water pump is off");  //event code for pump off= off alert
    }

    Serial.println("need water");
  }

  else {
     pinMode(D1,INPUT); 
digitalWrite(D1,HIGH);
Serial.println("relay is OFF");
    //digitalWrite(PUMPPIN, LOW);  //PUMP LED TURN OFF
    Serial.println("no need of water ");
  }

}  //ending the soilmoisturefunc


void setup() {
  Serial.begin(9600);
  dht.begin();                    //to start the dht
  Blynk.begin(auth, ssid, pass);  //to  configure the blynk platform
  //pinMode(PUMPLED, OUTPUT);
  pinMode(SOILPIN, OUTPUT);  // data soil pin configure to analog pin  A0 of node
}


void loop() {

  airdata();           //calling the  function of dht parameter
  raindata();          //calling the rain function
  soilmoisturefunc();  //calling the soilmoisturefunction
  delay(5000);
  Blynk.run();  // for keeping connection with blynk like sending data and receiving  data
}
