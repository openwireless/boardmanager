/*
 *	stts751.cpp - Digital temperature sensor STTS751 control library
 *    2018.01.14 R1.0 605e
 *    2018.02.07 R1.1 605e  fixed calculation bug when the temperature is negative
 *    2019.06.10 R1.2 605e  for stts751-1
 */

#include <Wire.h>
#include "stts751.h" 

// Symbols
#define STTS751_I2C_ADDDR  	0b0111011

// begin() - 
void STTS751::begin() {
    Wire.beginTransmission(STTS751_I2C_ADDDR);
    Wire.write(0x03);
    Wire.write(0b10001100);
    Wire.endTransmission();
	Wire.write(0x04);
    Wire.write(0x04);
    Wire.endTransmission();
}

// getTemperature() - 
int STTS751::getTemperature() {
	uint32_t data[2];
	Wire.beginTransmission(STTS751_I2C_ADDDR);
    Wire.write(0x00);
    Wire.endTransmission();
    Wire.requestFrom(STTS751_I2C_ADDDR, 1);
	if (Wire.available() == 1)
		data[0] = Wire.read();
    Wire.beginTransmission(STTS751_I2C_ADDDR);
    Wire.write(0x02);
    Wire.endTransmission();
    Wire.requestFrom(STTS751_I2C_ADDDR, 1);
    if (Wire.available() == 1)
		data[1] = Wire.read();
    int temp = ((data[0]  * 256) + (data[1] & 0xFC)) / 16;
    if (temp > 2047)
		temp -= 4096;

	return (temp * 0.625);
}

// End of stts751.cpp