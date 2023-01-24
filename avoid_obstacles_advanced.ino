/* AVOID OBSTACLE (ADVANCED [v2])
This code will use the distance sensor on your robot to avoid crashing into things.
*/

int turnAmount = 250;
int defaultSpeed = 200;

const int RSL = 9;
const int leftMotor_dir = 4;
const int leftMotor_pwr = 5;
const int rightMotor_dir = 2;
const int rightMotor_pwr = 6;
const int NECK = 10;

int leftDist;
int rightDist;
int forwardDist;

#include <Servo.h>
Servo neck;

#define mm 0
#define cm 1
#define in 2
#define ft 3
int distance(int trigger=12, int echo=13, int units = cm) {
  pinMode(trigger, OUTPUT);
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  pinMode(echo, INPUT);
  long rawInput = pulseIn(echo, HIGH);
  if (units == mm) { return round(0.1723 * rawInput); } else {
  if (units == cm) { return round(0.01723 * rawInput); } else {
  if (units == in) { return round(0.006783 * rawInput); } else {
  if (units == ft) { return round(0.00056525 * rawInput); } else {
  return 0; }}}}
}
void drive(int l_value = 0, int r_value = 0) {
  int lNew = l_value;
  int rNew = r_value;
  if (lNew <= 0) {
    lNew = lNew * -1;
    digitalWrite(leftMotor_dir, LOW);
  } else {
    digitalWrite(leftMotor_dir, HIGH);
  }
  if (rNew <= 0) {
    rNew = rNew * -1;
    digitalWrite(rightMotor_dir, LOW);
  } else {
    digitalWrite(rightMotor_dir, HIGH);
  }
  analogWrite(leftMotor_pwr, lNew);
  analogWrite(rightMotor_pwr, rNew);
}

void setup() {
  pinMode(RSL, OUTPUT);
  pinMode(leftMotor_dir, OUTPUT);
  pinMode(leftMotor_pwr, OUTPUT);
  pinMode(rightMotor_dir, OUTPUT);
  pinMode(rightMotor_pwr, OUTPUT);
  neck.attach(NECK);
  neck.write(90);
  drive(0,0);
  delay(2000);
  digitalWrite(RSL, HIGH);
  Serial.begin(115200);
}

void loop() {
  if (distance() < 20) {
    drive(0,0);
    neck.write(0); delay(200);
    rightDist = distance();
    neck.write(180); delay(400);
    leftDist = distance();
    neck.write(90);
    if (rightDist < 30 && leftDist < 30) {
      drive(255, -255);      
      delay(turnAmount);
    } else if (rightDist > leftDist) {
      drive(255, -255);
    } else {
      drive(-255, 255);
    }
    delay(turnAmount);
    drive(0,0);
  } else {
    drive(defaultSpeed, defaultSpeed);
  }
}
