#pragma config(Sensor, in1,    armP,           sensorPotentiometer)
#pragma config(Sensor, dgtl1,  er,             sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  el,             sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  limitswitch,    sensorTouch)
#pragma config(Sensor, dgtl6,  pn,             sensorDigitalOut)
#pragma config(Motor,  port2,           FR,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           BR,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           BL,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           FL,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           TRarm,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           TLarm,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           BRarm,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           BLarm,         tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
task main()
{

    motor[TLarm]=118;
    motor[TRarm]=118;
    motor[BLarm]=118;
    motor[TRarm]=118;
    wait(3);
    motor[TLarm]=0;
    motor[TRarm]=0;
    motor[BLarm]=0;
    motor[TRarm]=0;

}