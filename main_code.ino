const int RSL = 9;
const int leftMotor_dir = 4;
const int leftMotor_pwr = 5;
const int rightMotor_dir = 2;
const int rightMotor_pwr = 6;
const int L = 8;
const int M = 7;
const int R = 11;
const int NECK = 10;
#define SCL_Pin A5
#define SDA_Pin A4

unsigned char clear[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char smile[] = {0x08, 0x10, 0x20, 0x20, 0x43, 0x43, 0x80, 0x80, 0x80, 0x80, 0x43, 0x43, 0x20, 0x20, 0x10, 0x08};
unsigned char smile_blink[] = {0x08, 0x10, 0x20, 0x20, 0x42, 0x42, 0x80, 0x80, 0x80, 0x80, 0x42, 0x42, 0x20, 0x20, 0x10, 0x08};
unsigned char confused[] = {0x00, 0x00, 0x40, 0x40, 0x43, 0x43, 0x40, 0x40, 0x40, 0x40, 0x43, 0x43, 0x40, 0x40, 0x00, 0x00};
unsigned char confused_blink[] = {0x00, 0x00, 0x40, 0x40, 0x42, 0x42, 0x40, 0x40, 0x40, 0x40, 0x42, 0x42, 0x40, 0x40, 0x00, 0x00};
unsigned char happy[] = {0x00, 0x18, 0x28, 0x28, 0x4b, 0x4b, 0x88, 0x88, 0x88, 0x88, 0x4b, 0x4b, 0x28, 0x28, 0x18, 0x00};
unsigned char happy_blink[] = {0x00, 0x18, 0x28, 0x28, 0x4a, 0x4a, 0x88, 0x88, 0x88, 0x88, 0x4a, 0x4a, 0x28, 0x28, 0x18, 0x00};

#include <Servo.h>

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

#define BLACK 0
#define WHITE 1
int tape(int color = BLACK) {
  if (color == WHITE) {
    if (digitalRead(L) == LOW && digitalRead(M) == HIGH && digitalRead(R) == HIGH) { return -2; } // Tape at far left
    if (digitalRead(L) == LOW && digitalRead(M) == LOW && digitalRead(R) == HIGH) { return -1; } // Tape slightly to left
    if (digitalRead(L) == LOW && digitalRead(M) == LOW && digitalRead(R) == LOW) { return 0; } // Thick tape in center
    if (digitalRead(L) == HIGH && digitalRead(M) == LOW && digitalRead(R) == LOW) { return 1; } // Tape slightly to right
    if (digitalRead(L) == HIGH && digitalRead(M) == HIGH && digitalRead(R) == LOW) { return 2; } // Tape at far right
    if (digitalRead(L) == HIGH && digitalRead(M) == HIGH && digitalRead(R) == HIGH) { return 100; } // No tape
    if (digitalRead(L) == LOW && digitalRead(M) == HIGH && digitalRead(R) == LOW) { return -5; } // Highly unusual situation: Tape on left and right but not center
    if (digitalRead(L) == HIGH && digitalRead(M) == LOW && digitalRead(R) == HIGH) { return 5; } // Thin tape in center
  } else {
    if (digitalRead(L) == HIGH && digitalRead(M) == LOW && digitalRead(R) == LOW) { return -2; } // Tape at far left
    if (digitalRead(L) == HIGH && digitalRead(M) == HIGH && digitalRead(R) == LOW) { return -1; } // Tape slightly to left
    if (digitalRead(L) == HIGH && digitalRead(M) == HIGH && digitalRead(R) == HIGH) { return 0; } // Thick tape in center
    if (digitalRead(L) == LOW && digitalRead(M) == HIGH && digitalRead(R) == HIGH) { return 1; } // Tape slightly to right
    if (digitalRead(L) == LOW && digitalRead(M) == LOW && digitalRead(R) == HIGH) { return 2; } // Tape at far right
    if (digitalRead(L) == LOW && digitalRead(M) == LOW && digitalRead(R) == LOW) { return 100; } // No tape
    if (digitalRead(L) == HIGH && digitalRead(M) == LOW && digitalRead(R) == HIGH) { return -5; } // Highly unusual situation: Tape on left and right but not center
    if (digitalRead(L) == LOW && digitalRead(M) == HIGH && digitalRead(R) == LOW) { return 5; } // Thin tape in center
  }
}

#define mm 0
#define cm 1
#define in 2
#define ft 3
int distance(int trigger, int echo, int units = cm) {
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

void pic(unsigned char matrix_value[]) {
  digitalWrite(SCL_Pin,HIGH);delayMicroseconds(3);digitalWrite(SDA_Pin,HIGH);delayMicroseconds(3);digitalWrite(SDA_Pin,LOW);delayMicroseconds(3);IIC_send(0xc0);for(int i=0;i<16;i++){IIC_send(matrix_value[i]);}digitalWrite(SCL_Pin,LOW);delayMicroseconds(3);digitalWrite(SDA_Pin,LOW);delayMicroseconds(3);digitalWrite(SCL_Pin,HIGH);delayMicroseconds(3);digitalWrite(SDA_Pin,HIGH);delayMicroseconds(3);digitalWrite(SCL_Pin,HIGH);delayMicroseconds(3);digitalWrite(SDA_Pin,HIGH);delayMicroseconds(3);digitalWrite(SDA_Pin,LOW);delayMicroseconds(3);IIC_send(0x8A);digitalWrite(SCL_Pin,LOW);delayMicroseconds(3);digitalWrite(SDA_Pin,LOW);delayMicroseconds(3);digitalWrite(SCL_Pin,HIGH);delayMicroseconds(3);digitalWrite(SDA_Pin,HIGH);delayMicroseconds(3);}void IIC_send(unsigned char send_data){for(char i=0;i<8;i++){digitalWrite(SCL_Pin,LOW);delayMicroseconds(3);if(send_data & 0x01){digitalWrite(SDA_Pin,HIGH);}else{digitalWrite(SDA_Pin,LOW);}delayMicroseconds(3);digitalWrite(SCL_Pin,HIGH);delayMicroseconds(3);send_data=send_data>>1;}
}

Servo neck;

void setup() {
  pinMode(RSL, OUTPUT);
  pinMode(leftMotor_dir, OUTPUT);
  pinMode(leftMotor_pwr, OUTPUT);
  pinMode(rightMotor_dir, OUTPUT);
  pinMode(rightMotor_pwr, OUTPUT);
  pinMode(L, INPUT);
  pinMode(M, INPUT);
  pinMode(R, INPUT);
  pinMode(SCL_Pin,OUTPUT);
  pinMode(SDA_Pin,OUTPUT);
  pic(smile);
  neck.attach(NECK, 500, 2500);
  delay(3000);
  neck.write(0);
  digitalWrite(RSL, HIGH);
  pic(smile_blink);
}

bool right = false;
unsigned long blinkPeriod = 5000;
unsigned long blinkTime = 80;
unsigned long t = 0;

void loop() {
  t = millis();
  if (tape() == 0 || tape() == 5) {
    drive(255, 255);
    if (t % blinkPeriod <= blinkTime) {
      pic(smile_blink);
    } else {
      pic(smile);
    }
  } else {
    if (tape() == 100) {
      if (right) {
        drive(-130, -100);
      } else {
        drive(-100, -130);
      }
      if (t % blinkPeriod <= blinkTime) {
        pic(confused_blink);
      } else {
        pic(confused);
      }
    } else {
      if (tape() == 1) {
        drive(180, 255);
        right = true;
      }
      if (tape() == 2) {
        drive(77, 255);
        right = true;
      }
      if (tape() == -1) {
        drive(255, 180);
        right = false;
      }
      if (tape() == -2) {
        drive(255, 77);
        right = false;
      }      
      if (t % blinkPeriod <= blinkTime) {
        pic(happy_blink);
      } else {
        pic(happy);
      }
    }
  }
}
