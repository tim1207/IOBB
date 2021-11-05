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

void setup()
{
  Serial.begin(115200);
 // AT.begin(115200);
  BT.begin("Sensor_Go");
  BT.println("Welcome !!!!");
  Serial.println();
  Serial.println("BNO080 Read Example");

  Wire.begin();

  myIMU.begin();

  Wire.setClock(400000); //Increase I2C data rate to 400kHz
  myIMU.enableGyro(50);
  myIMU.enableMagnetometer(50); //Send data update every 50ms

  Serial.println(F("Magnetometer enabled"));
  Serial.println(F("Output in form x, y, z, in uTesla"));
}



void loop()
{
  //serialEvent();
  //Look for reports from the IMU
  if (myIMU.dataAvailable() == true)
  {
    float x = myIMU.getMagX();
    float y = myIMU.getMagY();
    float z = myIMU.getMagZ();
   //serial mag data
    Serial.print(x,2);
    Serial.print(" ");
    Serial.print(y, 2);
    Serial.print(" ");
    Serial.print(z, 2);
    Serial.print(" ");

    BT.print(x,2);
    BT.print(F(","));
    BT.print(y,2);
    BT.print(F(","));
    BT.print(z,2);
    BT.print(F(","));



    //serial gyro data
    float xg = myIMU.getGyroX();
    float yg = myIMU.getGyroY();
    float zg = myIMU.getGyroZ();
    //Serial.print("Gyro: ");
    Serial.print(xg, 2);
    //Serial.print(F(","));
    Serial.print(" ");
    Serial.print(yg, 2);
    //Serial.print(F(","));
    Serial.print(" ");
    Serial.print(zg, 2);
    //Serial.print(F(","));
    Serial.print(" ");
    Serial.print("#");

    //BT Gyro data
//    BT.print("Gyro:  ");
    BT.print(xg,2);
    BT.print(F(","));
    BT.print(yg,2);
    BT.print(F(","));
    BT.print(zg,2);
    BT.print(F(","));
    BT.println("");
//    delay(1000);
  }
}
