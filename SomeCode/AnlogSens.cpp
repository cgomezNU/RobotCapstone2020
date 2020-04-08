#include "AnlogSens.h"

AnlogSens::AnlogSens()
{
	pin = 0;
	a2d = mcp3008Spi();
}


AnlogSens::AnlogSens(int sensPin, mcp3008Spi aTOd)
{
	pin = sensPin;
	a2d = aTOd;
}


AnlogSens::~AnlogSens()
{
}

int AnlogSens::getPinNum() {
	return pin;
}


unsigned char* AnlogSens::getData() {
	return this->data;
}

// read flex sensor value using AtoD converter
int AnlogSens::get_reading() {
	// set data array in correct format to store information
	data[0] = 1;										//  first byte transmitted -> start bit
	data[1] = 0b10000000 | (((this->pin & 7) << 4)); // second byte transmitted -> (SGL/DIF = 1, D2=D1=D0=0)
	data[2] = 0;										// third byte transmitted....don't care

	// write channel info in data array
	a2d.spiWriteRead(data, sizeof(data));

	// set val using info from data array
	this->val = 0;
	this->val = (data[1] << 8) & 0b1100000000; //merge data[1] & data[2] to get result
	this->val |= (data[2] & 0xff);

	return this->val;
}