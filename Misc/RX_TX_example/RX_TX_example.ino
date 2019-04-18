#include <SoftwareSerial.h>
#include <ArduinoJson.h>

SoftwareSerial radioSerial(9, 1); //Vcc - 5V, Gng - gnd, Txd - 9, Rxd - Txd
JsonObject& root = StaticJsonBuffer<200>().createObject(); //Example of creating JSON object

void setup() {
  radioSerial.begin(9600); //Init of radio serial
  Serial.begin(9600);
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
  JsonObject& jsonData = DynamicJsonBuffer().parseObject(data);
  return jsonData;
}

// Just sending JSON
void send_data(JsonObject& data) {
  String output;
  data.printTo(output);
  radioSerial.println(output);
}

void loop() {

}