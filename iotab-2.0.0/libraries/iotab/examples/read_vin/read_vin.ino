// Sample sketch for IoTAB - Read VBAT voltage

#include <iotab.h>

void setup() {
  while (! ioSerial)
    ;
  ioSerial.begin(9600);

  if (iotab.begin() != ioSuccess) {
    ioSerial.println("iotab.begin(): error.");
    while (1)
      ;       // Stop here
  }
}

void loop() {
  int mV = iotab.getVIN();
  ioSerial.println(mV);

  delay(100);
}

