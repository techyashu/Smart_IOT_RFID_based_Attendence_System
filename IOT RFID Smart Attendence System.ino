#include <DS3231.h>
#include <SD.h>
#include <SPI.h>
#include <MFRC522.h>
#include<SoftwareSerial.h>//Included SoftwareSerial Library
#include <LiquidCrystal.h>
LiquidCrystal lcd(6, 5, A0, A1, A2, A3);

#define SS_PIN 10
#define RST_PIN 8
#define CS_SD 4
//#define led 7
#define buzzer 7

SoftwareSerial Node(2,3);

DS3231  rtc(SDA, SCL);

MFRC522 mfrc522(SS_PIN, RST_PIN); // Instance of the class

char* cont = (char*)malloc(sizeof(char)*11);

File myFile;

void setup() {
  Serial.begin(9600);
  Node.begin(9600);
  SPI.begin(); // Init SPI bus
  rtc.begin();
  lcd.begin(16,2);
  mfrc522.PCD_Init(); // Init MFRC522
  pinMode(buzzer,OUTPUT);
//  pinMode(led,OUTPUT);
  noTone(buzzer);
  
  lcd.print("Hey ya !! ");
  lcd.setCursor(0, 1);
  lcd.print("#IOT_for_Life");
  delay(2000);
  lcd.clear();
  
  
 if(!SD.begin(CS_SD)) {
    //Serial.println("initialization failed!");
      lcd.clear();
    lcd.print("Insert a Valid");
    lcd.setCursor(0, 1);
    lcd.print("SD Card...");
    return;
  }

  //Serial.print("Initializing SD card...");

 lcd.print("Welcoming You");
  lcd.setCursor(0, 1);
  lcd.print("to ->");
  delay(2000);
  lcd.clear();

 
  
  lcd.print("    ADVANCED");
  lcd.setCursor(0, 1);
  lcd.print("Attendence Systm");
  delay(2000);
  
  lcd.clear();
  lcd.print("Put your Card to");
  lcd.setCursor(0, 1);
  lcd.print("the Reader... <-");
  delay(100);
  
}

