#include <SPI.h>
#include <SD.h>
#include <SoftwareSerial.h>

const int RX_PIN = 9;
const int TX_PIN = 8;
const int BLUETOOTH_BAUD_RATE = 9600;

SoftwareSerial bluetooth(RX_PIN, TX_PIN);
char measureChar[100];
char cr;

File myFile;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bluetooth.begin(9600);
  
  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
}



void loop() {
  // put your main code here, to run repeatedly:
  int i=0;
  myFile = SD.open("test.txt");
  while (myFile.available()){
    cr = myFile.read();
      if((cr == '\n')||(cr == '\r'))
      bluetooth.write(measureChar);
          break;
    Serial.println(cr);
    measureChar[i]=cr;
    i++; 
 }
 bluetooth.write(cr); 
 Serial.println("");
 myFile.close();
}
