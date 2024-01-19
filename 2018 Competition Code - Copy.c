#pragma config(Sensor, in1,    angle,          sensorPotentiometer)
#pragma config(Sensor, dgtl1,  rightDrive,     sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftDrive,      sensorQuadEncoder)
#pragma config(Motor,  port1,            ,             tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           rightFront,    tmotorVex393_MC29, openLoop, reversed, encoderPort, dgtl3)
#pragma config(Motor,  port3,           angleYCable,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           leftShooter,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           intake,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           divider,       tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           rightShooter,  tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           rightRear,     tmotorVex393_MC29, openLoop, encoderPort, dgtl1)
#pragma config(Motor,  port9,           leftFront,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          leftRear,      tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*


task main()
{

	while (true)
	{
		if(SensorValue[angle] <= 400)
		{
			motor[angleYCable] = 30;
			wait1Msec(20);
		}
		else
		{
			motor[angleYCable] = 0;
			startTask(shoot);
			wait1Msec(20);
		}
	}
}