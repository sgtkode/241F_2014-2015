#pragma config(Sensor, in1,    armp,           sensorPotentiometer)
#pragma config(Sensor, in2,    dial,           sensorPotentiometer)
#pragma config(Sensor, in3,    gyro,           sensorGyro)
#pragma config(Sensor, dgtl1,  encoderRight,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  encoderLeft,    sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  armUltra,       sensorSONAR_cm)
#pragma config(Sensor, dgtl7,  intakeLimit,    sensorTouch)
#pragma config(Sensor, dgtl8,  pnr,            sensorDigitalIn)
#pragma config(Sensor, dgtl9,  pnl,            sensorDigitalIn)
#pragma config(Motor,  port2,           FR,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           BR,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           BL,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           FL,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           leftArm,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           rightArm,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           leftintake,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           rightintake,   tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*/

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                  Functions
//
// This file contains functions used by both the autonomous and competition files
//
//----------------------------------------------------------------------------------------
//
//                                    INDEX
//
// drive: gives the controller control of the wheels.
// clearmotor: sets all drivemotors to 0.
// forwardd: Move forward by a certain amount of ticks.
// forwards: Move forward by a duration of time.
// backwardd: Move backward a certain amount of ticks.
// backwards:Move backward a duration of time.
// correctturn: Put a certain amount of degrees and the robot gets the most efficiant way to turn done in ticks.
// turnright: turn right by ticks.
// turnleft: turn left by ticks.
// turnr:turn right for a duration of time.
// turnl:turn left for a duration of time.
// raisearm: raise arm a certain amount of ticks.
// lowerarm: lower arm for a duration of time.
// increment: Move the arm to a specified level.
// raiseintake: Raise the intake to pick up cubes.
// lowerintake: lower the intake to pick up cubes.
//
//
/////////////////////////////////////////////////////////////////////////////////////////

int base=1563;
float target=base;
/*
int base=1563;
float target=base; //PID VALUES
>>>>>>> ad6753eaba8958f75940cd8fed654bcfceda7902
float pGain=.3;
float iGain=.2;
float error=target-SensorValue[armp];
float errorSum=0;
<<<<<<< HEAD
//bottom=1530   top=3700
float turn;
float arm;
float intake;
=======
*/


//bottom=1530   top=3700



/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 DRIVETRAIN
//
/////////////////////////////////////////////////////////////////////////////////////////

/**
* @void drive
*
* @desc gives drive control to VexNET controller
*
* @args  half boolean  determines if motors should be running at half speed
*/
void drive(bool half)
{

			if (half==false)//Check if drive toggles half speed.
			{
				motor[BR] = vexRT[Ch2]; //give drive direct control.
				motor[FR] = vexRT[Ch2];
				motor[BL] = vexRT[Ch3];
				motor[FL] = vexRT[Ch3];
			}
			else if(half ==true)
			{
				motor[BR] = vexRT[Ch2]/3;//give drive control but all motor maxes are a third of their orignal max.
				motor[FR] = vexRT[Ch2]/3;
				motor[BL] = vexRT[Ch3]/3;
				motor[FL] = vexRT[Ch3]/3;
			}
}


/**
* @void clearMotor
*
* @desc clears all the motors
*
* @args  N/A
*/
void clearMotor()
{
	motor[FR]=0;
	motor[FL]=0;
	motor[BR]=0;
	motor[BL]=0;
}

/**
* @void fullStop
*
* @desc completely stops all motors without drift
*
* @args  N/A
*/
void fullStop()
{
	int FR = motor[FR];
	int FL = motor[FL];
	int BR = motor[BR];
	int BL = motor[BL];
	motor[FR]=FR*-.1;
	motor[FL]=FL*-.1;
	motor[BR]=BR*-.1;
	motor[BL]=BL*-.1;
	wait1MSec(150);
	clearMotor();
}


/**
* @void forwardTicks
*
* @desc moves bot forward a given tick amount
*
* @args  ticks  int    amount of ticks to move forward
*				 x      float  speed of motors
*/
void forwardTicks(int ticks, float x = 118)
{
	ticks=ticks;
	SensorValue[encoderLeft]=0;
	SensorValue[encoderRight]=0;
	motor[FL]=50;
	motor[FR]=50;
	motor[BL]=50;
	motor[BR]=50;
  while(SensorValue(encoderLeft) < ticks && SensorValue[encoderRight] < ticks)
  {
    if( abs(SensorValue[encoderLeft]) >= abs(SensorValue[encoderRight])+10 ){
			motor[FL]=x*.8;
    	motor[FR]=x;
    	motor[BL]=x*.8;
    	motor[BR]=x;
		} else if( abs(SensorValue[encoderRight]) >= abs(SensorValue[encoderLeft])+10 ){
			motor[FL]=x;
    	motor[FR]=x*.8;
    	motor[BL]=x;
    	motor[BR]=x*.8;
		} else {
			motor[FL]=x;
    	motor[FR]=x;
    	motor[BL]=x;
    	motor[BR]=x;
		}
  }
  fullStop();
}


