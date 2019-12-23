/*
|--------------------------------Copyright-------------------------------------|
|                                                                              |
|                          (C)Copyright 2019,yy                          |
|                                                                              |
|                          By:GCU The wolf of team                             |
|------------------------------------------------------------------------------|
|  FileName     : Motor.c
|  Version      : v1.0
|  Author       : yy
|  Date         : 2019-11-06
|  Libsupports  : STM32F10x_StdPeriph_Lib_V3.5.0
|  Description  :
|------------------------------declaration of end------------------------------|
**/
/*------------------------ I N C L U D E - F I L E S -------------------------*/
#include "Buleteeth.h"
/*----------------------------- D E F I N E S --------------------------------*/
int TARGET = 10;
/**/
/*------------ L O C A L - F U N C T I O N S - P R O T O T Y P E S -----------*/
/**/
/*--------------------- G L O B A L - F U N C T I O N S ----------------------*/
/**/
/*----------------------- L O C A L - F U N C T I O N S ----------------------*/
/**/
/*------------------------------- FILE OF END --------------------------------*/

void PARKING(void)
{
	Target_Left = 0;
	Target_Right = 0;
	Servo = 15;
}

void GO_STRIGHT_AHEAD(void)
{
	Target_Left = TARGET;
	Target_Right = TARGET;
	Servo = 15;
}

void STEP_BACK(void)
{
	Target_Left = -TARGET;
	Target_Right = -TARGET;
	Servo = 15;
}

void LEFTTURN(void)
{
	Target_Left = -TARGET;
	Target_Right = TARGET;
	Servo = 20;
}

void RIGHTTURN(void)
{
	Target_Left = TARGET;
	Target_Right = -TARGET;
	Servo = 10;
}

void REMOTE_CONTROL(void)
{
		char ch;
		ch = getchar();
		switch (ch)
		{
			case 'Z':PARKING(); break;
			case 'A': GO_STRIGHT_AHEAD(); break;
			case 'C': RIGHTTURN(); break;
			case 'G': LEFTTURN(); break;
			case 'E': STEP_BACK(); break;
			default:PARKING(); break;
		}
}
