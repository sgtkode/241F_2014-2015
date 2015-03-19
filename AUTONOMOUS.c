#pragma config(Sensor, in1,    armp,           sensorPotentiometer)
#pragma config(Sensor, in2,    dial,           sensorPotentiometer)
#pragma config(Sensor, in3,    gyro,           sensorGyro)
#pragma config(Sensor, dgtl1,  encoderRight,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  encoderLeft,    sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  pnsky,          sensorDigitalOut)
#pragma config(Sensor, dgtl6,  armultra,       sensorSONAR_cm)
#pragma config(Sensor, dgtl8,  intakeLimit,    sensorTouch)
#pragma config(Motor,  port2,           FR,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           BR,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           BL,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           FL,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           leftArm,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           rightArm,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           leftintake,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           rightintake,   tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "functions.c"



/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous
//
//	1st position: Blue Cube score
int firstPos = 600;
//	2nd position: Blue Skyrise score
int secondPos = 1000;
//	3rd position: Red Cube score
int thirdPos = 1520;
//	4th position: Red Skyrise score
int fourthPos = 2250;
//  5th position: Raise Arm
int fifthPos = 3000;
//
//
/////////////////////////////////////////////////////////////////////////////////////////






//---------------------------------Variables-------------------------------------------//

//Height in which to be at to obtain a
int skyriseHeight = 1950;
int l=30;
int h=118;

//-------------------------------------------------------------------------------------//




void autonomous()  //Programs are chosen by the value of the dial potentiometer.
{
	//DO NOT COPY THE TOP!!!

	int position=SensorValue[dial];
	SensorValue(encoderLeft)=0;
	//11111111111111111111111111111111111111111111111111111111111111111111111111
	//Blue side block || Put block on post turn around grab two and put them somewhere
	if (position>=firstPos&&position<secondPos)
	{
	}



	//2222222222222222222222222262222222222222222222222222222222222222222222222
	//Blue side skyrise
	else if (position>=secondPos&&position<thirdPos)
	{
	}


	//33333333333333333333333333333333333333333333333333333333333333333333333333
	//Red side cube
	else if(position>=thirdPos&&position<fourthPos)
	{
	}


	//444444444444444444444444444444444444444444444444444444444444444444444444444
	//Red side skyrise
	else if(position>=fourthPos&&position<fifthPos)
	{
	}


	//55555555555555555555555555555555555555555555555555555555555555
	//Raise arm up
	else if(position>=fifthPos)
	{
	}
}


task main()
{
	autonomous();
}
