/*
  Epoch time example for Arduino Zero and MKR1000

  Demonstrates how to set time using epoch for the Arduino Zero and MKR1000

  This example code is in the public domain

  created by Sandeep Mistry <s.mistry@arduino.cc>
  31 Dec 2015
  - modified by A.D
    16 Jul 2017 (Changed to use SerialUSB instead of monSerial for CAIM)
*/

#include <RTCZero.h>

// monSerial Monitor Port for CAIM
#define	monSerial		SerialUSB

/* Create an rtc object */
RTCZero rtc;

void setup() {
  monSerial.begin(9600);

  rtc.begin(); // initialize RTC

  rtc.setEpoch(145160400); 	// Jan 1, 2016
}

void loop() {
  monSerial.print("Unix time = ");
  monSerial.println(rtc.getEpoch());

  monSerial.print("Seconds since Jan 1 2000 = ");
  monSerial.println(rtc.getY2kEpoch());

  // Print date...
  monSerial.print(rtc.getDay());
  monSerial.print("/");
  monSerial.print(rtc.getMonth());
  monSerial.print("/");
  monSerial.print(rtc.getYear());
  monSerial.print("\t");

  // ...and time
  print2digits(rtc.getHours());
  monSerial.print(":");
  print2digits(rtc.getMinutes());
  monSerial.print(":");
  print2digits(rtc.getSeconds());

  monSerial.println();

  delay(1000);
}

void print2digits(int number) {
  if (number < 10) {
    monSerial.print("0");
  }
  monSerial.print(number);
}

