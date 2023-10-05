#include "main.h"
#include "pros/misc.h"
#include "pros/rtos.hpp"

bool firing;


void Catapult_Control(void *) {
  while (true) {
    
    catapult.move_velocity(100);
    
    if (cataLimitSwitch.get_value() == 1) {
    
      catapult.move_velocity(0);
    
    
    }

    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      
      catapult.move_velocity(100);
    
      pros::delay(250);
      
      catapult.tare_position();

      
    }

    pros::delay(20);
 
  }

}
 

void Catapult_Down(void *) {

  while (true) {

    if (pros::competition::is_autonomous)
    {
      if (firing) {
        catapult.move_velocity(60);
        pros::delay(300);
        catapult.tare_position();
        firing = false;
      } else {
        catapult.move_velocity((-0.0135135135*cata1.get_position() + 60));
        if (cataLimitSwitch.get_value() == 1) {
          catapult.move_velocity(0);
        }    
      }
    }



    else
    {
      catapult.move_velocity(60);
      if (cataLimitSwitch.get_value() == 1) {
        catapult.move_velocity(0);
      }
      if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) { 
        catapult.move_velocity(60);
        pros::delay(250);
        catapult.tare_position();
      }
    }


    pros::delay(20);
  
  }

}

void Catapult_Fire(void) {
  firing = true;
}

// void BoostOff(void *) {

//  while(true) {

//   if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {

//     BoosterShot.set_value(true);

//   }

//  }
  
// }