/**
* @void backwardsTicks
*
* @desc moves bot backwards for a given amount of ticks
*
* @args  ticks  int    amount of ticks to move forward
*				 x      float  speed of motors
*/
void backwardTicks(int ticks, float x=118)
{
	ticks=ticks;
	SensorValue[encoderLeft]=0;
	SensorValue[encoderRight]=0;
  while(SensorValue(encoderLeft) < ticks && SensorValue[encoderRight] < ticks)
  {
  	if( abs(SensorValue[encoderLeft]) >= abs(SensorValue[encoderRight])+10 ){
			motor[FL]=-x*.8;
    	motor[FR]=-x;
    	motor[BL]=-x*.8;
    	motor[BR]=-x;
		} else if( abs(SensorValue[encoderRight]) >= abs(SensorValue[encoderLeft])+10 ){
			motor[FL]=-x;
    	motor[FR]=-x*.8;
    	motor[BL]=-x;
    	motor[BR]=-x*.8;
		} else {
			motor[FL]=-x;
    	motor[FR]=-x;
    	motor[BL]=-x;
    	motor[BR]=-x;
		}
  }
	fullStop();
}


/**
* @void forwardSeconds
*
* @desc moves bot forward for a given amount of seconds
*
* @args  s  int    amount of seconds to move forward
				 x  float  speed of motors
*/
void forwardSeconds(float s,float x=118)
{
  motor[FL]=x;
	motor[FR]=x;
	motor[BL]=x;
	motor[BR]=x;
	wait1Msec(s*1000);
	fullStop();
}


/**
* @void backwardSeconds
*
* @desc moves bot backwards for a given amount of seconds
*
* @args  s  int    amount of seconds to move forward
*				 x  float  speed of motors
*/
void backwardSeconds(float s, float x=118)
{
  motor[FL]=-x;
	motor[FR]=-x;
	motor[BL]=-x;
	motor[BR]=-x;
	wait1Msec(s*1000);
	fullStop();
}


/**
* @void turnRightDegrees
*
* @desc turns bot right a given amount of degrees
*
* @args  degree  int    amount of degrees to turn right
*				 x       float  speed of motors
*/
void turnRightDegrees(float degree, float x=118)
{
	int initial= abs(SensorValue[gyro]);
	float first=degree*.8;
	degree=degree*10;

	SensorValue[encoderLeft] = 0;
	SensorValue[encoderRight] = 0;

	while(abs(SensorValue[gyro]) < initial+first)
	{
		if( abs(SensorValue[encoderLeft]) >= abs(SensorValue[encoderRight])+5 ){
			motor[FL]=x*.8;
    	motor[FR]=-x;
    	motor[BL]=x*.8;
    	motor[BR]=-x;
		} else if( abs(SensorValue[encoderRight]) >= abs(SensorValue[encoderLeft])+5 ){
			motor[FL]=x;
    	motor[FR]=-x*.8;
    	motor[BL]=x;
    	motor[BR]=-x*.8;
		} else {
			motor[FL]=x;
    	motor[FR]=-x;
    	motor[BL]=x;
    	motor[BR]=-x;
		}
	}
	while(abs(SensorValue[gyro]) < initial+degree)
	{
		if( abs(SensorValue[encoderLeft]) >= abs(SensorValue[encoderRight])+5 ){
			motor[FL]=x*.5*.8;
    	motor[FR]=-x*.5;
    	motor[BL]=x*.5*.8;
    	motor[BR]=-x*.5;
		} else if( abs(SensorValue[encoderRight]) >= abs(SensorValue[encoderLeft])+5 ){
			motor[FL]=x*.5;
    	motor[FR]=-x*.5*.8;
    	motor[BL]=x*.5;
    	motor[BR]=-x*.5*.8;
		} else {
			motor[FL]=x*.5;
    	motor[FR]=-x*.5;
    	motor[BL]=x*.5;
    	motor[BR]=-x*.5;
		}
	}
  fullStop();
}


