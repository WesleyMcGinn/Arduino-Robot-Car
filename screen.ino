/*
Screen
Displays images on the screen on the front of the robot
Note:  This is not 100% my code.  Some of it is from http://tinyurl.com/robot-car-arduino
*/

// Images:
unsigned char clear[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char snail[] = {0x00, 0x80, 0xb8, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0xf8, 0x80, 0x47, 0x38, 0x07, 0x00, 0x00};
unsigned char chess1[] = {0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa};
unsigned char chess2[] = {0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55};
unsigned char smile[] = {0x08, 0x10, 0x20, 0x20, 0x43, 0x43, 0x80, 0x80, 0x80, 0x80, 0x43, 0x43, 0x20, 0x20, 0x10, 0x08};
unsigned char smile_blink[] = {0x08, 0x10, 0x20, 0x20, 0x42, 0x42, 0x80, 0x80, 0x80, 0x80, 0x42, 0x42, 0x20, 0x20, 0x10, 0x08};
unsigned char confused[] = {0x00, 0x00, 0x40, 0x40, 0x43, 0x43, 0x40, 0x40, 0x40, 0x40, 0x43, 0x43, 0x40, 0x40, 0x00, 0x00};
unsigned char confused_blink[] = {0x00, 0x00, 0x40, 0x40, 0x42, 0x42, 0x40, 0x40, 0x40, 0x40, 0x42, 0x42, 0x40, 0x40, 0x00, 0x00};
unsigned char happy[] = {0x00, 0x18, 0x28, 0x28, 0x4b, 0x4b, 0x88, 0x88, 0x88, 0x88, 0x4b, 0x4b, 0x28, 0x28, 0x18, 0x00};
unsigned char happy_blink[] = {0x00, 0x18, 0x28, 0x28, 0x4a, 0x4a, 0x88, 0x88, 0x88, 0x88, 0x4a, 0x4a, 0x28, 0x28, 0x18, 0x00};

// Pin Numbers:
#define SCL_Pin A5
#define SDA_Pin A4

// Functions:
void pic(unsigned char matrix_value[]) {
  digitalWrite(SCL_Pin,HIGH);delayMicroseconds(3);digitalWrite(SDA_Pin,HIGH);delayMicroseconds(3);digitalWrite(SDA_Pin,LOW);delayMicroseconds(3);IIC_send(0xc0);for(int i = 0;i < 16;i++) {IIC_send(matrix_value[i]);}digitalWrite(SCL_Pin,LOW);delayMicroseconds(3);digitalWrite(SDA_Pin,LOW);delayMicroseconds(3);digitalWrite(SCL_Pin,HIGH);delayMicroseconds(3);digitalWrite(SDA_Pin,HIGH);delayMicroseconds(3);digitalWrite(SCL_Pin,HIGH);delayMicroseconds(3);digitalWrite(SDA_Pin,HIGH);delayMicroseconds(3);digitalWrite(SDA_Pin,LOW);delayMicroseconds(3);IIC_send(0x8A);digitalWrite(SCL_Pin,LOW);delayMicroseconds(3);digitalWrite(SDA_Pin,LOW);delayMicroseconds(3);digitalWrite(SCL_Pin,HIGH);delayMicroseconds(3);digitalWrite(SDA_Pin,HIGH);delayMicroseconds(3);}void IIC_send(unsigned char send_data){for(char i = 0;i < 8;i++){digitalWrite(SCL_Pin,LOW);delayMicroseconds(3);if(send_data & 0x01){digitalWrite(SDA_Pin,HIGH);}else{digitalWrite(SDA_Pin,LOW);}delayMicroseconds(3);digitalWrite(SCL_Pin,HIGH);delayMicroseconds(3);send_data = send_data >> 1;}
}

void setup() {
  pinMode(SCL_Pin,OUTPUT);
  pinMode(SDA_Pin,OUTPUT);
  pic(clear);
}

void loop() {
  pic(smile);
  delay(1000);
  pic(smile_blink);
  delay(100);
  pic(smile);
  delay(1000);
  pic(happy);
  delay(1000);
  pic(happy_blink);
  delay(100);
  pic(happy);
  delay(1000);
  pic(chess2);
  delay(100);
  pic(chess1);
  delay(100);
  pic(chess2);
  delay(100);
  pic(chess1);
  delay(100);
  pic(chess2);
  delay(100);
  pic(chess1);
  delay(100);
  pic(chess2);
  delay(100);
  pic(chess1);
  delay(100);
  pic(chess2);
  delay(100);
  pic(chess1);
  delay(100);
  pic(chess2);
  delay(100);
  pic(chess1);
  delay(100);
  pic(chess2);
  delay(100);
  pic(chess1);
  delay(100);
  pic(chess2);
  delay(100);
  pic(chess1);
  delay(100);
  pic(chess2);
  delay(100);
  pic(chess1);
  delay(100);
  pic(chess2);
  delay(100);
  pic(chess1);
  delay(100);
  pic(chess2);
  delay(100);
  pic(chess1);
  delay(100);
  pic(snail);
  delay(3000);
}
