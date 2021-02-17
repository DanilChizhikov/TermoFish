#include <OneWire.h>
#include <DallasTemperature.h>
#include "LedControll.hpp"
#include "SDControll.hpp"

#define ONE_WIRE_BUS 10

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

float temperature = 0;

void setup(void){
  Serial.begin(9600);
  sensors.begin();
  LedSetup();
  DisplaySetup();
} 

void LedUpdate(float temp){
  if(temp >= 24 && temp <= 28){
    LedOneSetColor(0, 34, 129, 163);
    LedOneSetColor(1, 34, 129, 163);
    LedOneSetColor(2, 255, 235, 20);
    LedOneSetColor(3, 255, 235, 20);
    LedOneSetColor(4, 59, 240, 14);
    LedOneSetColor(5, 59, 240, 14);
  }

  if(temp > 22 && temp < 24){
    LedOneSetColor(0, 34, 129, 163);
    LedOneSetColor(1, 34, 129, 163);
    LedOneSetColor(2, 255, 235, 20);
    LedOneSetColor(3, 255, 235, 20);
    LedOneSetColor(4, 0, 0, 0);
    LedOneSetColor(5, 0, 0, 0);
  }

  if(temp > 20 && temp <= 22){
    LedOneSetColor(0, 34, 129, 163);
    LedOneSetColor(1, 34, 129, 163);
    LedOneSetColor(2, 0, 0, 0);
    LedOneSetColor(3, 0, 0, 0);
    LedOneSetColor(4, 0, 0, 0);
    LedOneSetColor(5, 0, 0, 0);
  }

  if(temp <= 20){
    LedOneSetColor(0, 34, 129, 163);
    LedOneSetColor(1, 34, 129, 163);
    LedOneSetColor(2, 34, 129, 163);
    LedOneSetColor(3, 34, 129, 163);
    LedOneSetColor(4, 34, 129, 163);
    LedOneSetColor(5, 34, 129, 163);
    delay(200);
    LedOneSetColor(0, 255, 0, 0);
    LedOneSetColor(1, 255, 0, 0);
    LedOneSetColor(2, 255, 0, 0);
    LedOneSetColor(3, 255, 0, 0);
    LedOneSetColor(4, 255, 0, 0);
    LedOneSetColor(5, 255, 0, 0);
  }

  if(temp > 28){
    LedSetColor(255, 0, 0);
  }
}

void loop(void){
  temperature = sensors.getTempCByIndex(0);
  sensors.requestTemperatures();
  Serial.print("Temp: ");
  Serial.println(temperature); 
  Serial.println(round(temperature));
  DisplayUpdate(temperature);

  LedUpdate(temperature);
}