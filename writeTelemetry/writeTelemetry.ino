#include <SD.h>
#include <SPI.h>
#include <ArduinoJson.h>
#include <SoftwareSerial.h>

File myFile;
SoftwareSerial radioSerial(9, 10); //Vcc - 5V, Gng - gnd, Txd - 9, Rxd - Txd
JsonObject& root = StaticJsonBuffer<200>().createObject(); // Creating JSON object

void setup() {
  radioSerial.begin(9600); //Init of radio serial
  Serial.begin(9600);

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");


  //  if (myFile) {
  //    Serial.print("Writing to test.txt...");
  //    myFile.println("testing 1, 2, 3.");
  //    // close the file:
  //    myFile.close();
  //    Serial.println("done.");
  //  } else {
  //    // if the file didn't open, print an error:
  //    Serial.println("error opening test.txt");
  //  }
}

// This func will freeze arduino till data comes into it
JsonObject& wait_for_data() {
  while (!radioSerial.available()) {
    delay(1);
  }
  String data = "";
  while (radioSerial.available()) {
    data += radioSerial.readString();
  }
  DynamicJsonBuffer dynamicJsonBuffer;
  JsonObject& jsonData = dynamicJsonBuffer.parseObject(data);
  return jsonData;
}

void loop() {
  // put your main code here, to run repeatedly:
  JsonObject& danniye = wait_for_data();
  danniye.prettyPrintTo(Serial);
  myFile = SD.open("telemetry.txt", FILE_WRITE);
  danniye.prettyPrintTo(myFile);
  myFile.close();
}
