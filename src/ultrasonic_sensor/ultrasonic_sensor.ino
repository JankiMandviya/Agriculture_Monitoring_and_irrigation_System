
//  #define TRIGPIN  D3
// #define ECHOPIN  D4

// //define sound velocity in cm/uS
// #define SOUND_VELOCITY 0.034
// #define CM_TO_INCH 0.393701

// float duration;
// float distanceCm;
// float distanceInch;

// void setup() {
//   Serial.begin(115200); // Starts the serial communication
//   pinMode(TRIGPIN, OUTPUT); // Sets the trigPin as an Output
//   pinMode(ECHOPIN, INPUT); // Sets the echoPin as an Input
// }

// void loop() {
//   // Clears the trigPin
//   digitalWrite(TRIGPIN, LOW);
//   delayMicroseconds(2);
//   // Sets the trigPin on HIGH state for 10 micro seconds
//   digitalWrite(TRIGPIN, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(TRIGPIN, LOW);
  
//   // Reads the echoPin, returns the sound wave travel time in microseconds
//   duration = pulseIn(ECHOPIN, HIGH);
  
//   // Calculate the distance
//   distanceCm = duration * SOUND_VELOCITY/2;
  
//   // Convert to inches
//   distanceInch = distanceCm * CM_TO_INCH;
  
//   // Prints the distance on the Serial Monitor
//   Serial.print("Distance (cm): ");
//   Serial.println(distanceCm);
//   Serial.print("Distance (inch): ");
//   Serial.println(distanceInch);
  
//   delay(1000);
// }





#include <ESP8266WiFi.h>  // node library
#define TRIGPIN D3  //digital pin  3 of node connected to trig pin of ultrasonic
#define ECHOPIN D4   // digital pin 4 of node connected to  echo pin of ultrasonic



#define PUMPPIN  D1

int empty_tank=10; //10 cm for  empty tank

int full_tank=3;  //15-3= 12cm for full tank


void setup()
{


  pinMode(TRIGPIN,OUTPUT);
   pinMode(ECHOPIN,INPUT);


Serial.begin(9600);

   
 }


 void loop(){

  float  distance, duration;

  /* in ultrasonic sensor we have to set the trig pin high for 10 micro seconds 
   so first we will put trig pin low for 2 micro seconds and then put it high for 10 micro seconds*/

digitalWrite(TRIGPIN,LOW);
delayMicroseconds(2);
digitalWrite(TRIGPIN,HIGH);
delayMicroseconds(10);
digitalWrite(TRIGPIN,LOW);
delayMicroseconds(2);



duration=pulseIn(ECHOPIN,HIGH);  //it means the pulse function will get total duration time of echo pin  


// speed of sound on room temp=343.5 m/s
//speed of temp at room temp=0.03435 cm/microsec

// total distance=total duration*0.03435  this is the total distance of sound wave from going to object and then return back to sensor

// so to find only distance of object from sensor we have to  divide the duration by 2


// distance from sensor to object=(total duration/2)*0.03435



//distance=duration*340/20000;

distance=(duration/2)*0.03435;  //now this is only distance from object to sensor

Serial.println(distance);

// if(distance>=empty_tank )

// {

// digitalWrite(PUMPPIN, HIGH); //PUMP  GETS TURN OFF 


// Serial.println("PUMP  GETS TURN OFF ");


// }

// else {
// digitalWrite(PUMPPIN,LOW);  //pump gets turn on


// Serial.println("PUMP  GETS TURN on ");
// }

 }



 
  