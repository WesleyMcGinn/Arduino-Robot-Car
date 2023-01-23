const int RSL = 9;

// Distance Detecting Function:
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

void setup() {
  pinMode(RSL, OUTPUT);
  delay(2000);
  digitalWrite(RSL, HIGH);
  Serial.begin(115200);
}

void loop() {
  Serial.println(distance(12, 13, cm));
  delay(100);
}