void loop() {
  //delay(10);
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent())
    {
     return;
    }
    // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial())
    {
     return;
    }
  //Show UID on serial monitor
  tone(buzzer,500);
 // digitalWrite(led,HIGH);
  String content = "";
  delay(5);
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
   delay(5);
  content.toUpperCase();
  Serial.println();
  Serial.println(content);
  Serial.println(content.substring(1,12));
  delay(200);
  noTone(buzzer);

    int n=content.length();
  (content.substring(1,12)).toCharArray(cont,++n);
  delay(100);
  String Name="";
  delay(5);
   Serial.print("cont:");
   Serial.println(cont);
  lcd.clear();
       delay(100);
  if ((strcmp(cont,"4D 74 FF D3"))==0)
  {
    lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Ashish RoboCell");
    delay(100);
    Name.concat("Ashish RoboCell");
    Serial.println(Name);
    //delay(100);
  }
  else if((strcmp(cont,"43 43 2D 38"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Anushka RoboCell");
    delay(10);
    Name.concat("Anushka RoboCell");
    Serial.println(Name);
  }
  else if((strcmp(cont,"53 1F F3 38"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Ashis* RoboCell");
    delay(10);
    Name.concat("Ashis* RoboCell");
    Serial.println(Name);
  }
  else if((strcmp(cont,"43 2C 8E 38"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Ayush* RoboCell");
    delay(10);
    Name.concat("Ayush* RoboCell");
    Serial.println(Name);
  }else if((strcmp(cont,"43 87 D8 38"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Ayush RoboCell");
    delay(10);
    Name.concat("Ayush RoboCell");
    Serial.println(Name);
  }else if((strcmp(cont,"53 2C E2 38"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Chitrak RoboCell");
    delay(10);
    Name.concat("Chitrak RoboCell");
    Serial.println(Name);
  }
  else if((strcmp(cont,"43 4D 6B 38"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Gaurav RoboCell");
    delay(10);
    Name.concat("Gaurav RoboCell");
    Serial.println(Name);
  }else if((strcmp(cont,"43 8E EA 38"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Ishan RoboCell");
    delay(10);
    Name.concat("Ishan RoboCell");
    Serial.println(Name);
  }
  else if((strcmp(cont,"45 BA BC 21"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Pawan RoboCell");
    delay(10);
    Name.concat("Pawan RoboCell");
    Serial.println(Name);
  }
  else if((strcmp(cont,"35 DD C1 21"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Chitrita RoboCell");
    delay(10);
    Name.concat("Chitrita RoboCell");
    Serial.println(Name);
  }
  
  else if((strcmp(cont,"02 28 16 2D"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Mounam RoboCell");
    delay(10);
    Name.concat("Mounam RoboCell");
    Serial.println(Name);
  }
  
  else if((strcmp(cont,"02 64 87 2D"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Naresh RoboCell");
    delay(10);
    Name.concat("Naresh RoboCell");
    Serial.println(Name);
  }else if((strcmp(cont,"02 60 98 2D"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Pavani RoboCell");
    delay(10);
    Name.concat("Pavani RoboCell");
    Serial.println(Name);
  }
  else if((strcmp(cont,"45 AB EE 21"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Riddhi RoboCell");
    delay(10);
    Name.concat("Riddhi RoboCell");
    Serial.println(Name);
  }
  else if((strcmp(cont,"45 26 D5 21"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Sriman RoboCell");
    delay(10);
    Name.concat("Sriman RoboCell");
    Serial.println(Name);
  }
  
  else if((strcmp(cont,"45 20 98 21"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Srmntni RoboCell");
    delay(10);
    Name.concat("Srimantini RoboCell");
    Serial.println(Name);
  }else if((strcmp(cont,"45 6C 41 21"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Subham RoboCell");
    delay(10);
    Name.concat("Subham RoboCell");
    Serial.println(Name);
  }else if((strcmp(cont,"02 76 D5 2D"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Sumit RoboCell");
    delay(10);
    Name.concat("Sumit RoboCell");
    Serial.println(Name);
  }else if((strcmp(cont,"02 2D 8C 2D"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Thanooj RoboCell");
    delay(10);
    Name.concat("Thanooj RoboCell");
    Serial.println(Name);
  }else if((strcmp(cont,"43 24 16 38"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Yash RoboCell");
    delay(10);
    Name.concat("Yash RoboCell");
    Serial.println(Name);
  }
  else if((strcmp(cont,"43 33 F3 38"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Aashrey RoboCell");
    delay(10);
    Name.concat("Aashrey RoboCell");
    Serial.println(Name);
  }else if((strcmp(cont,"02 40 9C 2D"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Abhishek RoboCell");
    delay(10);
    Name.concat("Abhishek RoboCell");
    Serial.println(Name);
  }else if((strcmp(cont,"02 8E 20 2D"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Arindam RoboCell");
    delay(10);
    Name.concat("Arindam RoboCell");
    Serial.println(Name);
  }else if((strcmp(cont,"45 03 90 21"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Purnima RoboCell");
    delay(10);
    Name.concat("Purnima RoboCell");
    Serial.println(Name);
  }else if((strcmp(cont,"45 88 49 21"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Swapnil RoboCell");
    delay(10);
    Name.concat("Swapnil RoboCell");
    Serial.println(Name);
  }else if((strcmp(cont,"35 DD C1 21"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Chitrita RoboCell");
    delay(10);
    Name.concat("Chitrita RoboCell");
    Serial.println(Name);
  }else if((strcmp(cont,"02 98 EF 2D"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Harsh RoboCell");
    delay(10);
    Name.concat("Harsh RoboCell");
    Serial.println(Name);
  }
  else if((strcmp(cont,"02 93 25 2D"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Saivara RoboCell");
    delay(10);
    Name.concat("Saivara RoboCell");
    Serial.println(Name);
  }else if((strcmp(cont,"02 02 AF 2D"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Pradum RoboCell");
    delay(10);
    Name.concat("Pradum RoboCell");
    Serial.println(Name);
  }else if((strcmp(cont,"02 60 22 2D"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Rupesh RoboCell");
    delay(10);
    Name.concat("Rupesh RoboCell");
    Serial.println(Name);
  }else if((strcmp(cont,"02 13 56 2D"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Avinash RoboCell");
    delay(10);
    Name.concat("Avinash RoboCell");
    Serial.println(Name);
  }else if((strcmp(cont,"45 4E 81 21"))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("Roshan RoboCell");
    delay(10);
    Name.concat("Roshan RoboCell");
    Serial.println(Name);
  }

  
  else if((strcmp(cont,""))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("");
    delay(10);
    Name.concat("");
    Serial.println(Name);
  }else if((strcmp(cont,""))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("");
    delay(10);
    Name.concat("");
    Serial.println(Name);
  }else if((strcmp(cont,""))==0)
  {
     lcd.print("You're Welcome");
    lcd.setCursor(0,1);
    lcd.print("");
    delay(10);
    Name.concat("");
    Serial.println(Name);
  }
  else
  {
    lcd.print("You're Not");
    lcd.setCursor(0,1);
    lcd.print("Not Enrolled");
    delay(10);
    Name.concat("Not Enrolled");
    Serial.println(Name);
  }
  delay(10);
  //SD
  digitalWrite(CS_SD,LOW);
  delay(50);
  myFile=SD.open("NEWDATA.txt", FILE_WRITE);
  delay(100);
  if(!myFile)
  {
    Serial.println("Error");
    lcd.print("Error");
  }
  myFile.print(Name);
  myFile.print(", ");
  delay(100);
  myFile.print(cont);
  delay(100);
  myFile.print(", ");
  myFile.print(rtc.getTimeStr());
  delay(100);
  myFile.print(", ");
  myFile.print(rtc.getDateStr());
  delay(100);
  myFile.print(", ");
  myFile.print(rtc.getDOWStr());
  delay(100);
  myFile.println(" ");
  delay(100);
  myFile.close();


  digitalWrite(CS_SD,HIGH);
  
   delay(500);
  Node.print(cont);
  delay(2000);
  lcd.clear();
  lcd.print("Put your Card to");
  lcd.setCursor(0, 1);
  lcd.print("the Reader... <-");
  delay(100);

}
