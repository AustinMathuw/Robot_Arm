/*
Robot_Arm v0.1

Uses 3 A4988 boards, 3 Neva 17 stepper motors, 6 control push-buttons, and an Arduino Mega

*/
int enablePinBase = 6; //Start configuration of Base Motor
int stepPinBase = 5;
int directionPinBase = 4; //End configuration of Base Motor

int enablePinElbow = 9; //Start configuration of Elbow Motor
int stepPinElbow = 8;
int directionPinElbow = 7; //End configuration of Elbow Motor

int enablePinArm = 12; //Start configuration of  Motor
int stepPinArm = 11;
int directionPinArm = 10; //End configuration of Base Motor

const int buttonBaseRight = 36; //Set pin for button that turns Base Motor Right
const int buttonBaseLeft = 37; //Set pin for button that turns Base Motor Left

const int buttonElbowUp = 30; //Set pin for button that moves Elbow Motor Up
const int buttonElbowDown = 31; //Set pin for button that turns Elbow Motor Down

const int buttonArmUp = 53; //Set pin for button that turns Base Motor Right
const int buttonArmDown = 46; //Set pin for button that turns Base Motor Left

int buttonStateBaseRight = 0;
int buttonStateBaseLeft = 0;
int buttonStateElbowUp = 0;
int buttonStateElbowDown = 0;
int buttonStateArmUp = 0;
int buttonStateArmDown = 0;
// The setup() method runs once, when the sketch starts

void setup()   {                
 // initialize the pins  
 pinMode(enablePinBase, OUTPUT);    
 pinMode(stepPinBase, OUTPUT);    
 pinMode(directionPinBase, OUTPUT);

 pinMode(enablePinElbow, OUTPUT);    
 pinMode(stepPinElbow, OUTPUT);    
 pinMode(directionPinElbow, OUTPUT);

 pinMode(enablePinArm, OUTPUT);    
 pinMode(stepPinArm, OUTPUT);    
 pinMode(directionPinArm, OUTPUT);

 digitalWrite(enablePinBase, HIGH);
 digitalWrite(stepPinBase, LOW);
 digitalWrite(directionPinBase, LOW);

 digitalWrite(enablePinElbow, HIGH);
 digitalWrite(stepPinElbow, LOW);
 digitalWrite(directionPinElbow, LOW);

 digitalWrite(enablePinArm, HIGH);
 digitalWrite(stepPinArm, LOW);
 digitalWrite(directionPinArm, LOW);

 pinMode(buttonBaseRight, INPUT);
 pinMode(buttonBaseLeft, INPUT);
 pinMode(buttonElbowUp, INPUT);
 pinMode(buttonElbowDown, INPUT);
 pinMode(buttonArmUp, INPUT);
 pinMode(buttonArmDown, INPUT);

}

// the loop() method runs over and over again,
// as long as the Arduino has power

void loop()                    
{
  buttonStateBaseRight = digitalRead(buttonBaseRight); //Start reading the states of the buttons
  buttonStateBaseLeft = digitalRead(buttonBaseLeft);

  buttonStateElbowUp = digitalRead(buttonElbowUp);
  buttonStateElbowDown = digitalRead(buttonElbowDown);

  buttonStateArmUp = digitalRead(buttonArmUp);
  buttonStateArmDown = digitalRead(buttonArmDown);  //End reading the states of the buttons
  
  
  if (buttonStateBaseRight == buttonStateBaseLeft) { //Start Base Motor Control
    //If both buttons pressed, don't do anything
  } else {
    if (buttonStateBaseRight == HIGH) {  //SWITCH IF WRONG DIRECTION
      digitalWrite(enablePinBase, LOW);
      digitalWrite(directionPinBase, HIGH); //Decide Direction
      digitalWrite(stepPinBase, HIGH);
      delay(1); //Speed of Motor (1 step per x milliseconds)
      digitalWrite(stepPinBase, LOW);
      delay(1);
    }

    if (buttonStateBaseLeft == HIGH) {  //SWITCH IF WRONG DIRECTION
      digitalWrite(enablePinBase, LOW);
      digitalWrite(directionPinBase, LOW); //Decide Direction
      digitalWrite(stepPinBase, HIGH);
      delay(1); //Speed of Motor (1 step per x milliseconds)
      digitalWrite(stepPinBase, LOW);
      delay(1);
    }
  }  //End Base Motor Control

  if (buttonStateElbowUp == buttonStateElbowDown) {  //Start Elbow Motor Control
    //If both buttons pressed, don't do anything
  } else {
    if (buttonStateElbowUp == HIGH) {  //SWITCH IF WRONG DIRECTION
      digitalWrite(enablePinElbow, LOW);
      digitalWrite(directionPinElbow, HIGH); //Decide Direction
      digitalWrite(stepPinElbow, HIGH);
      delay(1); //Speed of Motor (1 step per x milliseconds)
      digitalWrite(stepPinElbow, LOW);
      delay(1);
    }

    if (buttonStateElbowDown == HIGH) {  //SWITCH IF WRONG DIRECTION
      digitalWrite(enablePinElbow, LOW);
      digitalWrite(directionPinElbow, LOW); //Decide Direction
      digitalWrite(stepPinElbow, HIGH);
      delay(1); //Speed of Motor (1 step per x milliseconds)
      digitalWrite(stepPinElbow, LOW);
      delay(1);
    }
  } //Start Elbow Motor Control

  if (buttonStateArmUp == buttonStateArmDown) {  //Start Arm Motor Control
    //If both buttons pressed, don't do anything
  } else {
    if (buttonStateArmUp == HIGH) {  //SWITCH IF WRONG DIRECTION
      digitalWrite(enablePinArm, LOW);
      digitalWrite(directionPinArm, HIGH); //Decide Direction
      digitalWrite(stepPinArm, HIGH);
      delay(1); //Speed of Motor (1 step per x milliseconds)
      digitalWrite(stepPinArm, LOW);
      delay(1);
    }

    if (buttonStateArmDown == HIGH) {  //SWITCH IF WRONG DIRECTION
      digitalWrite(enablePinArm, LOW);
      digitalWrite(directionPinArm, LOW); //Decide Direction
      digitalWrite(stepPinArm, HIGH);
      delay(1); //Speed of Motor (1 step per x milliseconds)
      digitalWrite(stepPinArm, LOW);
      delay(1);
    }
  }  //End Arm Motor Control
}
