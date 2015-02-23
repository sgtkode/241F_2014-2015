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
#pragma config(Motor,  port6,           leftArm,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           rightArm,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           leftintake,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           rightintake,   tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!
#include "functions.c"

int skyriseHeight = 1950;
int firstPos = 600;
int secondPos = 1000;
int thirdPos = 1520;
int fourthPos = 2250;
int fifthPos = 3000;

int heights[50];

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Pre-Autonomous
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
 bStopTasksBetweenModes = true;
}







/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous
//
//
//	1st position:Blue Cube score
//	2nd position:Blue Skyrise score
//	3rd position:Red Cube score
//	4th position:Red Skyrise score
//
//
/////////////////////////////////////////////////////////////////////////////////////////


task autonomous(){  //Programs are chosen by the value of the dial potentiometer.
		//DO NOT COPY THE TOP!!!

	int position=fifthPos; //SensorValue[dial];
	SensorValue(encoderLeft)=0;
	//startTask(armcontrol);
	SensorType[in3]=sensorNone;
	SensorType[in3]=sensorGyro;
	//11111111111111111111111111111111111111111111111111111111111111111111111111
	//Blue side block || Put block on post turn around grab two and put them somewhere
		if (position>=firstPos&&position<secondPos)
		{
			backwardSeconds(.33);
			raiseArmSeconds(1);
			lowerIntakeSeconds(1);//Drop Cube on post
			backwardSeconds(.2);
			lowerArmSeconds(1);
			forwardSeconds(.1);
			motor[FR]=118;
			motor[BR]=118;
			wait1Msec(.4*1000);
			clearMotor();
			turnLeftSeconds(.63);
			forwardSeconds(.12);
			motor[FR]=118;
			motor[BR]=118;
			wait1Msec(.1*1000);
			clearMotor();
			wait1Msec(.5*1000);
			raiseIntakeSeconds(1.3); //pick up cube on crosshair
			backwardSeconds(.3);
			turnLeftSeconds(.18);
			forwardSeconds(.6);
			wait1Msec(.5*1000);
			raiseIntakeSeconds(1.2); //Pick up second cube


			//To put on post
			backwardSeconds(.7);
			turnLeftSeconds(1.15);
			backwardSeconds(.5);
			raiseArmTicks(2500);
			forwardSeconds(1.1);
			lowerIntakeSeconds(.3);
			forwardSeconds(.1);
			lowerIntakeSeconds(2);


			//To put on skyrise
			/*backwardSeconds(.5);
			turnRightSeconds(.6);
			backwardSeconds(.4);
			turnRightSeconds(.2);
			raiseArmTicks(1800);
			lowerIntakeSeconds(5);
			*/
		}


		//2222222222222222222222222222222222222222222222222222222222222222222222222
		//Blue side skyrise
		else if (position>=secondPos&&position<thirdPos)
		{
			turnRightSeconds(.13);

			backwardSeconds(.6,90);
			raiseArmTicks(1950);
			forwardSeconds(.67,90);
			lowerArmSeconds(.6);
			raiseArmTicks(2300);
			backwardSeconds(.4,90);

			motor[BL]=60;
			motor[FL]=60;
			motor[BR]=-60;
			motor[FR]=-60;
			wait1Msec(.7*1000);
			clearMotor();

			forwardSeconds(.2,90);
			lowerArmSeconds(1.5);
			motor[BL]=45;
			motor[FL]=45;
			motor[BR]=45;
			motor[FR]=45;
			motor[leftArm]=118;
			motor[rightArm]=118;
			wait1Msec(.3*1000);
			clearMotor();
			raiseArmSeconds(1);
			//backwardSeconds(.15,90);//end of first cube


			motor[BL]=-100;
			motor[FL]=-100;
			wait1Msec(.5*1000);
			motor[BL]=-100;
			motor[FL]=-100;
			motor[BR]=100;
			motor[FR]=100;
			wait1Msec(.15*1000);
			clearMotor();

			/*
			wait(.2);
			forwardSeconds(.2,90);
			lowerArmSeconds(1);
			raiseArmTicks(2300);
			motor[BR]=-100;
			motor[FR]=-100;
			wait(.75);
			motor[BL]=100;
			motor[FL]=100;
			wait(.2);
			clearMotor();
			forwardSeconds(.25);
			lowerArmSeconds(1);
			raiseArmSeconds(1);
			*/
		}


		//33333333333333333333333333333333333333333333333333333333333333333333333333
		//Red side cube
		else if(position>=thirdPos&&position<fourthPos)
		{
			backwardSeconds(.33);
			raiseArmSeconds(1);
			lowerIntakeSeconds(1);//Drop Cube on post
			backwardSeconds(.2);
			lowerArmSeconds(1);
			forwardSeconds(.1);
			motor[FL]=118;
			motor[BL]=118;
			wait1Msec(.4*1000);
			clearMotor();
			turnRightSeconds(.63);
			forwardSeconds(.12);
			motor[FL]=118;
			motor[BL]=118;
			wait1Msec(.1*1000);
			clearMotor();
			wait1Msec(.5*1000);
			raiseIntakeSeconds(1.3); //pick up cube on crosshair
			backwardSeconds(.3);
			turnRightSeconds(.18);
			forwardSeconds(.6);
			wait1Msec(.5*1000);
			raiseIntakeSeconds(1.2); //Pick up second cube


			//To put on post
			backwardSeconds(.7);
			turnRightSeconds(1.15);
			backwardSeconds(.5);
			raiseArmTicks(2500);
			forwardSeconds(1.1);
			lowerIntakeSeconds(.3);
			forwardSeconds(.1);
			lowerIntakeSeconds(2);


			//To put on skyrise
			/*backwardSeconds(.5);
			turnRightSeconds(.6);
			backwardSeconds(.4);
			turnRightSeconds(.2);
			raiseArmTicks(1800);
			lowerIntakeSeconds(5);
			*/
		}


		//444444444444444444444444444444444444444444444444444444444444444444444444444
		//Red side skyrise
		else if(position>=fourthPos&&position<fifthPos)
		{
			turnLeftSeconds(.13);
			turnRightSeconds(.1);
			backwardSeconds(.6,90);
			raiseArmTicks(1950);
			forwardSeconds(.62,90);
			lowerArmSeconds(.6);
			raiseArmTicks(2300);
			backwardSeconds(1,90);

			motor[BL]=-60;
			motor[FL]=-60;
			motor[BR]=60;
			motor[FR]=60;
			wait1Msec(.5*1000);
			clearMotor();

			forwardSeconds(.45,90);
			lowerArmSeconds(1.5);
			motor[BL]=-45;
			motor[FL]=-45;
			//motor[BR]=45;
			//motor[FR]=45;
			motor[leftArm]=118;
			motor[rightArm]=118;
			wait1Msec(.3*1000);
			clearMotor();
			motor[BL]=-45;
			motor[FL]=-45;
			wait1Msec(.5*1000);
			backwardSeconds(.2);
			raiseArmSeconds(1);
			//backwardSeconds(.15,90);//end of first cube


			motor[BR]=-100;
			motor[FR]=-100;
			wait1Msec(.5*1000);
			motor[BL]=100;
			motor[FL]=100;
			motor[BR]=-100;
			motor[FR]=-100;
			wait1Msec(.15*1000);
			clearMotor();

			/*
			wait(.2);
			forwardSeconds(.2,90);
			lowerArmSeconds(1);
			raiseArmTicks(2300);
			motor[BL]=-100;
			motor[FL]=-100;
			wait(.75);
			motor[BR]=100;
			motor[FR]=100;
			wait(.2);
			clearMotor();
			forwardSeconds(.25);
			lowerArmSeconds(1);
			raiseArmSeconds(1);
			*/
		}


		//55555555555555555555555555555555555555555555555555555555555555
		//Raise arm up
		else if(position>=fifthPos){

			turnLeftDegrees(90,127);
		}
}



