// Sample skecth for iotab - Blink LED2

#include <iotab.h>

void setup() {
  iotab.begin();
}

void loop() {
  iotab.setLed(HIGH);   // turn on led2
  delay(500);
  iotab.setLed(LOW);    // turn off led2
  delay(500);
}

