#pragma config(Sensor, in1,    angle,          sensorPotentiometer)
#pragma config(Sensor, dgtl1,  rightRear,      sensorNone)
#pragma config(Sensor, dgtl3,  leftFront,      sensorNone)
#pragma config(Sensor, dgtl5,  leftRear,       sensorNone)
#pragma config(Sensor, dgtl7,  rightFront,     sensorNone)
#pragma config(Motor,  port2,           leftY,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftT,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           angle,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           shooterY,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           intake,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           rightT,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           rightY,        tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"



/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
void Drive(int left, int right)
{
	motor[leftT] = left;
	motor[leftY] = left;
	motor[rightT] = right;
	motor[rightY] = right;
	wait1Msec(20);
}


void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
	motor[shooterY] = 127;
	wait10Msec(400);
	stopTask(autonomous);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
int t;
task usercontrol()
{
  // User control code here, inside the loop
	while(true)
	{
		{
			t = 25;

		if(vexRT[Btn7L] == 1)
		{
			{
				Drive(-40, 60);
				wait1Msec(t);
			}
		}
		else if(vexRT[Btn7R] == 1)
		{
			{
				Drive(40, -60);
				wait1Msec(t);
			}
		}
		else if(vexRT[Btn7U] == 1)
		{
			{
				Drive(40, 60);
			}
		}
		else if(vexRT[Btn7D] == 1)
		{
			{
				Drive(-40,-60);
			}
		}
		else
		{
			{
				Drive(vexRT[Ch3], vexRT[Ch2]);
			}
		}

		if(vexRT[Btn6UXmtr2] == 1)
		{
			{
				motor[shooterY] = 127;
				wait1Msec(t);
			}
		}
		else
		{
			{
				motor[shooterY] = 15;
				wait1Msec(t);
			}
		}
		if(vexRT[Btn5UXmtr2] == 1)
		{
			{
				motor[angle] = 40;
				wait1Msec(t);
			}
		}
		else if(vexRT[Btn5DXmtr2] == 1)
		{
			{
				motor[angle] = -15;
				wait1Msec(t);
			}
		}
		else if(vexRT[Btn5DXmtr2] == 0)
		{
			{
				motor[angle] = 15;
				wait1Msec(t);
			}
		}
		else if(vexRT[Btn8UXmtr2] == 1 && SensorValue[angle] >= 100)
		{
			motor[angle] = 40;
			wait1Msec(t);
		}
		else if(vexRT[Btn8RXmtr2] == 1 && SensorValue[angle] >= 120)
		{
			motor[angle] = 40;
			wait1Msec(t);
		}
		else
		{
			motor[angle] = 15;
			wait1Msec(t);
		}
		if(vexRT[Btn7UXmtr2] == 1)
		{
			motor[intake] = 127;
			wait1Msec(t);
		}
		else if(vexRT[Btn7RXmtr2] == 1)
		{
			motor[intake] = 0;
			wait1Msec(t);
		}
	}
}
}
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    // Remove this function call once you have "real" code.
