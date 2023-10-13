#include "main.h"


// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/




Drive chassis(
    // Left Chassis Ports (negative port will reverse it!)
    //   the first port is the sensored port (when trackers are not used!)
    {-10, -8, -7}

    // Right Chassis Ports (negative port will reverse it!)
    //   the first port is the sensored port (when trackers are not used!)
    ,
    {1, 4, 5}

    // IMU Port
    ,
    6

    // Wheel Diameter (Remember, 4" wheels are actually 4.125!)
    //    (or tracking wheel diameter)
    ,
    2.75

    // Cartridge RPM
    //   (or tick per rotation if using tracking wheels)
    ,
    600

    // External Gear Ratio (MUST BE DECIMAL)
    //    (or gear ratio of tracking wheel)
    // eg. if your drive is 84:36 where the 36t is powered, your RATIO would
    // be 2.333. eg. if your drive is 36:60 where the 60t is powered, your RATIO
    // would be 0.6.
    ,
    1

    // Uncomment if using tracking wheels
    /*
    // Left Tracking Wheel Ports (negative port will reverse it!)
    // ,{1, 2} // 3 wire encoder
    // ,8 // Rotation sensor

    // Right Tracking Wheel Ports (negative port will reverse it!)
    // ,{-3, -4} // 3 wire encoder
    // ,-9 // Rotation sensor
    */

    // Uncomment if tracking wheels are plugged into a 3 wire expander
    // 3 Wire Port Expander Smart Port
    // ,1
);




/**
  ___       _ _   _       _ _         
 |_ _|_ __ (_) |_(_) __ _| (_)_______ 
  | || '_ \| | __| |/ _` | | |_  / _ \
  | || | | | | |_| | (_| | | |/ /  __/
 |___|_| |_|_|\__|_|\__,_|_|_/___\___|
                                      
*/
void initialize()
{
  // ez::print_ez_template();
  pros::delay(500); // Wait for legacy ports configure.


  // Configure your chassis controls
  chassis.toggle_modify_curve_with_controller(false);
  chassis.set_active_brake(0.01); // Sets the active brake kP. We recommend 0.1.
  chassis.set_curve_default(5, 5);
  default_constants();
  exit_condition_defaults();
  IntakeActuator.tare_position();


  ez::as::auton_selector.add_autons({
    Auton("You know exactly what the fuck goin on", Frenzy_Rush_Mid),
    Auton("Cope Seethe", Default)
  });
  chassis.initialize();
  ez::as::initialize();

  pros::Task Catapult(Catapult_Down); //cata reloads constantly

}






/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  chassis.reset_pid_targets();               // Resets PID targets to 0
  chassis.reset_gyro();                      // Reset gyro position to 0
  chassis.reset_drive_sensor();              // Reset drive sensors to 0
  chassis.set_drive_brake(MOTOR_BRAKE_HOLD); // Set motors to hold.  This helps
                                             // autonomous consistency.
//ez::as::auton_selector.call_selected_auton();
//Frenzy_Rush_Mid();
//////////////////////////////
//the diff auton functions here ya go
/*
Intake_Auto(200);
Actuate_Auto("out");
pros::delay(250);
Catapult_Fire();
pros::delay(1000);
Intake_Auto(0);
Actuate_Auto("in");
wingsAuto(true);
pros::delay(2000);
Actuate_Auto("out");
pros::delay(250);
Intake_Auto(-100);
wingsAuto(false);
*/

 
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */


void opcontrol()
{

  chassis.set_drive_brake(MOTOR_BRAKE_COAST);
  pros::Task IntakeControlTask(Intake_Control);
  pros::Task IntakeActuation(Intake_Actuate);
  pros::Task wingActuation(wingsActuate);

  while (true)
  {

    chassis.arcade_flipped(ez::SINGLE);
	if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1))
    {
      Catapult_Fire();
    }

    pros::delay(20);
  }
}




















/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() { }





/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() { }