/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol(){
	bool half=false;
	int buttonToggleState8r = 0;//half speed
  int buttonPressed8r = 0;
	int buttonToggleState7l = 0;//pneumatics
  int buttonPressed7l = 0;

	//startTask(armcontrol);
	while (true) {
		if(bVEXNETActive){

			//Toggle half speed---------------------------------------------------------------
			if( vexRT[ Btn7L ] == 1 ) {
	      if( ! buttonPressed7l ) {

	      	// change the toggle state
	      	buttonToggleState7l = 1 - buttonToggleState7l;

	        // Note the button is pressed
	        buttonPressed7l = 1;
	      }
	  	} else {

		    // the button is not pressed
		    buttonPressed7l = 0;
		  }

		  // Now do something with our toggle flag
	    if( buttonToggleState7l ) {
	      half=true;
	    } else {
	      half=false;
		  }

	   //Toggle pneumatics------------------------------------------------
		  if( vexRT[ Btn8R ] == 1 )
	    {
	      if( ! buttonPressed8r )
	      {
	      	// change the toggle state
	      	buttonToggleState8r = 1 - buttonToggleState8r;

	        // Note the button is pressed
	        buttonPressed8r = 1;
	      }
	    }
	    else
	    {
		    // the button is not pressed
		    buttonPressed8r = 0;
		  }
	    // Now do something with our toggle flag
	    if( buttonToggleState8r )
	    {
	      SensorValue[pnr]=1;
	      SensorValue[pnl]=1;
	    }
	    else
	    {
	      SensorValue[pnr]=0;
	      SensorValue[pnl]=0;
		  }




			//DRIVE-----------------------------------------------------
			if (half==false){ //Check if drive toggles half speed.
				//give drive direct control.
				motor[BR] = vexRT[Ch2];
				motor[FR] = vexRT[Ch2];
				motor[BL] = vexRT[Ch3];
				motor[FL] = vexRT[Ch3];
			} else if(half ==true) {
				//give drive control but all motor maxes are a third of their orignal max.
				motor[BR] = vexRT[Ch2]/3;
				motor[FR] = vexRT[Ch2]/3;
				motor[BL] = vexRT[Ch3]/3;
				motor[FL] = vexRT[Ch3]/3;
			}


	  	//ARM MOTION----------------------------
			if(vexRT[Btn5D] == true){
      	/*if(nMotorEncoder(rightArm) > nMotorEncoder(leftArm)){
        	motor[rightArm] = 127/2;
        	motor[leftArm] = 127;
      	}else if(nMotorEncoder(rightArm) < nMotorEncoder(leftArm)){
        	motor[rightArm] = 127;
        	motor[leftArm] = 127/2;
      	}else{*/
        	motor[rightArm] = 126;
        	motor[leftArm] = 126;
      	//}
    	}else if(vexRT[Btn6D] == true){
      	/*if(nMotorEncoder(rightArm) > nMotorEncoder(leftArm)){
        	motor[rightArm] = -10;
        	motor[leftArm] = -20;
      	}else if(nMotorEncoder(rightArm) < nMotorEncoder(leftArm)){
        	motor[rightArm] = -20;
        	motor[leftArm] = -10;
      	}else{*/
        	motor[rightArm] = -126;
        	motor[leftArm] = -126;
      	//}
    	}else{
      	motor[rightArm] = 0;
      	motor[leftArm] = 0;
    	}

    	if(vexRT[Btn6U] == true){
      	 motor[rightintake] = 118;
      	 motor[leftintake] = 118;
    	}else if(vexRT[Btn5U] == true){
      	 motor[leftintake] = -118;
      	 motor[rightintake] = -118;
    	}else{
      	motor[rightintake] = 0;
      	motor[leftintake] = 0;
    	}
			wait1Msec(10);
		}
	}
}
