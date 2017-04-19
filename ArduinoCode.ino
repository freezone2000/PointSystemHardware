#include <SoftwareSerial.h>
//#include <Time.h>
SoftwareSerial RFID = SoftwareSerial(4,5);
int ledGreen = 2;
int ledRed = 3;
int buzzer = 8;
 
char character;
String id;
String oldId = "0";
 
void setup() {
  Serial.begin(9600);
  RFID.begin(9600);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  digitalWrite(ledGreen,LOW);
  digitalWrite(ledRed,HIGH);
  pinMode(buzzer,OUTPUT);
  digitalWrite(buzzer,LOW);
}
  
void loop() {
   
  while(RFID.available()>0)
  {
    character = RFID.read();
    //Serial.println(typeid(character).name);
    id += character;
  }
   //Serial.println("Test ID : " + id);
   if (id.length() > 10) {
    id = id.substring(1,13);
    if (id != oldId){
      Serial.print("New ID: ");
      Serial.print(id);
      Serial.print(" Old ID: ");
      Serial.print(oldId);
      Serial.println();
      oldId = id;
      digitalWrite(ledGreen,HIGH);
      digitalWrite(ledRed,LOW);
      digitalWrite(buzzer,HIGH);
      delay(200);
      digitalWrite(buzzer,LOW);
      delay(800);
      digitalWrite(ledGreen,LOW);
      digitalWrite(ledRed,HIGH);
    }
   }
  
    id = "";
    delay(125);
}
