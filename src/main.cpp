#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

const int oneWireBus = 4;
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);

void setup() {
  // put your setup code here, to run once:
  // The setup function runs once

  // This starts the serial monitor. The number is the baud rate, which indicates the speed of communication between devices (small baud -> slower communication)
  Serial.begin(115200);

  // Starts the Temp. Sensor. This function is from the DallasTemperature Library.
  sensors.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  // The code will continue through this loop function forever

  // Sets up the request to sense temperatures. Also from DallasTemparature Library
  sensors.requestTemperatures();

  // Sets a float type variable that stores the temperature sensed
  float temperatureC = sensors.getTempCByIndex(0);
  float temperatureF = sensors.getTempFByIndex(0);

  // Prints the temperatures on Serial Monitor. ‘ln’ indicates a new line after printing that statement
  Serial.print(temperatureC);
  Serial.println("ºC");
  Serial.print(temperatureF);
  Serial.println("ºF");

  // Senses the temperature every 5 seconds
  delay(5000);
}