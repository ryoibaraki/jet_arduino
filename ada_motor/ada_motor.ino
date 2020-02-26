#include <Wire.h>
#include <Adafruit_MotorShield.h>
int readByte = 0;

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *Motor1 = AFMS.getMotor(1);

void setup() {
  
 AFMS.begin();
  Motor1->setSpeed(150);
  Motor1->run(FORWARD);
  Motor1->run(RELEASE);

 Serial.begin(9600);
 
}

void loop() {
 uint8_t i;
 if (Serial.available() > 0) {
  readByte = Serial.read();
  if(readByte==3){
 for (i=0; i<255; i++) {
  Motor1->run(FORWARD);
  
  Motor1->setSpeed(i);  
 delay(10);
 }
  for (i=255; i!=0 ; i--) {
  Motor1->run(FORWARD);
  
  Motor1->setSpeed(i);  
 delay(10);
 }
  Serial.write(6);
  }
 }
  }
