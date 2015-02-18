#pragma config(Sensor, in1,    lineMiddle,     sensorLineFollower)
#pragma config(Sensor, in2,    lineLeft,       sensorLineFollower)
#pragma config(Sensor, in3,    lineRight,      sensorLineFollower)
#pragma config(Sensor, in4,    lineFarLeft,    sensorLineFollower)
#pragma config(Sensor, in5,    lineFarRight,   sensorLineFollower)
#pragma config(Sensor, dgtl1,  ultasonic,      sensorSONAR_cm)
#pragma config(Sensor, dgtl3,  encoderLeft,    sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  encoderRight,   sensorQuadEncoder)
#pragma config(Motor,  port1,           FL,            tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           BL,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           BR,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,            ,             tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port10,          FR,            tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                  Functions
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
//----------------------------------------------------------------------------------------
//
//                                    INDEX
//
//
//
/////////////////////////////////////////////////////////////////////////////////////////


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


void clearMotor()
{
	motor[FR]=0;
	motor[FL]=0;
	motor[BR]=0;
	motor[BL]=0;
}

void forwardTicks(int ticks)
{
		ticks=ticks;
		SensorValue[encoderLeft]=0;
    while(SensorValue(encoderLeft)<ticks)
    {
      motor[FL]=118;
    	motor[FR]=118;
    	motor[BL]=118;
    	motor[BR]=118;
    }
  motor[FL]=0;
	motor[FR]=0;
	motor[BL]=0;
	motor[BR]=0;
}

void forwardSeconds(int s)
{
      motor[FL]=118;
    	motor[FR]=118;
    	motor[BL]=118;
    	motor[BR]=118;
    	wait(s);
    	motor[FL]=0;
    	motor[FR]=0;
    	motor[BL]=0;
    	motor[BR]=0;
}

void backwardTicks(int ticks)
{
		ticks=ticks;
    nMotorEncoder[encoderLeft] = 0;
    int enctick=SensorValue(encoderLeft);
    while(enctick>-ticks)
    {
    motor[FL]=-118;
		motor[FR]=-118;
		motor[BL]=-118;
		motor[BR]=-118;
    }
	motor[FL]=0;
	motor[FR]=0;
	motor[BL]=0;
	motor[BR]=0;
}


void backwardSeconds(int s)
{
      motor[FL]=-118;
    	motor[FR]=-118;
    	motor[BL]=-118;
    	motor[BR]=-118;
    	wait(s);
    	motor[FL]=0;
    	motor[FR]=0;
    	motor[BL]=0;
    	motor[BR]=0;
}

void turnRightDegrees(float degree)
{
	degree=degree*10;
	float first=degree*.8;
	while(abs(SensorValue[gyro]) < first)
	{
      motor[FL]=118;
    	motor[FR]=-118;
    	motor[BL]=118;
    	motor[BR]=-118;
	}
	while(abs(SensorValue[gyro]) < degree)
	{
      motor[FL]=50;
    	motor[FR]=-50;
    	motor[BL]=50;
    	motor[BR]=-50;
	}
      motor[FL]=-5;
    	motor[FR]=5;
    	motor[BL]=-5;
    	motor[BR]=5;
  wait1Msec(250);
  clearMotor();
}




void turnLeftDegrees(float degree)
{
	float first=degree*.8;
	while(abs(SensorValue[gyro]) < first)
	{
      motor[FL]=-118;
    	motor[FR]=118;
    	motor[BL]=-118;
    	motor[BR]=118;
	}
	while(abs(SensorValue[gyro]) < degree)
	{
      motor[FL]=-50;
    	motor[FR]=50;
    	motor[BL]=-50;
    	motor[BR]=50;
	}
      motor[FL]=5;
    	motor[FR]=-5;
    	motor[BL]=5;
    	motor[BR]=-5;
  wait1Msec(250);
  clearMotor();
}



void turnRightTicks(int ticks)
{
	SensorValue[encoderLeft]=0;
	while(SensorValue[encoderLeft]<ticks)
	{
		motor[FL]=118;
		motor[BL]=118;
		motor[FR]=-118;
		motor[BR]=-118;
	}
}


void turnLeftTicks(int ticks)
{
	SensorValue[encoderRight]=0;
	while(SensorValue[encoderRight]<ticks)
	{
		motor[FL]=-118;
		motor[BL]=-118;
		motor[FR]=118;
		motor[BR]=118;
	}
}


void turnRightSeconds(float seconds)
{
	motor[FL]=118;
	motor[BL]=118;
	motor[FR]=-118;
	motor[BR]=-118;
	wait(seconds);
	clearMotor();
}
void turnLeftSeconds(float seconds)
{
	motor[FL]=-118;
	motor[BL]=-118;
	motor[FR]=118;
	motor[BR]=118;
	wait(seconds);
	clearMotor();
}

/*
void raiseArmTicks(int ticks)
{
	while(SensorValue[armp]<ticks)
	{
		motor[leftArm]=118;
		motor[rightArm]=118;
	}
	motor[leftArm]=0;
	motor[rightArm]=0;
}


void raiseArmSeconds(float s)
{
		motor[leftArm]=118;
		motor[rightArm]=118;
		wait(s);
		motor[leftArm]=0;
		motor[rightArm]=0;
}



void lowerArmTicks(int ticks)
{
	while(SensorValue[armp]>ticks)
	{
		motor[leftArm]=-118;
		motor[rightArm]=-118;

	}
	motor[leftArm]=0;
	motor[rightArm]=0;
}



void lowerArmSeconds(float seconds)
{
      motor[leftArm]= -118;
			motor[rightArm]= -118;
   		wait(seconds);
    	motor[leftArm]= -0;
			motor[rightArm]= -0;
}







void raiseIntakeSeconds(float s)
{

	motor[leftintake]=118;
	motor[rightintake]=118;
	wait(s);
	motor[leftintake]=0;
	motor[rightintake]=0;
}


void lowerIntakeSeconds(float s)
{
	motor[leftintake]=118;
	motor[rightintake]=118;
	wait(s);
	motor[leftintake]=0;
	motor[rightintake]=0;
}

void armto(int point)
{
	target=point;
}




task armcontrol()
{
	while(true)
	{
		error=target-SensorValue[armp];
		errorSum+=error;
		motor[leftArm]= error*pGain+errorSum*iGain;
		motor[rightArm]= error*pGain+errorSum*iGain;
	}
}
*/







void autonomous()
{



	//Completely clear out any previous sensor readings by setting the port to "sensorNone"
 SensorType[in6] = sensorNone;
 wait1Msec(1000);
 //Reconfigure Analog Port 8 as a Gyro sensor and allow time for ROBOTC to calibrate it
 SensorType[in8] = gyro;
 wait1Msec(2000);






 turnRightDegrees(90);

}

task main()
{
	autonomous();
}