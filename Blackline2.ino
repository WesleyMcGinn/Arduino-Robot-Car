/*
BLACKLINE 2
Makes the robot follow a line of black tape on the floor.
Start the robot on the line and it should work properly.
*/


const int RSL = 9;
const int leftMotor_dir = 4;
const int leftMotor_pwr = 5;
const int rightMotor_dir = 2;
const int rightMotor_pwr = 6;
const int L = 8;
const int M = 7;
const int R = 11;

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


void setup() {
  pinMode(RSL, OUTPUT);
  pinMode(leftMotor_dir, OUTPUT);
  pinMode(leftMotor_pwr, OUTPUT);
  pinMode(rightMotor_dir, OUTPUT);
  pinMode(rightMotor_pwr, OUTPUT);
  pinMode(L, INPUT);
  pinMode(M, INPUT);
  pinMode(R, INPUT);
  delay(2000);
  digitalWrite(RSL, HIGH);
}


bool right = false;


void loop() {
  if (tape() == 0 || tape() == 5) {
    drive(170, 170);
  } else {
    if (tape() == 100) {
      if (right) {
        drive(-130, -50);
      } else {
        drive(-50, -130);
      }
    } else {
      if (tape() == 1) {
        drive(120, 200);
        right = true;
      }
      if (tape() == 2) {
        drive(77, 200);
        right = true;
      }
      if (tape() == -1) {
        drive(200, 120);
        right = false;
      }
      if (tape() == -2) {
        drive(200, 77);
        right = false;
      }
    }
  }
}
