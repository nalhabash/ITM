#include <SPI.h>
#include <SD.h>
#include <Ethernet2.h>


const float ArduinoVoltage = 5.00; 
const float ArduinoResolution = ArduinoVoltage / 1024;
const float resistorValue = 10000.0;
int threshold = 3;
int inputPin = A0;
int ouputPin = A5;
File myFile;

byte mac[] = {
  0x90, 0xA3, 0xDA, 0x0F, 0x46, 0x70
};
IPAddress ip(192, 168, 0, 6);


EthernetServer server(80);

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  pinMode(ouputPin, OUTPUT);
  pinMode(inputPin, INPUT);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}


void loop() {
  int analogValue = 0;
  int oldAnalogValue = 1000;
  float returnVoltage = 0.0;
  float resistance = 0.0;
  double Siemens;
  float TDS = 0.0;

  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);

        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  
          client.println("Refresh: 2");  
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          client.println("<link rel='stylesheet' href='https://goo.gl/21MtaM'");
          client.println("<body>");
          client.println("<p class='h4 text-center '>Nour's Web Server</p>");


          myFile = SD.open("test.txt", FILE_WRITE);
          while (((oldAnalogValue - analogValue) > threshold) || (oldAnalogValue < 50)) {
            oldAnalogValue = analogValue;
            digitalWrite( ouputPin, HIGH );
            delay(10); // allow ringing to stop
            analogValue = analogRead( inputPin );
            digitalWrite( ouputPin, LOW );
          }

          if (myFile) {
            Serial.println("File opened");
            returnVoltage = analogValue * ArduinoResolution;
            resistance = ((5.00 * resistorValue) / returnVoltage) - resistorValue;
            Siemens = 1.0 / (resistance / 1000000);
            TDS = 500 * (Siemens / 1000);

            unsigned long time = millis();
            client.print("<p>");
            client.print("Time :");
            client.println(time);
            client.println("<br />");
            client.print("Voltage = ");
            client.print(returnVoltage);
            client.println("<br />");
            client.print("Resistance = ");
            client.print(resistance);
            client.println("<br />");
            client.print("Conductivity = ");
            client.print(Siemens);
            client.println("<br />");
            client.print("Total Dissolved Solids = ");
            client.print(TDS);
            client.print("</p>");

            myFile.print("Time: ");
            myFile.print(time);
            myFile.print(" Voltage= ");
            myFile.print(returnVoltage);
            myFile.print(" Resistance= ");
            myFile.print(resistance);
            myFile.print(" Conductivity= ");
            myFile.print(Siemens);
            myFile.print(" Total Dissolved Solids= ");
            myFile.print(TDS);
            myFile.println(" ");
            myFile.close();

            client.println("<br />");
            client.println("</body>");
            client.println("</html>");
            break;
          }
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        }
        else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    delay(1);
    client.stop();
    Serial.println("client disconnected");
  }
  delay(3000);
}