/**
* @void turnLeftDegrees
*
* @desc turns bot left a given amount of degrees
*
* @args  degree  int    amount of degrees to turn left
*				 x       float  speed of motors
*/
void turnLeftDegrees(float degree, float x=118)
{
	int initial= abs(SensorValue[gyro]);
	float first=degree*.8;
	degree=degree*10;

	SensorValue[encoderLeft] = 0;
	SensorValue[encoderRight] = 0;

	while(abs(SensorValue[gyro]) < initial+first)
	{
			if( abs(SensorValue[encoderLeft]) >= abs(SensorValue[encoderRight])+5 ){
				motor[FL]=-x*.8;
	    	motor[FR]=x;
	    	motor[BL]=-x*.8;
	    	motor[BR]=x;
			} else if( abs(SensorValue[encoderRight]) >= abs(SensorValue[encoderLeft])+5 ){
				motor[FL]=-x;
	    	motor[FR]=x*.8;
	    	motor[BL]=-x;
	    	motor[BR]=x*.8;
			} else {
				motor[FL]=-x;
	    	motor[FR]=x;
	    	motor[BL]=-x;
	    	motor[BR]=x;
			}
	}
	while(abs(SensorValue[gyro]) < initial+degree)
	{
		if( abs(SensorValue[encoderLeft]) >= abs(SensorValue[encoderRight])+5 ){
			motor[FL]=-x*.5*.8;
    	motor[FR]=x*.5;
    	motor[BL]=-x*.5*.8;
    	motor[BR]=x*.5;
		} else if( abs(SensorValue[encoderRight]) >= abs(SensorValue[encoderLeft])+5 ){
			motor[FL]=-x*.5;
    	motor[FR]=x*.5*.8;
    	motor[BL]=-x*.5;
    	motor[BR]=x*.5*.8;
		} else {
			motor[FL]=-x*.5;
    	motor[FR]=x*.5;
    	motor[BL]=-x*.5;
    	motor[BR]=x*.5;
		}
	}
  fullStop();
}



/**
* @void turnRightTicks
*
* @desc turns bot right a given amount of ticks
*
* @args  ticks   int    amount of ticks to turn right
*				 x       float  speed of motors
*/
void turnRightTicks(int ticks, float x=118)
{
	SensorValue[encoderLeft]=0;
	while(SensorValue[encoderLeft]<ticks)
	{
		if( abs(SensorValue[encoderLeft]) >= abs(SensorValue[encoderRight])+5 ){
			motor[FL]=x*.8;
    	motor[FR]=-x;
    	motor[BL]=x*.8;
    	motor[BR]=-x;
		} else if( abs(SensorValue[encoderRight]) >= abs(SensorValue[encoderLeft])+5 ){
			motor[FL]=x;
    	motor[FR]=-x*.8;
    	motor[BL]=x;
    	motor[BR]=-x*.8;
		} else {
			motor[FL]=x;
    	motor[FR]=-x;
    	motor[BL]=x;
    	motor[BR]=-x;
		}
	}
	fullStop();
}


/**
* @void turnLeftTicks
*
* @desc turns bot left a given amount of ticks
*
* @args  ticks   int    amount of ticks to turn left
*				 x       float  speed of motors
*/
void turnLeftTicks(int ticks, float x=118)
{
	SensorValue[encoderLeft]=0;
	while(SensorValue[encoderLeft]<ticks)
	{
		if( abs(SensorValue[encoderLeft]) >= abs(SensorValue[encoderRight])+5 ){
			motor[FL]=-x*.8;
    	motor[FR]=x;
    	motor[BL]=-x*.8;
    	motor[BR]=x;
		} else if( abs(SensorValue[encoderRight]) >= abs(SensorValue[encoderLeft])+5 ){
			motor[FL]=-x;
    	motor[FR]=x*.8;
    	motor[BL]=-x;
    	motor[BR]=x*.8;
		} else {
			motor[FL]=-x;
    	motor[FR]=x;
    	motor[BL]=-x;
    	motor[BR]=x;
		}
	}
	fullStop();
}


/**
* @void turnRightSeconds
*
* @desc turns bot right a given amount of seconds
*
* @args  seconds   int    amount of seconds to turn right
*				 x         float  speed of motors
*/
void turnRightSeconds(float seconds, float x=118)
{
	motor[FL]=x;
	motor[BL]=x;
	motor[FR]=-x;
	motor[BR]=-x;
	wait1Msec(seconds*1000);
	fullStop();
}

/**
* @void turnLeftSeconds
*
* @desc turns bot left a given amount of seconds
*
* @args  seconds   int    amount of seconds to turn left
*				 x         float  speed of motors
*/
void turnLeftSeconds(float seconds, float x=118)
{
	motor[FL]=-x;
	motor[BL]=-x;
	motor[FR]=x;
	motor[BR]=x;
	wait1Msec(seconds*1000);
	fullStop();
}



/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 ARM
//
/////////////////////////////////////////////////////////////////////////////////////////

