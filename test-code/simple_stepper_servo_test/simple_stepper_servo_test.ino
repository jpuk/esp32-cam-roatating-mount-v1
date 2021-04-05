
#include <Stepper.h>
#include <Servo.h>


const int stepsPerRevolution = 300;//800;  
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
Servo myservo; 
int pos = 0;    // variable to store the servo position
int ang = 70;

void setup() {
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object
  myStepper.setSpeed(5);
  Serial.begin(9600);
}

void loop() {
  for (pos = 0; pos <= ang; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(2500);
  for (pos = ang; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(5000);
  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(2500);
    for (pos = 0; pos <= ang; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(2500);
  for (pos = ang; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(2500);
}
