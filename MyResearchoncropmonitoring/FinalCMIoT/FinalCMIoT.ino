#include <SimpleDHT.h>

// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);

int sensorValue;
int digitalValue;

//rain
const int sensorMin = 0; 
const int sensorMax = 1024; 
void setup()
{

Serial.begin(9600); // sets the serial port to 9600
pinMode(13, OUTPUT);
pinMode( 3, INPUT);

}


void loop()
{
sensorValue = analogRead(0);       // read analog input pin 0

int sensorReading = analogRead(2);
int range = map(sensorReading, sensorMin, sensorMax, 0, 3);


// read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
  
 
  
  // DHT11 sampling rate is 1HZ.
  //delay(1000);

  // read the input on analog pin 0:
  int sensorvalue = analogRead(1);
      // prints the value read
Serial.print(sensorValue, DEC);Serial.print(",");
Serial.print((int)temperature);Serial.print(",");
Serial.print((int)humidity);Serial.print(",");
Serial.print(sensorvalue);Serial.print(",");
switch (range)
    {
      case 0:
        Serial.print("RAINING");
        break;

      case 1:
        Serial.print("RAIN WARNING");
        break;

      case 2:
        Serial.print("NOT RAINING");
        break;
    }
  Serial.print("\n");
delay(60000);
}
