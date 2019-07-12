
#include <AFMotor.h>

// Connect a stepper motor with 48 steps per revolution (7.5 degree)
// to motor port #2 (M3 and M4)
AF_Stepper motor(200, 2);
AF_Stepper motor2(200,1);
int previous=0;
int direc;
void setup() {
  Serial.begin(9600);   
  motor.setSpeed(30);
  motor2.setSpeed(30);
}

void loop() {
  // read the sensor value:

  int sensorReading = analogRead(A0);
int positionpls = map(sensorReading,0,680,0,400);
 Serial.println(positionpls);
  if ((positionpls - previous)<-1) {
    direc = FORWARD;
      motor.step(abs(positionpls - previous),direc,DOUBLE);
    motor2.step(abs(positionpls - previous),direc,DOUBLE);
  } else if ((positionpls - previous)>1) {
   direc = BACKWARD;
    motor.step(abs(positionpls - previous),direc,DOUBLE);
   motor2.step(abs(positionpls - previous),direc,DOUBLE);
  } else {
    
  }
  // remember the previous value of the sensor
  previous = positionpls;
  }

