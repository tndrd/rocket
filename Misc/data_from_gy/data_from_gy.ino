#include <VB_MPU9250.h>
#include <VB_BMP280.h>

bool imu_connection;
bool barometer_connection;
unsigned long time;

VB_MPU9250 imu;
VB_BMP280 barometer;
String id = "1A";
bool start = 0;
bool apogee = 0;
bool separate = 0;
bool success_sep = 0;
bool landing = 0;

void setupSensors() {
    imu_connection   = (imu.begin() == MPU_OK);
    barometer.start_altitude = 132; //check the real 
    barometer_connection = barometer.begin();
}

void setup() {
    Serial.begin(57600);
    setupSensors();
}
 


void loop() {
    if ((imu_connection && barometer_connection)) {
        time = millis();
        
        imu.read();
        barometer.read();

        Serial.println(id+";"+String(time)+";"+String(barometer.alti)+";"+String(sqrt(imu.ax*imu.ax+imu.ay*imu.ay+(imu.az-1.1)*(imu.az-1.1)))+";"+String(start)+";"+String(apogee)+";"+String(separate)+";"+String(success_sep)+";"+String(landing));
        //Serial.println(sqrt(imu.ax*imu.ax+imu.ay*imu.ay+(imu.az-1.1)*(imu.az-1.1)));

    } else {
        Serial.println("Something is wrong");
        setupSensors();
    }

    delay(10);
}


