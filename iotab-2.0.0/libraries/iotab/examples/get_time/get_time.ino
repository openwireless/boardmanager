// Sample sketch for iotab -- Get Time

#include <iotab.h>
#include "a3gim2.h"

#define baudrate 	9600

void setup()
{
  while (! ioSerial)
    ;
  ioSerial.begin(9600);

  if (iotab.begin() != ioSuccess) {
    ioSerial.println("iotab.begin(): error.");
    while (1)
      ;       // Stop here
  }

  ioSerial.print("Initializing.. ");

  if (a3gs.start(io3gimPowerOnPin) == 0 && a3gs.begin(0, baudrate) == 0) {
    ioSerial.println("Succeeded.");
    char date[a3gsDATE_SIZE], time[a3gsTIME_SIZE];
    if (a3gs.getTime(date, time) == 0) {
      ioSerial.print(date);
      ioSerial.print(" ");
      ioSerial.println(time);
    }
  }
  else {
    ioSerial.println("Failed.");
  }

  ioSerial.println("Shutdown..");
  a3gs.end();
  a3gs.shutdown();
}

void loop()
{
}

