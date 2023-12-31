#include "main.h"
#include "pros/rtos.hpp"

/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////

const int DRIVE_SPEED =
    90; // This is 110/127 (around 87% of max speed).  We don't suggest making
        // this 127. If this is 127 and the robot tries to heading correct, it's
        // only correcting by making one side slower.  When this is 87%, it's
        // correcting by making one side faster and one side slower, giving
        // better heading correction.
const int TURN_SPEED = 90;
const int SWING_SPEED = 90;

///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier
// game objects, or with lifts up vs down. If the objects are light or the cog
// doesn't change much, then there isn't a concern here.

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void one_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void two_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void exit_condition_defaults() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

// START OF Fiesta AUTOS

/**
  __  __       _       _          _         _                
 |  \/  | __ _| |_ ___| |__      / \  _   _| |_ ___  _ __  _ 
 | |\/| |/ _` | __/ __| '_ \    / _ \| | | | __/ _ \| '_ \(_)
 | |  | | (_| | || (__| | | |  / ___ \ |_| | || (_) | | | |_ 
 |_|  |_|\__,_|\__\___|_| |_| /_/   \_\__,_|\__\___/|_| |_(_)
                                                             
*/
void Frenzy_Rush_Mid()
{
  chassis.set_drive_pid(24, 90);
  chassis.wait_drive();

  chassis.set_turn_pid(90, 90);
  chassis.wait_drive();

  chassis.set_drive_pid(-12, 60);
  chassis.wait_drive();

  chassis.set_turn_pid(0, 90);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, 90);
  chassis.wait_drive();

  chassis.set_turn_pid(90, 90);
  chassis.wait_drive();

  chassis.set_drive_pid(12, 60);
  chassis.wait_drive();

  chassis.set_turn_pid(0, 90);
  chassis.wait_drive();

  chassis.set_swing_pid(RIGHT_SWING, -45, 90);
  chassis.wait_drive();

  chassis.set_swing_pid(LEFT_SWING, 0, 90);
  chassis.wait_drive();

  chassis.set_drive_pid(-18, 90);
  chassis.wait_drive();

  chassis.set_turn_pid(135, 90);
  chassis.wait_drive();

  chassis.set_drive_pid(36, 90, true);
  chassis.wait_drive();
}

/**
  ____  _    _ _ _          _         _                
 / ___|| | _(_) | |___     / \  _   _| |_ ___  _ __  _ 
 \___ \| |/ / | | / __|   / _ \| | | | __/ _ \| '_ \(_)
  ___) |   <| | | \__ \  / ___ \ |_| | || (_) | | | |_ 
 |____/|_|\_\_|_|_|___/ /_/   \_\__,_|\__\___/|_| |_(_)
                                                       
*/


void Default()
{
  //Bring intakes out
  Actuate_Auto("out");
  int x = 0;

  while (x < 19) {
    chassis.set_drive_pid(-9, 65);
    chassis.wait_drive();

    Intake_Auto(600);

    chassis.set_turn_pid(-25, 50);
    chassis.wait_drive();

    pros::delay(20);
    Catapult_Fire();
    pros::delay(150);

    chassis.set_turn_pid(0, 50);
    chassis.wait_drive();

    chassis.set_drive_pid(10, 50);
    chassis.wait_drive();
    x++;
  }

  chassis.set_drive_pid(-7, 65);
  chassis.wait_drive();

  chassis.set_turn_pid(-30, 50);
  chassis.wait_drive();

  pros::delay(20);
  Catapult_Fire();
  pros::delay(250);

  //Turn to goals for wing movement
  
  chassis.set_turn_pid(-65, 75);
  chassis.wait_drive();

  chassis.set_drive_pid(-28, 75);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, 75);
  chassis.wait_drive();

  //Drive to goal and push in side of goal

  chassis.set_drive_pid(-60, 90, true);
  chassis.wait_drive();

  Actuate_Auto("in");
  Intake_Auto(0);
  pros::delay(150);

  chassis.set_turn_pid(0, 75);
  chassis.wait_drive();

  chassis.set_drive_pid(-30, 75);
  chassis.wait_drive();

  chassis.set_turn_pid(45, 75);
  chassis.wait_drive();

  chassis.set_drive_pid(-10, 100);
  chassis.wait_drive();

  chassis.set_drive_pid(5, 50);
  chassis.wait_drive();

  chassis.set_drive_pid(-10, 100);
  chassis.wait_drive();

  //Go to wing deploy location

  chassis.set_drive_pid(5, 75);
  chassis.wait_drive();

  chassis.set_turn_pid(135, 75);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, 75);
  chassis.wait_drive();

  chassis.set_turn_pid(90, 75);
  chassis.wait_drive();

  wingsAuto(true);

  //Corral triballs

  chassis.set_drive_pid(-24, 30);
  chassis.wait_drive();

  chassis.set_turn_pid(45, 50);
  chassis.wait_drive();

  //Turn to goal

  chassis.set_drive_pid(-10, 50);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, 50);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, 100);
  chassis.wait_drive();

  chassis.set_drive_pid(18, 100);
  chassis.wait_drive();

  chassis.set_turn_pid(45, 75);
  chassis.wait_drive();

  chassis.set_drive_pid(12, 50);
  chassis.wait_drive();


}

void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is target degrees
  // The third parameter is speed of the moving side of the drive

  chassis.set_swing_pid(ez::LEFT_SWING, 45, SWING_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(12);

  chassis.set_swing_pid(ez::RIGHT_SWING, 0, SWING_SPEED);
  chassis.wait_drive();
}

///
// Auto that tests everything
///
void combining_movements() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, -45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}

///
// Interference example
///
void tug(int attempts) {
  for (int i = 0; i < attempts - 1; i++) {
    // Attempt to drive backwards
    printf("i - %i", i);
    chassis.set_drive_pid(-12, 127);
    chassis.wait_drive();

    // If failsafed...
    if (chassis.interfered) {
      chassis.reset_drive_sensor();
      chassis.set_drive_pid(-2, 20);
      pros::delay(1000);
    }
    // If robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, robot will drive forward and turn 90 degrees.
// If interfered, robot will drive forward and then attempt to drive backwards.
void interfered_example() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  if (chassis.interfered) {
    tug(3);
    return;
  }

  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();
}

// . . .
// Make your own autonomous functions here!
// . . .