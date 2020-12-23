/*
 * ALAT PENYEMPROT SABUN / HANDZINTIZER OTOMATIS
 * DI BUAT = MUHAMMAD LUTFI AZIZ
 * INDONESIA
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
  servo2.write(150);// tell servo to go to position in variable 'pos'
  delay(100);  
 }
 else
 {
 // Serial.println("Servo Tutup");
  myservo.write(0);              // tell servo to go to position in variable 'pos'
  servo2.write(0);
  delay(5); 
 }
 delay(100);
 }
