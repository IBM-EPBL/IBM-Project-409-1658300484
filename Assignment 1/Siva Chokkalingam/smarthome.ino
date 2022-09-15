// C++ code
//
#include <Servo.h>
Servo door;
int tempPin = 0;
int motorPin = 13;
int pirPin = 11;
int pirPin2 = 10;
int servo = 12;

void setup()
{
  pinMode(pirPin, INPUT);
  pinMode(pirPin2, INPUT);
  door.attach(servo);
  door.write(0);
  
}

void loop()
{
  if (analogRead(tempPin)> 256){
    digitalWrite(motorPin, HIGH);
  }else{
    digitalWrite(motorPin, LOW);
  }
  
  if (digitalRead(pirPin)){
    door.write(90);
    delay(1000);
    door.write(0);
  }else{
    digitalWrite(servo, LOW);
  }
  
  if (digitalRead(pirPin2)){
    digitalWrite(2, HIGH);
  }else{
    digitalWrite(2, LOW);
  }
}
