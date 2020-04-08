/***********************************************************************
 * mcp3008SpiTest.cpp. Sample program that tests the mcp3008Spi class.
 * an mcp3008Spi class object (a2d) is created. the a2d object is instantiated
 * using the overloaded constructor. which opens the spidev0.0 device with
 * SPI_MODE_0 (MODE 0) (defined in linux/spi/spidev.h), speed = 1MHz &
 * bitsPerWord=8.
 *
 * call the spiWriteRead function on the a2d object 20 times. Each time make sure
 * that conversion is configured for single ended conversion on CH0
 * i.e. transmit ->  byte1 = 0b00000001 (start bit)
 *                   byte2 = 0b1000000  (SGL/DIF = 1, D2=D1=D0=0)
 *                   byte3 = 0b00000000  (Don't care)
 *      receive  ->  byte1 = junk
 *                   byte2 = junk + b8 + b9
 *                   byte3 = b7 - b0
 *
 * after conversion must merge data[1] and data[2] to get final result
 *
 *
 *
 * *********************************************************************/
#include "mcp3008Spi.h"
#include "FlexSens.h"
using namespace std;

int main(void)
{
	mcp3008Spi a2d("/dev/spidev0.0", SPI_MODE_0, 1000000, 8);
	int i = 20;
	int a2dChannel = 0;
	FlexSens flex = FlexSens(a2dChannel, a2d);
	int a2dVal;

	while (i > 0)
	{
		a2dVal = flex.get_reading();
		sleep(1);

		cout << "The Result is: " << a2dVal << endl;
		i--;
	}

	return 0;
}