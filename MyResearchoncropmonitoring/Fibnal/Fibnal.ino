#include <SimpleDHT.h>
// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);

int sensorValue;
int digitalValue;
void setup()
{

Serial.begin(9600); // sets the serial port to 9600

pinMode(13, OUTPUT);
pinMode( 3, INPUT);

// start working...
Serial.println("Temperature and Humidity Data...");
}


void loop()
{
sensorValue = analogRead(0); // read analog input pin 0
digitalValue = digitalRead(2); 

if(sensorValue>400)
{
digitalWrite(13, HIGH);
}
else
digitalWrite(13, LOW);
Serial.println(sensorValue, DEC); // prints the value read
Serial.println(digitalValue, DEC);
delay(1000); // wait 100ms for next reading

// read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
}
  
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" H");
  
  // DHT11 sampling rate is 1HZ.
  delay(1500);
  
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  
  Serial.println(sensorValue);
  delay(1000);

  
}
