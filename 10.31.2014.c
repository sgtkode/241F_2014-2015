#pragma config(Sensor, in1,    armP,           sensorPotentiometer)
#pragma config(Sensor, dgtl1,  er,             sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  el,             sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  limitswitch,    sensorTouch)
#pragma config(Sensor, dgtl10, pn,             sensorDigitalIn)
#pragma config(Motor,  port2,           FR,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           BR,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           FL,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           BL,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           TRarm,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           TLarm,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           BRarm,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           BLarm,         tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

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
//                                  Functions
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////




void forward(int s) //s is encoder ticks for wheels, can be right or left as they should be the same.
{
    int enctick=SensorValue(er);
    while(enctick<s)
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

void backward(int s)
{
    nMotorEncoder[er] = 0;
    int enctick=SensorValue(er);
    while(enctick<s)
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


//need to calculate how many ticks it is per degree turn.
void correctturn(int degrees) //add sensor ticks per degrees
{
	//CONVERT DEGREES TO TICKS!!!
		int ticks=degrees*170;
    int i=SensorValue( er );//named encoder

    //CHANGE THE 1 LATERRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
    if(1<180)
    {
        while (i < ticks)
        {
            motor[FL]=118;
            motor[BL]=118;
            motor[FR]=-118;
            motor[BR]=-118; //<- need to check how long is 1 tick.
        }
    }
    else
    {
        //subtract amount of ticks in 180 degrees
        int ticks= 1-ticks;
        while (i < ticks)
        {
            motor[FL]=-118;
            motor[BL]=-118;
            motor[FR]=118;
            motor[BR]=118;
        }
    }
}

void raisearm(int ticks)
{
	SensorValue[pn] = 0;//open
	while(SensorValue[armP]<ticks)
	{
		motor[TLarm]=118;
		motor[TRarm]=118;
		motor[BLarm]=118;
		motor[BRarm]=118;
	}
	motor[TLarm]=0;
	motor[TRarm]=0;
	motor[BLarm]=0;
	motor[BRarm]=0;
	SensorValue[pn] = 1;//extends
}

void lowerarm(float seconds)
{
			SensorValue[pn]=0;
      motor[TRarm]= -118;
			motor[TLarm]= -118;
			motor[BRarm]= -118;
			motor[BLarm]= -118;
   		wait(seconds);
    	motor[TRarm]= -0;
			motor[TLarm]= -0;
			motor[BRarm]= -0;
			motor[BLarm]= -0;
			SensorValue[pn]=1;
}


/*
void lowerarm(int ticks)
{
	while(sensorValue[armP]>ticks)
	{
		motor[TLarm]=-118;
		motor[TRarm]=-118;
		motor[BLarm]=-118;
		motor[BRarm]=-118;
	}
	motor[TLarm]=0;
	motor[TRarm]=0;
	motor[BLarm]=0;
	motor[BRarm]=0;
}
*/

void increment(int lev) //raising the arm to certain levels
{
		int level[]={1322,1685,1965,2235,2615,3030,1270};
    if(SensorValue[armP]<level[lev])
    {
        raisearm(level[lev]);
    }
}

void taketower()
{
				int level[]={1322,1685,1965,2235,2615,3030,1270};
        backward();
        increment(level[6]);
        forward();
        backward();
}


void drive(bool half)
{
		if (half==false)
		{
			motor[BR] = vexRT[Ch2];
			motor[FR] = vexRT[Ch2];
			motor[BL] = vexRT[Ch3];
			motor[FL] = vexRT[Ch3];
		}
		else if(half ==true)
		{
			motor[BR] = vexRT[Ch2]/2;
			motor[FR] = vexRT[Ch2]/2;
			motor[BL] = vexRT[Ch3]/2;
			motor[FL] = vexRT[Ch3]/2;
		}
}



/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous
//
/////////////////////////////////////////////////////////////////////////////////////////


//EVerY X VALUE MUST BE CHANGED
void autonomus()
{
    while (true)
    {
    		nMotorEncoder[er]=0;
    		nMotorEncoder[el]=0;
        increment(0);
        forward(210);
        lowerarm(.5);
        backward(105);
        for(int i=1;i<7;i++)
        {
            correctturn(90);
            taketower();
            increment(i);
            correctturn(90);
            lowerarm(.5);
            backward(105);
        }
    }
}



/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	bool half=false;

	if (vexRT[Btn6D] == 1)
	{
		if (half==false)
		{
			half=true;
		}
		else if (half==true)
		{
				half=false;
		}
	}


	while (true)
	{

		drive(half);
		motor[TRarm] = 0;
  	motor[TLarm] = 0;
  	motor[BRarm] = 0;
  	motor[BLarm] = 0;

		while(vexRT[Btn6D] == 1)
		{
			motor[TRarm] = 118;
  		motor[TLarm] = 118;
  		motor[BRarm] = 118;
  		motor[BLarm] = 118;
  		drive(half);
		}

		while(vexRT[Btn5D] == 1)
		{
			motor[TRarm] = -118;
  		motor[TLarm] = -118;
  		motor[BRarm] = -118;
  		motor[BLarm] = -118;
  		drive(half);
		}

		while(vexRT[Btn6U] == 1)
		{
			motor[TRarm] = 118/2;
  		motor[TLarm] = 118/2;
  		motor[BRarm] = 118/2;
  		motor[BLarm] = 118/2;
  		drive(half);
		}
		while(vexRT[Btn5U] == 1)
		{
			motor[TRarm] = -118/2;
  		motor[TLarm] = -118/2;
  		motor[BRarm] = -118/2;
  		motor[BLarm] = -118/2;
  		drive(half);
		}
		while(vexRT[Btn8U] == 1)
	{
			motor[TRarm] = 40;
  		motor[TLarm] = -40;
  		motor[BRarm] = 40;
  		motor[BLarm] = -40;
  		drive(half);
	}
}
}




















//Hard coded autonomous

/*
task autonomous()
{
	while(true)
	{
		if(SensorValue[limitswitch] == 1)
		{
			break;
		}
	}
	while(SensorValue[armP] <= 1270)
	{
			motor[TRarm]= 118;
			motor[TLarm]= 118;
			motor[BRarm]= 118;
			motor[BLarm]= 118;
	}
	motor[TRarm]= 0;
	motor[TLarm]= 0;
	motor[BRarm]= 0;
	motor[BLarm]= 0;
	SensorValue[pn] = 1;

	motor[FL]=118;
  motor[FR]=118;
	motor[BL]=118;
  motor[BR]=118;
  wait10Msec(1000);

  SensorValue[pn] = 0;
  while(SensorValue[armP] <= 1400)
  {
	 	motor[TRarm]= 118;
		motor[TLarm]= 118;
		motor[BRarm]= 118;
		motor[BLarm]= 118;
	}
	motor[TRarm]= 0;
	motor[TLarm]= 0;
	motor[BRarm]= 0;
	motor[BLarm]= 0;
	SensorValue[pn] = 1;

	motor[FL]=-90;
  motor[FR]=-90;
	motor[BL]=-90;
  motor[BR]=-90;
  wait10Msec(1000);

  motor[FL]=0;
  motor[FR]=0;
	motor[BL]=0;
  motor[BR]=0;
  wait10Msec(2000);

  SensorValue[pn] = 0;
	motor[TRarm]= -118;
	motor[TLarm]= -118;
	motor[BRarm]= -118;
	motor[BLarm]= -118;
	wait10Msec(1000);

	motor[TRarm]= 0;
	motor[TLarm]= 0;
	motor[BRarm]= 0;
	motor[BLarm]= 0;

	while(true)
	{
		if(SensorValue[limitswitch] == 1)
		{
			break;
		}
	}
	while(SensorValue[armP] <= 1270)
	{
			motor[TRarm]= 118;
			motor[TLarm]= 118;
			motor[BRarm]= 118;
			motor[BLarm]= 118;
	}
	motor[TRarm]= 0;
	motor[TLarm]= 0;
	motor[BRarm]= 0;
	motor[BLarm]= 0;
	SensorValue[pn] = 1;

	motor[FL]=118;
  motor[FR]=118;
	motor[BL]=118;
  motor[BR]=118;
  wait10Msec(1000);

  SensorValue[pn] = 0;
  while(SensorValue[armP] <= 1750)
  {
	 	motor[TRarm]= 118;
		motor[TLarm]= 118;
		motor[BRarm]= 118;
		motor[BLarm]= 118;
	}
	motor[TRarm]= 0;
	motor[TLarm]= 0;
	motor[BRarm]= 0;
	motor[BLarm]= 0;
	SensorValue[pn] = 1;

	motor[FL]=-90;
  motor[FR]=-90;
	motor[BL]=-90;
  motor[BR]=-90;
  wait10Msec(1000);

  motor[FL]=0;
  motor[FR]=0;
	motor[BL]=0;
  motor[BR]=0;
  wait10Msec(2000);

  SensorValue[pn] = 0;
	motor[TRarm]= -118;
	motor[TLarm]= -118;
	motor[BRarm]= -118;
	motor[BLarm]= -118;
	wait10Msec(1000);

	motor[TRarm]= 0;
	motor[TLarm]= 0;
	motor[BRarm]= 0;
	motor[BLarm]= 0;
	wait10Msec(2000);
}

*/