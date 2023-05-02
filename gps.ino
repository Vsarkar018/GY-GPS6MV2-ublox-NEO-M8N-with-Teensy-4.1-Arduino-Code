#include <SoftwareSerial.h>
#include <TinyGPS++.h>
SoftwareSerial gpsSerial(0, 1); // RX, TX pins for GPS module
TinyGPSPlus gps;
void setup() {
  Serial.begin(9600); // initialize serial port for debugging
  gpsSerial.begin(9600); // initialize GPS serial port
  // send any necessary configuration commands to the GPS module
}

void loop() {
  if (gpsSerial.available() > 0) {
    // Serial.write(gpsSerial.read());
    gps.encode(gpsSerial.read());// Parse the input from the GY-GPS6MV2 
   if (gps.location.isUpdated()){
     Serial.print("Latitude= "); 
     Serial.print(gps.location.lat(), 6);
     Serial.print(" Longitude= "); 
     Serial.println(gps.location.lng(), 6);
   }
  }
}
