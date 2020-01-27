#include "cactus_io_DHT22.h" // header file

#define DHT22_PIN 2 // This pin is used for taken digital data from DHT22 module on arduino UNO digital pin 2

DHT22 dht(DHT22_PIN); // this is a built-in function with one parameter dht(pin2).


int sensorValue; // here we define this variable to assign analog value of mq135 gas module. 

//this is rain sensor min and max value or range[0,1024]
const int sensorMin = 0; 
const int sensorMax = 1024; 


void setup()
{
  Serial.begin(9600); // sets the serial port to 9600
    
  dht.begin(); // dHT module begin
    
}

void loop()
{
 
    sensorValue = analogRead(0);       // air gas
    
    int sensorvalue = analogRead(1); //soil moisture
      
    int sensorReading = analogRead(2); // rain sensor
    
    int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
    
    dht.readHumidity(); // this function read humidity data and send to arduino uno board
    dht.readTemperature();// this function read temperature data and send to arduino uno board
      
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
