int PIR = 0;

int HIGH2 = 0;

int TMP = 0;

void setup()
{
  pinMode(A1, INPUT);
  Serial.begin(9600);

  pinMode(2, INPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  TMP = -40 + 0.488155 * (analogRead(A1) - 20);
  Serial.println(TMP);
  PIR = digitalRead(2);
  Serial.println(PIR);
  delay(100); // Wait for 100 millisecond(s)
  if (PIR == 1) {
    digitalWrite(12, HIGH);
  } else {
    digitalWrite(12, LOW);
  }
  if (TMP > 35) {
    digitalWrite(11, HIGH);
  } else {
    digitalWrite(11, LOW);
  }
}