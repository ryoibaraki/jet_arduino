#include <Adafruit_MotorShield.h>

/* 
This is a test sketch for the Adafruit assembled Motor Shield for Arduino v2
It won't work with v1.x motor shields! Only for the v2's with built in PWM
control

For use with the Adafruit Motor Shield v2 
---->  http://www.adafruit.com/products/1438
*/

#include <Wire.h>
#include <Adafruit_MotorShield.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);
// You can also make another motor on port M2
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);
Adafruit_DCMotor *myMotor3 = AFMS.getMotor(3);
int readByte=0; 

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  // Set the speed to start, from 0 (off) to 255 (max speed)
  myMotor1->setSpeed(155);
  myMotor2->setSpeed(155);
  myMotor3->setSpeed(255);
  myMotor1->run(FORWARD);
  myMotor2->run(FORWARD);
  myMotor3->run(FORWARD);
  // turn on motor
  myMotor1->run(RELEASE);
  myMotor2->run(RELEASE);
  myMotor3->run(RELEASE);

  myMotor1->run(BACKWARD);
  myMotor2->run(BACKWARD);
  myMotor3->run(BACKWARD);
   
}

void loop() {
  uint8_t i,j,k,l,val;
  if(Serial.available() > 0){ 
  for (j=0; j<3; j++){  
  val = Serial.read();
  readByte = Serial.read();
  if(readByte==3){
  for (i=0; i<155; i++) {
    myMotor1->run(FORWARD);
    myMotor2->run(FORWARD);
    myMotor1->setSpeed(i); 
    myMotor2->setSpeed(i);
    delay(3);
  }
  delay(10);
  for (i=155; i!=0; i--) {
    myMotor1->run(FORWARD);
    myMotor2->run(FORWARD);
    myMotor1->setSpeed(i); 
    myMotor2->setSpeed(i); 
    delay(3);
  }
    myMotor1->run(BACKWARD);
    myMotor2->run(BACKWARD);
    myMotor1->setSpeed(1); 
    myMotor2->setSpeed(1); 
 delay(500);
  }
   Serial.write(6);
 }
    for (j=0; j<3; j++){
  val = Serial.read();
  readByte = Serial.read();
  if(readByte==3){
  for (i=0; i<155; i++) {
    myMotor1->run(BACKWARD);
    myMotor2->run(BACKWARD);
    myMotor1->setSpeed(i); 
    myMotor2->setSpeed(i);
    delay(3);
  }
  delay(10);
  for (i=155; i!=0; i--) {
    myMotor1->run(BACKWARD);
    myMotor2->run(BACKWARD);
    myMotor1->setSpeed(i); 
    myMotor2->setSpeed(i); 
    delay(3);
  }
    myMotor1->run(FORWARD);
    myMotor2->run(FORWARD);
    myMotor1->setSpeed(5); 
    myMotor2->setSpeed(5); 
 delay(500);
  }
  Serial.write(6);
  }
  }
  }
