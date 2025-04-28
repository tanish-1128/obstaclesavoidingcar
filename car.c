#include <AFMotor.h>
#include <Servo.h> 
AF_DCMotor rightBack(1); 
AF_DCMotor rightFront(2); 
AF_DCMotor leftFront(3); 
AF_DCMotor leftBack(4); 
Servo servoLook;
byte trig = 2; 
byte echo = 13;
byte maxDist = 150; // Maximum sensing distance 
byte stopDist = 50; // Minimum distance to stop
byte motorSpeed = 55; // Maximum motor speed
int motorOffset = 10; // Power difference adjustment 
int turnSpeed = 50; // Speed adjustment for turning
void setup() { 
rightBack.setSpeed(motorSpeed); 
rightFront.setSpeed(motorSpeed);
leftFront.setSpeed(motorSpeed + motorOffset); 
leftBack.setSpeed(motorSpeed + motorOffset); 
rightBack.run(RELEASE); 
rightFront.run(RELEASE); 
leftFront.run(RELEASE); 
leftBack.run(RELEASE);
servoLook.attach(10);
pinMode(trig, OUTPUT); 
pinMode(echo, INPUT);
}
int getDistance() {
unsigned long pulseTime; 
int distance; 
digitalWrite(trig, HIGH); 
delayMicroseconds(10); 
digitalWrite(trig, LOW);
pulseTime = pulseIn(echo, HIGH, timeOut); 
distance = (float)pulseTime * 340 / 2 / 10000; 
return distance;
} 
void moveForward() { 
rightBack.run(FORWARD); 
rightFront.run(FORWARD); 
leftFront.run(FORWARD); 
leftBack.run(FORWARD);
}
void stopMove() { 
rightBack.run(RELEASE); 
rightFront.run(RELEASE); 
leftFront.run(RELEASE); 
leftBack.run(RELEASE);
}
int checkDirection() {
int distances[2] = {0, 0}; 
int turnDir = 1; 
servoLook.write(180); 
delay(500);
distances[0] = getDistance(); 
servoLook.write(0); 
delay(1000);
distances[1] = getDistance();
if (distances[0] >= 200 && distances[1] >= 200) turnDir = 0;
else if (distances[0] <= stopDist && distances[1] <= stopDist) turnDir = 1; 
else if (distances[0] >= distances[1]) turnDir = 0;
else turnDir = 2; 
return turnDir;
}
case 0: turnLeft(400); break; 
case 1: turnLeft(700); break; 
case 2: turnRight(400); break;
}
