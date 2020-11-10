#include "Ubidots.h"
const char* UBIDOTS_TOKEN = "BBFF-S8JXMYiPqcAGSZjM4eldw7m2LEvQ0s";  // Put here your Ubidots TOKEN
const char* WIFI_SSID = "realme 5";      // Put here your Wi-Fi SSID
const char* WIFI_PASS = "12345678";      // Put here your Wi-Fi password
Ubidots ubidots(UBIDOTS_TOKEN, UBI_TCP);

int value;
void setup() {
  Serial.begin(9600);
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
  pinMode(A0,INPUT);
  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN,HIGH);
  // put your setup code here, to run once:

}
 // ubidots.setDebug(true);  // Uncomment this line for printing debug messages
void loop() {

  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // read all the available characters
     String content = "";
  char character;

  while(Serial.available()) {
      character = Serial.read();
      content.concat(character);
  }
    //delay(50);
    Serial.println(content.substring(0));
    
    int n=content.length();
    Serial.println(n);
    char* cont = (char*)malloc(sizeof(char) * 11);
  content.substring(0,11).toCharArray(cont,++n);
  Serial.print("cont:");
  Serial.println(cont);
  if (content != "") 
  {
   // Serial.println(content.substring(0,11));
    delay(50);
    //Serial.println((strcmp(cont,"43 78 6A 38"))==0);
    
    if((strcmp(cont,"4D 74 FF D3"))==0)
  { 
    ubidots.addContext("namey","Ashish RoboCell");
    Serial.println("Ashish RoboCell");
    delay(50);
  }
  else if((strcmp(cont,"43 43 2D 38"))==0)
  {//Serial.println("it Went here");
     ubidots.addContext("namey","Anushka RoboCell");
    delay(50);
  }
  else if((strcmp(cont,"53 1F F3 38"))==0)
  {
    ubidots.addContext("namey","Ashis* RoboCell");
    delay(50);
  }
  else if((strcmp(cont,"43 2C 8E 38"))==0)
  {
    ubidots.addContext("namey","Ayush* RoboCell");
    delay(50);
  }
  else if((strcmp(cont,"43 87 D8 38"))==0)
  {
    ubidots.addContext("namey","Ayush RoboCell");
    delay(50);
  }
  else if((strcmp(cont,"53 2C E2 38"))==0)
  {
    ubidots.addContext("namey","Chitrak RoboCell");
    delay(50);
  }

  else if((strcmp(cont,"43 4D 6B 38"))==0)
  {
    ubidots.addContext("namey","Gaurav RoboCell");
    delay(50);
  }
  else if((strcmp(cont,"43 8E EA 38"))==0)
  {
    ubidots.addContext("namey","Ishan RoboCell");
    delay(50);
  }
  else if((strcmp(cont,"02 28 16 2D"))==0)
  {
    ubidots.addContext("namey","Mounam RoboCell");
    delay(50);
  }
  else if((strcmp(cont,"02 64 87 2D"))==0)
  {
    ubidots.addContext("namey","Naresh RoboCell");
    delay(50);
  }
  else if((strcmp(cont,"02 60 98 2D"))==0)
  {
    ubidots.addContext("namey","Pavani RoboCell");
    delay(50);
  }
  else if((strcmp(cont,"45 AB EE 21"))==0)
  {//Serial.println("it Went here");
     ubidots.addContext("namey","Riddhi RoboCell");
    delay(50);
  }
  else if((strcmp(cont,"45 26 D5 21"))==0)
  {
    ubidots.addContext("namey","Sriman RoboCell");
    delay(50);
  }
  else if((strcmp(cont,"45 20 98 21"))==0)
  {
    ubidots.addContext("namey","Srimantini RoboCell");
    delay(50);
  }
  else if((strcmp(cont,"45 6C 41 21"))==0)
  {
    ubidots.addContext("namey","Subham RoboCell");
    delay(50);
  }
  else if((strcmp(cont,"02 76 D5 2D"))==0)
  {
    ubidots.addContext("namey","Sumit RoboCell");
    delay(50);
  }

  else if((strcmp(cont,"02 2D 8C 2D"))==0)
  {
    ubidots.addContext("namey","Thanooj RoboCell");
    delay(50);
  }
  else if((strcmp(cont,"43 24 16 38"))==0)
  {
    ubidots.addContext("namey","Yash RoboCell");
    delay(50);
  }
  else if((strcmp(cont,"43 33 F3 38"))==0)
  {
    ubidots.addContext("namey","Aashrey RoboCell");
    delay(50);
  }
  else if((strcmp(cont,"02 40 9C 2D"))==0)
  {
    ubidots.addContext("namey","Abhishek RoboCell");
    delay(50);
  }
  else if((strcmp(cont,"02 8E 20 2D"))==0)
  {
    ubidots.addContext("namey","Arindam RoboCell");
    delay(50);
  }
  else if((strcmp(cont,"45 03 90 21"))==0)
  {//Serial.println("it Went here");
     ubidots.addContext("namey","Purnima RoboCell");
    delay(50);
  }
  else if((strcmp(cont,"45 BA BC 21"))==0)
  {
    ubidots.addContext("namey","Pawan RoboCell");
    delay(50);
  }
  else if((strcmp(cont,"45 88 49 21"))==0)
  {
    ubidots.addContext("namey","Swapnil RoboCell");
    delay(50);
  }
  else if((strcmp(cont,"35 DD C1 21"))==0)
  {
    ubidots.addContext("namey","Chitrita RoboCell");
    delay(50);
  }
  else if((strcmp(cont,"02 98 EF 2D"))==0)
  {
    ubidots.addContext("namey","Harsh RoboCell");
    delay(50);
  }

  else if((strcmp(cont,"02 93 25 2D"))==0)
  {
    ubidots.addContext("namey","Saivara RoboCell");
    delay(50);
  }
  else if((strcmp(cont,"02 02 AF 2D"))==0)
  {
    ubidots.addContext("namey","Pradum RoboCell");
    delay(50);
  }
  else if((strcmp(cont,"02 60 22 2D"))==0)
  {
    ubidots.addContext("namey","Rupesh RoboCell");
    delay(50);
  }
  else if((strcmp(cont,"02 13 56 2D"))==0)
  {
    ubidots.addContext("namey","Avinash RoboCell");
    delay(50);
  }
  else if((strcmp(cont,"45 4E 81 21"))==0)
  {
    ubidots.addContext("namey","Roshan RoboCell");
    delay(50);
  }
  
  else
  {
    ubidots.addContext("namey","Not Enrolled");
    delay(50);
  }

  delay(10);
  ubidots.addContext("uid", cont);
  delay(10);
    value=analogRead(A0);
    delay(30);
  char* context = (char*)malloc(sizeof(char) * 60);
  ubidots.getContext(context);
  ubidots.add("Attendence_System", value, context); // Change for your variable name
  
  bool bufferSent = false;
  bufferSent = ubidots.send("nodemcu");  // Will send data to a device label that matches the device Id

  if (bufferSent) {
    // Do something if values were sent proper
    digitalWrite(LED_BUILTIN,LOW);
    delay(200);
    digitalWrite(LED_BUILTIN,HIGH);
    
    Serial.println("Values sent by the device");}
    
    
    
    }
  
   
  }


    
  }
  // put your main code here, to run repeatedly:
