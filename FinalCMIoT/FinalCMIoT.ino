#include "cactus_io_DHT22.h"
#define DHT22_PIN 2 // what pin on the arduino is the DHT22 data line connected to

DHT22 dht(DHT22_PIN);

int sensorValue;
int digitalValue;

//rain
const int sensorMin = 0; 
const int sensorMax = 1024; 
//byte byteRead;

void setup()
{
Serial.begin(9600); // sets the serial port to 9600
pinMode(13, OUTPUT);
pinMode( 3, INPUT);

//Serial.println("DHT22 Humidity - Temperature Sensor");
//Serial.println("RH\tTemp (C)\tTemp (F)");//\tHeat Index (C)\tHeat Index (F)");
dht.begin();
  
}

void loop()
{
 //  if (Serial.available()>0) 
 //  {
    /* read the most recent byte */
 //   byteRead = Serial.read();
 //   if(byteRead==48)//0
 //   {
    sensorValue = analogRead(0);       // air gas
    
    int sensorvalue = analogRead(1); //soil moisture
      
    int sensorReading = analogRead(2); // rain sensor
    
    int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
    
    dht.readHumidity();
    dht.readTemperature();
      
    // Check if any reads failed and exit early (to try again).
      if (isnan(dht.humidity) || isnan(dht.temperature_C)) {
      Serial.println("DHT sensor read failure!");
      return;
      }
    
          // prints the value read
    Serial.print(sensorValue, DEC);Serial.print(",");// air gas
    Serial.print(dht.humidity); Serial.print(",");
    Serial.print(dht.temperature_C); Serial.print(",");
    Serial.print(dht.temperature_F); Serial.print(",");
    Serial.print(sensorvalue);Serial.print(","); // soil moisture
    switch (range)
        {
          case 0:
            Serial.print("1");//RAINING
            break;
    
          case 1:
            Serial.print("0.5");//RAIN WARNING
            break;
    
          case 2:
            Serial.print("0");//NOT RAINING
            break;
        }
      Serial.print(",\n");
    delay(100);
    }
//  }
//}
