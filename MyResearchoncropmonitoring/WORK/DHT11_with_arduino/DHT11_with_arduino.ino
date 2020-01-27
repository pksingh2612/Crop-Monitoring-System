#include <SimpleDHT.h>

// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);

void setup() {
   // start working...
 Serial.println("Temperature and Humidity Data...");
  Serial.begin(9600);
}

void loop() {
 
  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
  
  Serial.print((int)temperature); Serial.print(","); 
  Serial.println((int)humidity);
  
  // DHT11 sampling rate is 1HZ.
  delay(1500);
}
