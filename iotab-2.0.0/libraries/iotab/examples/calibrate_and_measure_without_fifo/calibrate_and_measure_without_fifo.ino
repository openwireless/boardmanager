// Sample sketch for iotab -- Calibrate accelarations and read 3-axis accelarations without FIFO

#include <Wire.h>
#include <iotab.h>
#include "mma8451q.h"

// Constants
#define CALIBRATE_COUNT   100
#define MG_PER_LSB        0.244    // Conversion factor from LSB to mg @+/-2g

// Initial settings
#define XYZ_DATA_CFG      (m8XYZ_DATA_FS_2G)
#define CTRL_REG1         (m8CTRL_REG1_DR_100HZ | m8CTRL_REG1_LNOISE)
#define CTRL_REG2         (m8CTRL_REG2_MODE_HIGH_RES)

// Define accelaration sensor instance
MMA8451Q  acc(LOW);

void setup() {
  Wire.begin();
  
  while (! ioSerial)
    ;
  ioSerial.begin(115200);

  if (iotab.begin() != ioSuccess) {
    ioSerial.println("iotab.begin(): error.");
    while (1)
      ;       // Stop here
  }

  // Check id
  uint8_t id = acc.readRegister(m8REG_WHO_AM_I);
  if (id != m8WHO_AM_I_MMA8451Q_ID) {
    ioSerial.print("Bad id=0x");
    ioSerial.println(id, HEX);
    while (1) ;
  }

  // Reset MMA8451Q
  acc.writeRegister(m8REG_CTRL_REG2, m8CTRL_REG2_RST);
  while (acc.readRegister(m8REG_CTRL_REG2) & m8CTRL_REG2_RST)
    ;   // wait for ready

  // Set up MMA8451Q
  acc.writeRegister(m8REG_XYZ_DATA_CFG, XYZ_DATA_CFG);
  delay(10);
  acc.writeRegister(m8REG_CTRL_REG1, CTRL_REG1);
  delay(10);
  acc.writeRegister(m8REG_CTRL_REG2, CTRL_REG2);
  delay(10);
  uint8_t reg1 = acc.readRegister(m8REG_CTRL_REG1);
  reg1 |= m8CTRL_REG1_ACTIVE;
  acc.writeRegister(m8REG_CTRL_REG1, reg1);    // and Go!  

  // Calibration
  int tx = 0, ty = 0, tz = 0;
  for (int n = 0; n < CALIBRATE_COUNT; n++) {
    int ax, ay, az;
    acc.getAccelerations(&ax, &ay, &az);
    tx += ax;
    ty += ay;
    tz += az;    
  }
  tx /= CALIBRATE_COUNT;
  tx = tx >> 3;
  acc.writeRegister(m8REG_OFF_X, (- tx & 0xff));
  ty /= CALIBRATE_COUNT;
  ty = ty >> 3;
  acc.writeRegister(m8REG_OFF_Y, (- ty & 0xff));
  tz /= CALIBRATE_COUNT;
  tz = tz >> 3;
  tz -= 4095;
  acc.writeRegister(m8REG_OFF_Z, (- tz & 0xff));
}

void loop() {
  uint8_t status = acc.readRegister(m8REG_STATUS);
  if (status & m8STATUS_ZYXD) {
    uint32_t  ts = micros();
    int ax, ay, az;
    acc.getAccelerations(&ax, &ay, &az);
    char  line[60];
    sprintf(line, "%d,%d,%d", (int)(ax*MG_PER_LSB), (int)(ay*MG_PER_LSB), (int)(az*MG_PER_LSB));
    ioSerial.println(line);
  }
  delayMicroseconds(100);
}

