#pragma once
#include "mcp3008Spi.h"

// Class to deal with analog actuators
class AnlogSens
{
public:
	AnlogSens();
	AnlogSens(int sensPin, mcp3008Spi aTOd);
	~AnlogSens();
	// read sensor value using AtoD converter
	int get_reading();
	int getPinNum();
	unsigned char* getData();

protected:
	int pin;
	int val;
	mcp3008Spi a2d;
	unsigned char data[3];
	
};

