// Sample skech for iotab -- Get 3G RSSI

#include <iotab.h>
#include <a3gim2.h>

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
  }
  else {
    ioSerial.println("Failed.");
    while (1) ;   // Stop here
  }
}

void loop() {
    int rssi;
    if (a3gs.getRSSI(rssi) == 0) {
      ioSerial.println(rssi);
    }
    else {
      ioSerial.println("N/A");
    }
    
    delay(5000);
}

