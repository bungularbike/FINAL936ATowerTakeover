/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Wed Sep 25 2019                                           */
/*    Description:  Tank Drive                                                */
/*    This sample allows you to control the V5 Clawbot using the both         */
/*    joystick. Adjust the deadband value for more accurate movements.        */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Bleft                motor         1               
// Fleft                motor         2               
// Bright               motor         3               
// Fright               motor         4               
// Tray                 motor         5               
// Lift                 motor         6               
// ITLeft               motor         8               
// ITRight              motor         9               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // Deadband stops the motors when Axis values are close to zero.
  int deadband = 5;

  while (true) {
    // Get the velocity percentage of the left motor. (Axis3)
    int leftMotorSpeed = Controller1.Axis3.position();
    // Get the velocity percentage of the right motor. (Axis2)
    int rightMotorSpeed = Controller1.Axis2.position();

    // Set the speed of the left motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(leftMotorSpeed) < deadband) {
      // Set the speed to zero.
      Bleft.setVelocity(0, percent);
      Fleft.setVelocity(0, percent);
    } else {
      // Set the speed to leftMotorSpeed
      Bleft.setVelocity(leftMotorSpeed, percent);
      Fleft.setVelocity(leftMotorSpeed, percent);
    }

    // Set the speed of the right motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(rightMotorSpeed) < deadband) {
      // Set the speed to zero
      Bright.setVelocity(0, percent);
      Fright.setVelocity(0, percent);
    } else {
      // Set the speed to rightMotorSpeed
      Bright.setVelocity(rightMotorSpeed, percent);
      Fright.setVelocity(rightMotorSpeed, percent);
    }

    // Spin both motors in the forward direction.
    Bleft.spin(forward);
    Fleft.spin(reverse);
    Bright.spin(forward);
    Fright.spin(reverse);

    wait(25, msec);

    Lift.setVelocity(100, rpm);
    if (Controller1.ButtonL1.pressing()) {     
    
      Lift.spin(forward);
      
    } else if (Controller1.ButtonL2.pressing()) {

      Lift.spin(reverse);  
      
    } else {

      Lift.stop(hold);

    }

    Tray.setVelocity(100, rpm);
    if (Controller1.ButtonUp.pressing()) {     
    
      Tray.spin(forward);
      
    } else if (Controller1.ButtonDown.pressing()) {

      Tray.spin(reverse);  
      
    } else {

      Tray.stop(hold);

    }

    ITLeft.setVelocity(200, rpm);
    ITRight.setVelocity(200, rpm);
    if (Controller1.ButtonR1.pressing()) {     
    
      ITLeft.spin(reverse);
      ITRight.spin(forward);
      
    } else if (Controller1.ButtonR2.pressing()) {

      ITLeft.spin(forward);
      ITRight.spin(reverse);
      
    } else {

      ITLeft.stop(hold);
      ITRight.stop(hold);

    }

  }
}
