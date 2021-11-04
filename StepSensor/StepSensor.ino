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
  BT.begin("TW");
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

//void serialEvent() {
//  while (BT.available()){
//    //char inChar = (char)BT.read();
//    // Serial.println(inChar);
//    //if ((inChar == '1')){ //ENTER PROBLEM     
//      //receiveComplete = (receivedCommand.length() > 0);      
//      //receiveComplete = true;
//      
//      //Serial.println(receiveComplete);
//      BT.println("Success");
//     // break;
//    //} else {
//      //receivedCommand += inChar;
//   // }
//  }
//}

void loop()
{
  //serialEvent();
  //Look for reports from the IMU
  if (myIMU.dataAvailable() == true)
  {
    float x = myIMU.getMagX();
    float y = myIMU.getMagY();
    float z = myIMU.getMagZ();
   // byte accuracy = myIMU.getMagAccuracy();
   //serial mag data
    //Serial.print("Mag:  ");
    Serial.print(x,2);
    //Serial.print(F(","));
    Serial.print(" ");
    Serial.print(y, 2);
    Serial.print(" ");
   // BT.print(y,2);
   // Serial.print(F(","));
    Serial.print(z, 2);
    Serial.print(" ");
   // Serial.print("#");
   // BT.print(z,2);
    //Serial.print(F(","));
  //  printAccuracyLevel(accuracy);
   //Serial.print(F(","));
    //Serial.println("");
   // BT.println("Hello!!");
    //BT Mag data
    //BT.println("Mag:  ");
    BT.print(x,2);
    BT.print(F(","));
    //BT.print(" ");
    BT.print(y,2);
    BT.print(F(","));
    //BT.print(" ");
    BT.print(z,2);
   // BT.println();
    BT.print(F(","));
    //BT.println("");

    //AT computer connect bluetooth
//    AT.println("Mag:  ");
//    AT.println(x,2);
//    AT.println(F(","));
//    AT.println(y,2);
//    AT.println(F(","));
//    AT.println(z,2);
//    AT.println(F(","));
//    AT.println("");
    
    //delay(1000);
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

//Given a accuracy number, print what it means
//void printAccuracyLevel(byte accuracyNumber)
//{
//  if(accuracyNumber == 0) Serial.print(F("Unreliable"));
//  else if(accuracyNumber == 1) Serial.print(F("Low"));
//  else if(accuracyNumber == 2) Serial.print(F("Medium"));
//  else if(accuracyNumber == 3) Serial.print(F("High"));
//}
