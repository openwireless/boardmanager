/*
 * MMA8452Q Sample sketch for CAIM -- Read "Who am I"
 */

#include <Wire.h>
#include "mma8452q.h"

// monSerial monitor port
#define monSerial     SerialUSB

MMA8452Q  acc(LOW);

void setup() {
  Wire.begin();
  
  monSerial.begin(9600);
  while (! monSerial)
    ;
  monSerial.println("Try to read ID from the device.");
  
  uint8_t id = acc.readRegister(m8REG_WHO_AM_I);

  monSerial.print("id=0x");
  monSerial.println(id, HEX);

  Wire.end();
}

void loop() {
}
