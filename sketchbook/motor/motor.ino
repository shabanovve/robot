#include <AFMotor.h>  //Подключаем заголовочный файл библиотеки

//Создаем объект для двигателя на 1 канале (M1)
AF_DCMotor motorLeftFront(1);
AF_DCMotor motorRightFront(2);

AF_DCMotor motorLeftBack(3);
AF_DCMotor motorRightBack(4);

int operationTime = 300;

const int pingPin = 9;
const int trigPin = 10;


void setup() {
  Serial.begin(9600);
}


void go(){  
  motorLeftFront.run(FORWARD);
  motorRightFront.run(FORWARD);
  motorLeftBack.run(FORWARD);
  motorRightBack.run(FORWARD);
  motorLeftFront.setSpeed(100);
  motorRightFront.setSpeed(100);
  motorLeftBack.setSpeed(100);
  motorRightBack.setSpeed(100);
  delay(operationTime);

}

void back(){
  motorLeftFront.run(BACKWARD);
  motorRightFront.run(BACKWARD);
  motorLeftBack.run(BACKWARD);
  motorRightBack.run(BACKWARD);
  motorLeftFront.setSpeed(100);
  motorRightFront.setSpeed(100);
  motorLeftBack.setSpeed(100);
  motorRightBack.setSpeed(100);
  delay(operationTime);

}

void stop(){
    motorLeftFront.run(RELEASE);
    motorRightFront.run(RELEASE);
    motorLeftBack.run(RELEASE);
    motorRightBack.run(RELEASE);
    delay(100);
}

void goLeft(){
  motorLeftFront.run(FORWARD);
  motorRightFront.run(FORWARD);
  motorLeftFront.setSpeed(20);
  motorRightFront.setSpeed(255);
  motorLeftBack.run(FORWARD);
  motorRightBack.run(FORWARD);
  motorLeftBack.setSpeed(20);
  motorRightBack.setSpeed(255);

  delay(operationTime);
}

void goRight(){
  motorLeftFront.run(FORWARD);
  motorRightFront.run(FORWARD);
  motorLeftFront.setSpeed(255);
  motorRightFront.setSpeed(20);
  
  motorLeftBack.run(FORWARD);
  motorRightBack.run(FORWARD);
  motorLeftBack.setSpeed(255);
  motorRightBack.setSpeed(20);
  delay(operationTime);
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

long getDistance()
{
  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
  long duration, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(trigPin, INPUT);
  duration = pulseIn(trigPin, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);
  
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(100);
  return cm;
}

void loop() {
  if (getDistance() > 30){
    go();
    goLeft();
    goRight();
  } else {
    stop();
    back();
  }
}


