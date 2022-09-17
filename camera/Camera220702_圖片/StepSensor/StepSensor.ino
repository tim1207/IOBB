#include <Wire.h>

#include <stdlib.h>

#include <stdint.h>

#include <string.h>

#include <pt.h>

//#include <BluetoothSerial.h>

#include "SparkFun_BNO080_Arduino_Library.h" // Click here to get the library: http://librarymanager/All#SparkFun_BNO080

//BluetoothSerial BT;
#include <SoftwareSerial.h> //Serial transport for bluetooth
SoftwareSerial AT(0,1); //set bluetooth name as BT
BNO080 myIMU;
unsigned long myTime;
String receivedCommand;
bool receiveComplete;

void setup() {
  Serial.begin(38400);
  Serial.println();
  Serial.println("BNO080 Read Example");
//  BT.begin("Sensor");
    AT.begin();
  Wire.begin();

  myIMU.begin();

  Wire.setClock(400000); //Increase I2C data rate to 400kHz

  myIMU.enableGyro(50); //Send data update every 50ms

  myIMU.enableAccelerometer(50);

  //Enable dynamic calibration for accel, gyro, and mag
  myIMU.calibrateAll(); //Turn on cal for Accel, Gyro, and Mag

  //Enable Game Rotation Vector output
  myIMU.enableGameRotationVector(50); //Send data update every 100ms

  //Enable Magnetic Field output
  myIMU.enableMagnetometer(50); //Send data update every 100ms
}


void resetCommand() {
  receivedCommand = "";
  receiveComplete = false;
}
void serialEvent() {
  while (BT.available()) {
    char inChar = (char) BT.read();
    if ((inChar == '\n') || (inChar == '#')) {
      receiveComplete = (receivedCommand.length() > 0);
      break;
    } else {
      receivedCommand += inChar;
    }
  }
}


void loop() {
  serialEvent();
  if (receiveComplete) {
    Serial.println(receivedCommand);
    for (int i = 0; i < receivedCommand.length(); i++)
      BT.write((uint8_t) receivedCommand[i]);
    //        BT.print((uint8_t)receivedCommand[0]);
    resetCommand();
    //Look for reports from the IMU
    if (myIMU.dataAvailable() == true) {
      float mx = myIMU.getMagX();
      float my = myIMU.getMagY();
      float mz = myIMU.getMagZ();

      float gx = myIMU.getGyroX();
      float gy = myIMU.getGyroY();
      float gz = myIMU.getGyroZ();

      float ax = myIMU.getAccelX();
      float ay = myIMU.getAccelY();
      float az = myIMU.getAccelZ();

      float quatI = myIMU.getQuatI();
      float quatJ = myIMU.getQuatJ();
      float quatK = myIMU.getQuatK();
      float quatReal = myIMU.getQuatReal();
      myTime = millis();

      // if(mx!=NULL and my!=NULL  and mz!=NULL  and gx!=NULL  and gy!=NULL  and gz!=NULL  and ax!=NULL  and ay!=NULL  and az!=NULL  and quatI!=NULL  and quatJ!=NULL  and quatK!=NULL  and quatReal!=NULL)
      // {

//      BT.print(F(","));
//      BT.print(gx, 2);
//      BT.print(F(","));
//      BT.print(gy, 2);
//      BT.print(F(","));
//      BT.print(gz, 2);
//      BT.print(F(","));
//
//      BT.print(mx, 2);
//      BT.print(F(","));
//      BT.print(my, 2);
//      BT.print(F(","));
//      BT.print(mz, 2);
//      BT.print(F(","));
//
//      BT.print(ax, 2);
//      BT.print(F(","));
//      BT.print(ay, 2);
//      BT.print(F(","));
//      BT.print(az, 2);
//      BT.print(F(","));
//
//      BT.print(quatI, 2);
//      BT.print(F(","));
//      BT.print(quatJ, 2);
//      BT.print(F(","));
//      BT.print(quatK, 2);
//      BT.print(F(","));
//      BT.print(quatReal, 2);
//      BT.print(F(","));
//
//      BT.print(myTime); // prints time since program started
//      BT.print(F(","));
//
//      BT.println();
           BT.print(F(","));
      AT.print(gx, 2);
      AT.print(F(","));
      AT.print(gy, 2);
      AT.print(F(","));
      AT.print(gz, 2);
      AT.print(F(","));

      AT.print(mx, 2);
      AT.print(F(","));
      AT.print(my, 2);
      AT.print(F(","));
      AT.print(mz, 2);
      AT.print(F(","));

      AT.print(ax, 2);
      AT.print(F(","));
      AT.print(ay, 2);
      AT.print(F(","));
      AT.print(az, 2);
      AT.print(F(","));

      AT.print(quatI, 2);
      AT.print(F(","));
      AT.print(quatJ, 2);
      AT.print(F(","));
      AT.print(quatK, 2);
      AT.print(F(","));
      AT.print(quatReal, 2);
      AT.print(F(","));

      AT.print(myTime); // prints time since program started
      AT.print(F(","));

      AT.println();


    }
  }
}
