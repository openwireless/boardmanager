// 3GIM(V2) sample sketch for Mega/Leonardo.. -- sendSMS (Japanease message version)
// PLEASE REPLACE "msn" WITH CORRECT TELEPHONE NUMBER BEFORE UPLOAD THIS SKETCH.

#include "a3gim2.h"

#define baudrate 	9600UL
const int powerPin = 7;     // 3gim power pin(If not using power control, 0 is set.)

char *msn = "09000000000";    // Replace your phone number!
char *msg = "TEST MESSAGE. HELLO!";  // ASCII String
  // Japanease(Multi-byte code) is not supported in 3GIM(V2)

void setup()
{
  Serial.begin(baudrate);
  delay(3000);  // Wait for Start Serial Monitor
  Serial.println("Ready.");

  Serial.print("Initializing.. ");
  if (a3gs.start(powerPin) == 0 && a3gs.begin(0, baudrate) == 0) {
    Serial.println("Succeeded.");
    Serial.print("SMS Sending.. ");
    if (a3gs.sendSMS(msn, msg) == 0)
      Serial.println("OK!");
    else
      Serial.println("Can't send SMS.");
  }
  else
    Serial.println("Failed.");

  Serial.println("Shutdown..");
  a3gs.end();
  a3gs.shutdown();
}

void loop()
{
}

// END
