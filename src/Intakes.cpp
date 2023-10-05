#include "main.h"

void Intake_Control(void *)
{
  bool hopperFull = false;
  double hopperVal = 90;
  
  while (true)
  {
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
    {
      intake.move_velocity(600);
    }
    
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
    {
      intake.move_velocity(-600);

    }
    else
    {
      intake.move_velocity(0);
    }

    pros::delay(20);
  }   
}

void Intake_Actuate(void *)
{
  while(true)
  {
    if ((master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)))
    {
      
      IntakeActuator.move_velocity(100);
    }
    else if((master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)))
    {
      IntakeActuator.move_velocity(-100);
    }
    else
    {
      IntakeActuator.move_velocity(0);
    }


    pros::delay(20);
  }
}

void Intake_Auto(int x) {
    intake.move_velocity(x);
    
}

void Actuate_Auto(bool active)
{
  if(active = true)
  {
    IntakeActuator.move_absolute(180, 100);
  }
  else
  {
    IntakeActuator.move_absolute(0, 100);
  }
}

void wingsActuate(void *)
{
  bool wingsActive = false;
  while(true)
  {
    if ((master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)))
    {
      wingsActive = !wingsActive;
      wings.set_value(wingsActive);
      pros::delay(250);
    }


    pros::delay(20);
  }
}