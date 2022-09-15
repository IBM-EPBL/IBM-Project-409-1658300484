#include <Keypad.h>
#include<Servo.h>

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {11, 10, 9, 8};
byte colPins[COLS] = {7, 6, 5, 4};

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

Servo inGate;

void setup()
{
  Serial.begin(9600);
  inGate.attach(3);  
  inGate.write(0);
  
  pinMode(A0, INPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  
}

String pass;
int k = 0;
void loop()
{
  char customKey = customKeypad.getKey();
  if(customKey) {
    pass += customKey;
    k ++;
    Serial.println(pass);
  }
  
  
  //Serial.println(pass=="1234");
  
  if(pass=="1234"){
    inGate.write(90);
    delay(1000);
    inGate.write(0);
    pass = "";
    k = 0;
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
  }
  else
    inGate.write(0);
  
  int val = analogRead(A0);
  // Serial.println(val);
  if(val > 200)
    digitalWrite(12, HIGH);
  else
    digitalWrite(12, LOW);
    
  if(digitalRead(2))
    digitalWrite(0, HIGH);
  else
    digitalWrite(0, LOW);
    
  
}