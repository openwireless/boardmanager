/*
 *	iotab.h
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

#ifndef _iotab_H_
#define	_iotab_H_

#include <Arduino.h>

/*
 *  Constants
 */
#define ioSuccess			0
#define ioError				1
/*
 *  Define pins
 */	
#define io3gimPowerOnPin	9			// 3GIM PWR_ON pin
#define ioLed2Pin			13			// LED2 pin (0:turn off/1:turn on) - same as pre-defined LED_BUILTIN
#define	ioMMA8451QInt1Pin	6			// INT1 pin of MMA8451Q
#define	ioMMA8451QInt2Pin	7			// INT2 pin of MMA8451Q
#define ioInputVoltagePin	A5			// Pins that can read 1/4 of the input voltage

/*
 *  Serial port
 */
#define ioSerial			SerialUSB	// USB Serial port(not Serial)
#define	io3gimSerial		Serial		// 3GIM Serial port

/*
 *  Class iotab
 */
class IOTAB {
	public:
		// Board control
		int	begin(void);					// Begin to use the iotab

		// LED2 control
		void setLed(int sw);					// Turn led1 on(1) or off(0)

		// 3GIM control
		void turnOn3GIM(void);				// Turn on 3GIM
		void turnOff3GIM(void);				// Turn off 3GIM

		// Supply power control
		int getVIN(void);					// return value: Supply voltage(VBAT) [mV]

	private:
		boolean hasInitialized = false;
		void (*alarmHandler)(void) = NULL;
};

extern IOTAB	iotab;

#endif // _iotab_H_
