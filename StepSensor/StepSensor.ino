#include <Wire.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <pt.h>
#include <BluetoothSerial.h>
#include "SparkFun_BNO080_Arduino_Library.h" // Click here to get the library: http://librarymanager/All#SparkFun_BNO080
BluetoothSerial BT;
//#include <SoftwareSerial.h> //Serial transport for bluetooth
//SoftwareSerial AT; //set bluetooth name as BT
BNO080 myIMU;
unsigned long myTime;
unsigned long myTime2;

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("BNO080 Read Example");
  BT.begin("KWK");

  Wire.begin();

  myIMU.begin();

  Wire.setClock(400000); //Increase I2C data rate to 400kHz

  myIMU.enableGyro(50); //Send data update every 50ms

  myIMU.enableAccelerometer(50);

  //Enable dynamic calibration for accel, gyro, and mag
  myIMU.calibrateAll(); //Turn on cal for Accel, Gyro, and Mag

  //Enable Game Rotation Vector output
  myIMU.enableGameRotationVector(100); //Send data update every 100ms

  //Enable Magnetic Field output
  myIMU.enableMagnetometer(100); //Send data update every 100ms

  

  //Once magnetic field is 2 or 3, run the Save DCD Now command
  Serial.println(F("Calibrating. Press 's' to save to flash"));
  Serial.println(F("Output in form x, y, z, in uTesla"));
}

void loop()
{
  
    
  

  //Look for reports from the IMU
  if (myIMU.dataAvailable() == true)
  {
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
//
//    Serial.print("Time: ");
      myTime = millis();

      

    
//    Serial.print("Gyro : ");
//    Serial.print(gx, 2);
//    Serial.print(F(" "));
//    Serial.print(gy, 2);
//    Serial.print(F(" "));
//    Serial.print(gz, 2);
//    Serial.print(F(" "));
//    Serial.println();
//
//    Serial.print("Mag : ");
//    Serial.print(mx, 2);
//    Serial.print(F(" "));
//    Serial.print(my, 2);
//    Serial.print(F(" "));
//    Serial.print(mz, 2);
//    Serial.print(F(" "));
//    Serial.println();
//    
//    Serial.print("Acc : ");
//    Serial.print(ax, 2);
//    Serial.print(F(" "));
//    Serial.print(ay, 2);
//    Serial.print(F(" "));
//    Serial.print(az, 2);
//    Serial.print(F(" "));
//    Serial.println();
//
//    Serial.print("Quat : ");
//    Serial.print(quatI, 2);
//    Serial.print(F(" "));
//    Serial.print(quatJ, 2);
//    Serial.print(F(" "));
//    Serial.print(quatK, 2);
//    Serial.print(F(" "));
//    Serial.print(quatReal, 2);
//    Serial.print(F(" "));
//    Serial.println();
//
//
      BT.print(gx,2);
      BT.print(F(","));
      BT.print(gy,2);
      BT.print(F(","));
      BT.print(gz,2);
      BT.print(F(","));
  
      BT.print(mx,2);
      BT.print(F(","));
      BT.print(my,2);
      BT.print(F(","));
      BT.print(mz,2);
      BT.print(F(","));
  
      BT.print(ax,2);
      BT.print(F(","));
      BT.print(ay,2);
      BT.print(F(","));
      BT.print(az,2);
      BT.print(F(","));
  
      BT.print(quatI,2);
      BT.print(F(","));
      BT.print(quatJ,2);
      BT.print(F(","));
      BT.print(quatK,2);
      BT.print(F(","));
      BT.print(quatReal,2);
      BT.print(F(","));

      BT.print(myTime); // prints time since program started
      BT.print(F(","));
      
      BT.println();




    
  }
}
