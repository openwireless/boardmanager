/*
 *  STTS751 sample sketch for CAIM - Read temperature and print it to serial monitor
 */

#include <Wire.h>
#include <stts751.h>

STTS751 stts751;

void setup() {
	while (! SerialUSB)
		;
	SerialUSB.begin(9600);

  Wire.begin();
  stts751.begin();
}

void loop() {
	int tX10 = stts751.getTemperature();
	SerialUSB.print(tX10 / 10);
	SerialUSB.print(".");
	SerialUSB.println(abs(tX10 % 10));

	delay(100);
}
