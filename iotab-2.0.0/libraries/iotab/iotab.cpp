/*
 *	iotab.cpp
 *
 *	Control library for IoTAB(Compact Arduino Module for IoT)
 *
 *  Release:
 *	 - R1.0  2017.10.10  1st Release(A.D)
 *   - R2.0  2019.06.10  2nd Release for iotab(v2) (A.D)
 *
 *  Notes:
 *   - For controlling peripheral devices, you can use the following library included:
 *       RTCZero, mma8451q, stts751, lcdi2c,
 *
 *  Copyright(c) 2017-2019 TABrain Inc. All rights reserved.
 */

#include <iotab.h>

// Define iotab instance
IOTAB	iotab;

// begin() -- 
int IOTAB::begin(void) {
	if (hasInitialized)
		return ioError;		// already had initialized
	
	// Set up GPIOs
	pinMode(io3gimPowerOnPin, OUTPUT);
	digitalWrite(io3gimPowerOnPin, LOW);	// Turn off 3GIM
	pinMode(ioLed2Pin, OUTPUT);
	digitalWrite(ioLed2Pin, LOW);			// Turn off led

	// 
	hasInitialized = true;
	return ioSuccess;
}

// setLed() --
void IOTAB::setLed(int sw) {
	digitalWrite(ioLed2Pin, sw);
}


// turnOn3GIM() -- 
void IOTAB::turnOn3GIM(void) {
	digitalWrite(io3gimPowerOnPin, HIGH);	// Turn on
}

// turnOff3GIM() -- 
void IOTAB::turnOff3GIM(void) {
	digitalWrite(io3gimPowerOnPin, LOW);	// Turn Off
}

int IOTAB::getVIN(void) {
#define	NCOUNTS		5
	int mV = 0;
	for (int n = 0; n < NCOUNTS; n++) {
		mV += analogRead(ioInputVoltagePin) * 4.0 * 3.236;
		delay(10);
	}

	return (mV / NCOUNTS);	
}

// END
