/* RACE CODE
This is the official programming that was in the robot car for the blackline race.
Our robot did win the blackline race, so this is GOOD CODE.
Our robot beat the next closest team by 5.99 seconds.
*/

// Pin Numbers:
const int RSL = 9;
const int leftMotor_dir = 4;
const int leftMotor_pwr = 5;
const int rightMotor_dir = 2;
const int rightMotor_pwr = 6;
const int L = 8;
const int M = 7;
const int R = 11;

// Variables:
bool right = false;
int Tape;

// Functions:
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
  delay(3000);
  digitalWrite(RSL, HIGH);
}

// Main Code:
void loop() {
  Tape = tape();
  if (Tape == 0 || Tape == 5) {
    drive(255, 255);
  } else if (Tape == 100) {
    if (right) {
      drive(-120, 255);
    } else {
      drive(255, -120);
    }
    while (Tape == 100) {
      Tape = tape();
    }
  } else if (Tape == 1) {
    drive(220, 255);
    right = true;
  } else if (Tape == 2) {
    drive(177, 255);
    right = true;
  } else if (Tape == -1) {
    drive(255, 220);
    right = false;
  } else if (Tape == -2) {
    drive(255, 177);
    right = false;
  }
}
