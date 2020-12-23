/*
 * ---------------------ALAT PENYEMPROT SABUN / HANDZINTIZER OTOMATIS-----------------
 * DI BUAT = MUHAMMAD LUTFI AZIZ
 * 
 *                            --->PROJECT ANGEL <---
 * YOUTUBE TUTORIAL : https://www.youtube.com/channel/UCbJ5ddQ7PCo74sNRZ7Q48_w
 * GITHUB           : https://github.com/lutfi-aziz/Alat-Pencuci-Sabun-Otomatis
 * 
 * KOMPONEN ALAT:
 * 1 Modul Arduino NANO
 * 2 pcs Servo
 * 1 Sensor Ultrasonic
 * Kabel Jumper
 * 
 */

#include <Servo.h>
#define ECHOPIN 2
#define TRIGPIN 3
int pos = 0;
Servo myservo,servo2;

unsigned int jarak;

void setup(){
Serial.begin(9600);
myservo.attach(9);
servo2.attach(10);
pinMode(ECHOPIN, INPUT);
pinMode(TRIGPIN, OUTPUT);
delay(100);
}
void loop(){
ping();
servo();
}

void ping(){
digitalWrite(TRIGPIN, LOW);
delayMicroseconds(2);
digitalWrite(TRIGPIN, HIGH);
delayMicroseconds(10);
digitalWrite(TRIGPIN, LOW);
distance = pulseIn(ECHOPIN, HIGH);
distance= distance/58;
delay(5);
}

void servo(){
// servo(); 
 if (jarak <= 10 )
 { 
  delay(700);
  myservo.write(150);
  servo2.write(150);
  delay(100);  
 }
 else
 {
 // Serial.println("Servo Tutup");
  myservo.write(0); 
  servo2.write(0);
  delay(5); 
 }
 delay(100);
 }