/**
* @void raiseArmTicks
*
* @desc raises arm a given amount of ticks
*
* @args  ticks   int    amount of ticks to raise arm
*				 x       float  speed of motors
*/
void raiseArmTicks(int ticks,float x=118)
{
	while(SensorValue[armp]<ticks)
	{
		motor[leftArm]=-x;
		motor[rightArm]=-x;
	}
	motor[leftArm]=0;
	motor[rightArm]=0;
}

/**
* @void lowerArmTicks
*
* @desc lowers arm a given amount of ticks
*
* @args  ticks   int    amount of ticks to lower arm
*				 x       float  speed of motors
*/
void lowerArmTicks(int ticks,float x=118)
{
	while(SensorValue[armp]>ticks)
	{
		motor[leftArm]=x;
		motor[rightArm]=x;
	}
	motor[leftArm]=0;
	motor[rightArm]=0;
}

/**
* @void raiseArmSeconds
*
* @desc raises arm a given amount of seconds
*
* @args  s   int    amount of seconds to raise arm
*				 x   float  speed of motors
*/
void raiseArmSeconds(float s, float x=118)
{
	motor[leftArm]=x;
	motor[rightArm]=x;
	wait1Msec(s*1000);
	motor[leftArm]=0;
	motor[rightArm]=0;
}


/**
* @void lowerArmSeconds
*
* @desc lowers arm a given amount of seconds
*
* @args  s   int    amount of seconds to raise arm
*				 x   float  speed of motors
*/
void lowerArmSeconds(float seconds, float x=118)
{
  motor[leftArm]= -x;
	motor[rightArm]= x;
	wait1Msec(seconds*1000);
	motor[leftArm]= 0;
	motor[rightArm]= 0;
}

/**
* @void raiseIntakeSeconds
*
* @desc raises intake a given amount of seconds
*
* @args  s   int    amount of seconds to raise intake
*/
void raiseIntakeSeconds(float s)
{
	motor[leftintake]=118;
	motor[rightintake]=118;
	wait1Msec(s*1000);
	motor[leftintake]=0;
	motor[rightintake]=0;
}

/**
* @void lowerIntakeSeconds
*
* @desc lowers intake a given amount of seconds
*
* @args  s   int    amount of seconds to lower intake
*/
void lowerIntakeSeconds(float s)
{
	motor[leftintake]=-118;
	motor[rightintake]=-118;
	wait1Msec(s*1000);
	motor[leftintake]=0;
	motor[rightintake]=0;
}

/**
* @void raiseIntake
*
* @desc raises intake to highest point
*
* @args  N/A
*/
void raiseIntake()
{
	while(SensorValue[intakeLimit] !=1)
	{
		motor[leftintake]=118;
		motor[rightintake]=118;
	}
	motor[leftintake]=0;
	motor[rightintake]=0;
}


/**
* @void lowerIntake
*
* @desc lowers intake to lowest point
*
* @args  N/A
*/
void lowerIntake()
{
	while(SensorValue[intakeLimit] !=1)
	{
		motor[leftintake]=-118;
		motor[rightintake]=-118;
	}
	motor[leftintake]=0;
	motor[rightintake]=0;
}


/**
* @task armcontrol
*
* @desc raises or lowers arm to certain point
*       using PI loop
*
* @args target float tick value target for arm
*/
task armcontrol(float target){
	// 1563:
		//float target = 1563; //pot val at scoring height pos0
	float pGain = .3;
	float iGain = .2;
	float error = target-SensorValue[armp];
	float errorSum=0;

	while(true){
		error=target-SensorValue[armp];
		errorSum+=error;
		motor[leftArm]= error*pGain+errorSum*iGain;
		motor[rightArm]= error*pGain+errorSum*iGain;
	}
}



/**
* ###### NOT FINISHED ######
* @void retrieve
*
* @desc gets skyrise
*
*
* @args  N/A
*/
void retrieve()
{
	float distanceFromSkyrise=12; //THE NUMBER OF CENTIMETERS THE ULTRASONIC MUST BE TO LOWER THE ARM AND BE ON TARGET
	raiseArmTicks(1950);
	while(SensorValue[armUltra]>30){
		motor[FL]=-80;
		motor[BL]=-80;
		motor[FR]=80;
		motor[FR]=80;
	}
	turnRightSeconds(.04,80);
	//float distanceFromCenter=sqrt(SensorValue[armUltra]^2+3.5^2);
	float turn=asin(3.5/SensorValue[armUltra]);
	turnLeftDegrees(turn);
	float temp=SensorValue[armUltra];
	float distanceForward=temp-distanceFromSkyrise;
	forwardTicks(distanceForward);//The number of ticks in
}
