#include <Servo.h>
int opa1 = 10;
int opa2 = 11;
int ops = 4;
int pos = 90;
int op1 = 6;
int op2 = 7;
int op3 = 8;
int op4 = 9;
int s1 = A0;
int s2 = A1;
int Speed1 = 800;
int Speed2 = 800;
Servo myservo;

char a;

void setup() {
  pinMode(op1, OUTPUT);
  pinMode(op2, OUTPUT);
  pinMode(op3, OUTPUT);
  pinMode(op4, OUTPUT);
  pinMode(ops, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  myservo.attach(ops);
  Serial.begin(9600);
  // put your setup code here, to run once:

}
void grabon()
{
  for (pos = 90; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);    
}
}
void graboff()
{
  for (pos = 180; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
}
}
void pickup()
{
  analogWrite(11,255);
  analogWrite(10, 0);
  delay(15);
  analogWrite(11,0);
  analogWrite(10, 0);
}
void pickdown()
{
  analogWrite(10,255);
  analogWrite(11, 0);
  delay(15);
  analogWrite(11,0);
  analogWrite(10, 0);
}

void forward()
{

  digitalWrite(op1, HIGH);
  digitalWrite(op2, LOW);
  digitalWrite(op3, HIGH);
  digitalWrite(op4, LOW);
  digitalWrite(s1, Speed1);
  digitalWrite(s2, Speed2);
  Serial.println("forward");

}
void Stop()
{
  //analogWrite(en1, 255);
  //analogWrite(en2, x);
  digitalWrite(op1, LOW);
  digitalWrite(op2, LOW);
  digitalWrite(op3, LOW);
  digitalWrite(op4, LOW);
  digitalWrite(s1, Speed1);
  digitalWrite(s2, Speed2);
  Serial.println("stop");

}

void reverse()
{
  //analogWrite(en1, 255);
  //analogWrite(en2, x);
  digitalWrite(op1, LOW);
  digitalWrite(op2, HIGH);
  digitalWrite(op3, LOW);
  digitalWrite(op4, HIGH);
  digitalWrite(s1, Speed1);
  digitalWrite(s2, Speed2);
  Serial.println("reverse");

}
void reverseright()
{
  //analogWrite(en1, 255);
  //analogWrite(en2, x);
  digitalWrite(op1, LOW);
  digitalWrite(op2, LOW);
  digitalWrite(op3, LOW);
  digitalWrite(op4, HIGH);
  digitalWrite(s1, Speed1);
  digitalWrite(s2, Speed2);
  Serial.println("reverse right");

}
void reverseleft()
{
  //analogWrite(en1,255);
  //analogWrite(en2, x);
  digitalWrite(op1, LOW);
  digitalWrite(op2, HIGH);
  digitalWrite(op3, LOW);
  digitalWrite(op4, LOW);
  digitalWrite(s1, Speed1);
  digitalWrite(s2, Speed2);
  Serial.println("reverse left");

}
void left()
{
  //analogWrite(en1, 255);
  //analogWrite(en2, x);
  digitalWrite(op1, HIGH);
  digitalWrite(op2, LOW);
  digitalWrite(op3, LOW);
  digitalWrite(op4, HIGH);
  digitalWrite(s1, Speed1);
  digitalWrite(s2, Speed2);
  Serial.println("left");

}
void right()
{
  // analogWrite(en1, 255);
  //analogWrite(en2, x);
  digitalWrite(op1, LOW);
  digitalWrite(op2, HIGH);
  digitalWrite(op3, HIGH);
  digitalWrite(op4, LOW);
  digitalWrite(s1, Speed1);
  digitalWrite(s2, Speed2);
  Serial.println("right");

}
void forwardleft()
{
  digitalWrite(op1, HIGH);
  digitalWrite(op2, LOW);
  digitalWrite(op3, LOW);
  digitalWrite(op4, LOW);
  digitalWrite(s1, Speed1);
  digitalWrite(s2, Speed2);
  Serial.println("forwardleft");

}
void forwardright()
{
  digitalWrite(op1, LOW);
  digitalWrite(op2, LOW);
  digitalWrite(op3, HIGH);
  digitalWrite(op4, LOW);
  digitalWrite(s1, Speed1);
  digitalWrite(s2, Speed2);
  Serial.println("forwardright");
}
void loop() {
    if (Serial.available())
    {
      a = Serial.read();
      Serial.println(a);
    }
    if (a == 'B')
    {
      forward();
      Serial.println("forward");
    }
    else if (a == 'L')
    {
      left();

    }
    else if (a == 'R')
    {
      right();

    }
    else if (a == 'z')
    {
      forwardleft();

    }
    else if (a == 'Z')
    {
      forwardright();

    }
    else if (a == 'F')
    {
      reverse();

    }

    else if (a == 'q')
    {
      reverseleft();

    }
    else if (a == 'Q')
    {
      reverseright();

    }
    else if (a == 'P')
    {
      pickup();

    }
    
    else if (a == 'D')
    {
      pickdown();
    }
    else if (a == 'G')
    {
      grabon();
    }
    else if (a == 'g')
    {
      graboff();
    }
    else if (a == 'S')
    {
      Stop();
    }
  }
