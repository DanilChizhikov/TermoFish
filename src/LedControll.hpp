#include "Adafruit_NeoPixel.h"
#include <math.h>

#define LED_COUNT 6
#define LED_PIN 13

void LedSetup();

void LedSetColor(int red, int green, int blue);

void LedOneSetColor(int indexLed, int red, int green, int blue);

void LedOff();