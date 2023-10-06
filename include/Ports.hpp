#include "api.h"
#include "pros/adi.hpp"

//Extra Motor Ports

extern pros::Motor IntakeActuate1;
extern pros::Motor IntakeActuate2;
extern pros::Motor_Group IntakeActuator;
extern pros::Motor intake;
extern pros::Motor cata1;
extern pros::Motor cata2;
extern pros::Motor_Group catapult;

//adi ports
extern pros::ADIDigitalIn cataLimitSwitch;
extern pros::ADIDigitalOut wings;