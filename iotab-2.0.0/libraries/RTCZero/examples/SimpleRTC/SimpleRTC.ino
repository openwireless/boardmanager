/*
  Simple RTC for Arduino Zero and MKR1000

  Demonstrates the use of the RTC library for the Arduino Zero and MKR1000

  This example code is in the public domain

  http://arduino.cc/en/Tutorial/SimpleRTC

  created by Arturo Guadalupi <a.guadalupi@arduino.cc>
  15 Jun 2015
  modified 
  18 Feb 2016
  modified by Andrea Richetta <a.richetta@arduino.cc>
  24 Aug 2016
  - modified by A.D
    16 Jul 2017 (Changed to use SerialUSB instead of monSerial for CAIM)
*/

#include <RTCZero.h>

// monSerial Monitor Port for CAIM
#define	monSerial		SerialUSB

/* Create an rtc object */
RTCZero rtc;

/* Change these values to set the current initial time */
const byte seconds = 0;
const byte minutes = 0;
const byte hours = 16;

/* Change these values to set the current initial date */
const byte day = 15;
const byte month = 6;
const byte year = 15;

void setup()
{
  monSerial.begin(9600);

  rtc.begin(); // initialize RTC

  // Set the time
  rtc.setHours(hours);
  rtc.setMinutes(minutes);
  rtc.setSeconds(seconds);

  // Set the date
  rtc.setDay(day);
  rtc.setMonth(month);
  rtc.setYear(year);

  // you can use also
  //rtc.setTime(hours, minutes, seconds);
  //rtc.setDate(day, month, year);
}

void loop()
{
  // Print date...
  print2digits(rtc.getDay());
  monSerial.print("/");
  print2digits(rtc.getMonth());
  monSerial.print("/");
  print2digits(rtc.getYear());
  monSerial.print(" ");

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
    monSerial.print("0"); // print a 0 before if the number is < than 10
  }
  monSerial.print(number);
}