#include "main.h"
#include "pros/adi.hpp"
#include "pros/motors.h"

//Extra Motor Ports
pros::Motor intake(19, MOTOR_GEARSET_18);


pros::Motor IntakeActuate1(15, MOTOR_GEARSET_36);
pros::Motor IntakeActuate2(16, MOTOR_GEARSET_36, true);
pros::Motor_Group IntakeActuator({IntakeActuate1, IntakeActuate2});

pros::Motor cata1(7, MOTOR_GEARSET_36);
pros::Motor cata2(4, MOTOR_GEARSET_36, true);
pros::Motor_Group catapult({cata1, cata2});


//adi ports
pros::ADIDigitalIn cataLimitSwitch('B');

pros::ADIDigitalOut wings('A');