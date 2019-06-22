// 3GIM(V2) sample sketch for Mega/Leonardo.. -- getLocation2

#include "a3gim2.h"

#define baudrate 	9600UL
const int powerPin = 7;     // 3gim power pin(If not using power control, 0 is set.)

void setup()
{
  Serial.begin(baudrate);
  delay(3000);    // Wait for start serial monitor
  Serial.println("Ready.");

  Serial.print("Initializing.. ");
  if (a3gs.start(powerPin) == 0 && a3gs.begin(0, baudrate) == 0) {
    Serial.println("Succeeded.");
    setupAGPS();
    char lat[15], lng[15], utc[7], height[8];
    int quality, number;
    if (a3gs.getLocation2(lat, lng, height, utc, &quality, &number) == 0) {
      Serial.print("OK: ");
      Serial.print(lat);
      Serial.print(",");
      Serial.print(lng);
      Serial.print(",");
      Serial.print(height);
      Serial.print(",");
      Serial.print(utc);
      Serial.print(",");
      Serial.print(quality);
      Serial.print(",");
      Serial.println(number);
    }
    else
      Serial.println("Sorry, I don't know this location.");
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

// setup AGPS function
void setupAGPS()
{
  char apn[20], user[20], password[20];
  if (a3gs.getDefaultProfile(apn, user, password) == 0) {
    char atwppp[50];
    sprintf(atwppp,"at+wppp=2,4,\"%s\",\"%s\"",user,password);
    Serial.println(atwppp);
    a3gs.enterAT(2);
    a3gSerial.println(atwppp);
    delay(200);
    Serial.println("Assisted GPS set OK");
  }
  else
	Serial.println("NG: getDefaultProfile(), can't use AGPS.."); 
}

// END
