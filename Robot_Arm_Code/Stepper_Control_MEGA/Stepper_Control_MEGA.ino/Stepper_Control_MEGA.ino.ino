//Robot Arm Mega v1.2
//http://www.seeedstudio.com/wiki/File:MotorDriver20121210.zip - Motor Driver Library
#include "MotorDriver.h"

const int buttonElbowUp = 35;
const int buttonElbowDown = 32;
const int buttonSholderUp = 37;
const int buttonSholderDown = 34;
const int buttonBaseRight = 36; //Set pin for button that turns Base Motor Right
const int buttonBaseLeft = 39; //Set pin for button that turns Base Motor Left

int enablePinBase = 7; //Start configuration of Base Motor
int stepPinBase = 6;
int directionPinBase = 5; //End configuration of Base Motor

int buttonStateBaseRight = 0;
int buttonStateBaseLeft = 0;
int buttonStateElbowUp = 0;
int buttonStateElbowDown = 0;
int buttonStateSholderUp = 0;
int buttonStateSholderDown = 0;

void setup()
{
  motordriver.init();
  motordriver.setSpeed(200,MOTORB);
  motordriver.setSpeed(200,MOTORA);
  pinMode(buttonElbowUp, INPUT);
  pinMode(buttonElbowDown, INPUT);
  pinMode(buttonSholderUp, INPUT);
  pinMode(buttonSholderDown, INPUT);
  pinMode(buttonBaseRight, INPUT);
  pinMode(buttonBaseLeft, INPUT);
  pinMode(enablePinBase, OUTPUT);    
  pinMode(stepPinBase, OUTPUT);    
  pinMode(directionPinBase, OUTPUT);
  digitalWrite(enablePinBase, HIGH);
  digitalWrite(stepPinBase, LOW);
  digitalWrite(directionPinBase, LOW);
}
 
void loop()
{
  buttonStateElbowUp = digitalRead(buttonElbowUp);
  buttonStateElbowDown = digitalRead(buttonElbowDown);
  buttonStateSholderUp = digitalRead(buttonSholderUp);
  buttonStateSholderDown = digitalRead(buttonSholderDown);
  buttonStateBaseRight = digitalRead(buttonBaseRight);
  buttonStateBaseLeft = digitalRead(buttonBaseLeft);

  if (buttonStateBaseRight == buttonStateBaseLeft) { //Start Base Motor Control
    //If both buttons pressed, don't do anything
  } else {
    if (buttonStateBaseRight == HIGH) {  //SWITCH IF WRONG DIRECTION
      digitalWrite(enablePinBase, LOW);
      digitalWrite(directionPinBase, HIGH); //Decide Direction
      digitalWrite(stepPinBase, HIGH);
      delay(10); //Speed of Motor (1 step per x milliseconds)
      digitalWrite(stepPinBase, LOW);
      delay(10);
    }

    if (buttonStateBaseLeft == HIGH) {  //SWITCH IF WRONG DIRECTION
      digitalWrite(enablePinBase, LOW);
      digitalWrite(directionPinBase, LOW); //Decide Direction
      digitalWrite(stepPinBase, HIGH);
      delay(10); //Speed of Motor (1 step per x milliseconds)
      digitalWrite(stepPinBase, LOW);
      delay(10);
    }
  }  //End Base Motor Control

  switch (buttonStateElbowUp == HIGH) {
    case 1:
      motordriver.rotateWithID(MOTOR_CLOCKWISE, MOTORA);
      delay(1);
      motordriver.stop(MOTORA);
      break;
  }
  switch (buttonStateElbowDown == HIGH) {
    case 1:
      motordriver.rotateWithID(MOTOR_ANTICLOCKWISE, MOTORA);
      delay(1);
      motordriver.stop(MOTORA);
      break;
    
  }
  switch (buttonStateSholderUp == HIGH) {
    case 1:
      motordriver.rotateWithID(MOTOR_CLOCKWISE, MOTORB);
      delay(1);
      motordriver.stop(MOTORB);
      break;
  }
  switch (buttonStateSholderDown == HIGH) {
    case 1:
      motordriver.rotateWithID(MOTOR_ANTICLOCKWISE, MOTORB);
      delay(1);
      motordriver.stop(MOTORB);
      break;
    
  }
}
