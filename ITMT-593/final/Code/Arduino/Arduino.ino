#include <SD.h>
#include <SPI.h>
#include "Adafruit_BLE_UART.h"

// Connect CLK/MISO/MOSI to hardware SPI
// e.g. On UNO & compatible: CLK = 13, MISO = 12, MOSI = 11
#define ADAFRUITBLE_REQ 8
#define ADAFRUITBLE_RST 7
#define ADAFRUITBLE_RDY 2     // This should be an interrupt pin, on Uno thats #2 or #3

Adafruit_BLE_UART BTLEserial = Adafruit_BLE_UART(ADAFRUITBLE_REQ, ADAFRUITBLE_RDY, ADAFRUITBLE_RST);

File myFile;

const int xpin = A0;                  // x-axis of the accelerometer
const int ypin = A1;                  // y-axis
const int buzz = 3;

// buzzer frequencies
int Do = 262, Re = 294 , Mi = 330 , Fa = 349 , Sol = 392 , 
    La = 440 , Si = 494, Do2 = 524;

int16_t zLow = 283, zHigh = 419, xHigh = 399, xLow = 264, yHigh = 396, yLow = 260;
int count = 0;
String incomingString="";

void setup() {

    Serial.begin(250000); // You can choose any baudrate, just need to also change it in Unity.
    BTLEserial.begin();
    pinMode(10, OUTPUT);
    pinMode(buzz, OUTPUT);
}

aci_evt_opcode_t laststatus = ACI_EVT_DISCONNECTED;

void loop() {
   BTLEserial.pollACI();

   aci_evt_opcode_t status = BTLEserial.getState();
  // If the status changed....
   if (status != laststatus) {
    laststatus = status;
   }

   short angleX = map(constrain(analogRead(xpin), xLow, xHigh),xLow,xHigh,-90,90);
   short angleY = map(constrain(analogRead(ypin), yLow, yHigh),yLow,yHigh,-90,90);

    // print the sensor values:
   Serial.print(angleX);
   // print a tab between values:
   Serial.print("/");
   Serial.print(angleY);
   // print a tab between values:
   Serial.println();

   

   if (status == ACI_EVT_CONNECTED) {
      
  
      if (Serial.available()) {
        // Read a line from Serial
        Serial.setTimeout(100); // 100 millisecond timeout
        String s = Serial.readString();
  
        // We need to convert the line to bytes, no more than 20 at this time
        uint8_t sendbuffer[25];
        s.getBytes(sendbuffer, 25);
        char sendbuffersize = min(25, s.length());
  
        Serial.print(F("\n* Sending -> \"")); Serial.print((char *)sendbuffer); Serial.println("\"");
  
        // write the data
        startSound();
        BTLEserial.write(sendbuffer, sendbuffersize);
      }
   }
   delay(100);
}


void startSound(){
  tone(buzz, Sol, 200);
  delay(200);
  tone(buzz, La, 100);
  delay(100);
  tone(buzz, Si, 100);
  delay(100);
  tone(buzz, La, 100);
  delay(100);
  tone(buzz, Do2, 100);
  delay(100);
  tone(buzz, La, 100);
  delay(100);
  tone(buzz, Do2, 100);
  delay(100);
}
