#include <Servo.h>

#define trigPin   6
#define echoPin   7
#define trigPin2   10
#define echoPin2   11

#define ledRedPin   A3

Servo myservo;

void setup()
{
  Serial.begin(9600);
  
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  pinMode (trigPin2, OUTPUT);
  pinMode (echoPin2, INPUT);
  pinMode (ledRedPin, OUTPUT);
  
  myservo.attach(9);
}

int distance(String deviceType) {
  double dist;
  if(deviceType=="Hand") {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    dist = pulseIn(echoPin, HIGH)/58;    
  }else{
    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2, LOW);
    dist = pulseIn(echoPin2, HIGH)/58; 
  }
  
  return dist;
}

void loop()
{   
  if(distance("HAND")>30 && distance("HAND")<60)
  {
    myservo.write(180);
    delay(3000);
    myservo.write(3);
    delay(1000);
  }
  if(distance("TRASH")<3)
  {
    digitalWrite(ledRedPin, HIGH);
  }
  else
  {
    digitalWrite(ledRedPin, LOW);
  }
}

