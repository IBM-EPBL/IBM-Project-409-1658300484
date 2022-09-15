// C++ code
//
const int Pin=0;
const int limit=480;


void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);

}

void loop() {
  int value;
  value=analogRead(Pin);
  Serial.println("analog value:");
  Serial.println(value);
  delay(1000);
  if (value<limit)
  {
    digitalWrite(13,HIGH);
  }
  else
  {
    digitalWrite(13,LOW);
  }

}
