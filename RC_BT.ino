#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // TX, RX

char RecivedData;

int Right_Speed_Pin = 9;//EN-A
int Left_Speed_Pin = 6; //EN-B

int LM1 = 2; //Left Motor
int LM2 = 3;
int RM1 = 4; //Right Motor
int RM2 = 5;

void SetSpeed(int Speed)
{
  analogWrite(Right_Speed_Pin, Speed);
  analogWrite(Left_Speed_Pin, Speed);
}
void Stop()
{
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
}
void  Forward()
{
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);
}
void  Backward()
{
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}
void  SpotRight()
{
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);
}
void  ArcRight()
{
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
}
void  SpotLeft()
{
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}
void  ArcLeft()
{
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}

void setup() {
  pinMode(LM1, OUTPUT); //Left 1
  pinMode(LM2, OUTPUT); //Left 2
  pinMode(RM1, OUTPUT); //Right 1
  pinMode(RM2, OUTPUT); //Right 2
  pinMode(Right_Speed_Pin, OUTPUT); //Enable A
  pinMode(Left_Speed_Pin, OUTPUT); //Enable B
  Serial.begin(9600); //Arduino Uno - PC
  mySerial.begin(9600); //Arduino Uno - HC05
}

void loop() {
  //Read Bluetooth Data
  if (mySerial.available() > 0) {
    RecivedData = mySerial.read();
  }
  if (RecivedData == 'F')
  {
    Forward();
    SetSpeed(200);
    Serial.println("Forward");
  }
  if (RecivedData == 'B')
  {
    Backward();
    SetSpeed(200);
    Serial.println("Backward");
  }
  else if (RecivedData == 'L')
  {
    SpotLeft();
    SetSpeed(200);
    Serial.println("Left");
  }
  else if (RecivedData == 'R')
  {
    SpotRight();
    SetSpeed(200);
    Serial.println("Right");
  }
  else {
    Stop();
    Serial.println("Stop");
  }
}