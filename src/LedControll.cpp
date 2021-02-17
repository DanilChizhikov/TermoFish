#include "LedControll.hpp"

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void LedSetup(){
    strip.begin();

    for (int i = 0; i < LED_COUNT; i++)
    {
        strip.setPixelColor(i, strip.Color(48, 199, 88));
        strip.show();
        delay(500);
    }

    for (int i = LED_COUNT; i >= 0; i--)
    {
        strip.setPixelColor(i, strip.Color(0, 0, 0));
        strip.show();
        delay(500);
    }
}

void LedSetColor(int red, int green, int blue){
    for (int i = LED_COUNT; i >= 0; i--)
    {
        strip.setPixelColor(i, strip.Color(red, green, blue));
    }

    strip.show();
    delay(500);
}

void LedOneSetColor(int indexLed, int red, int green, int blue){
    strip.setPixelColor(indexLed, strip.Color(red, green, blue));

    strip.show();
    delay(500);
}

void LedOff(){
    for (int i = 0; i < LED_COUNT; i++)
    {
        strip.setPixelColor(i, strip.Color(0, 0, 0));
    }

    strip.show();
    delay(500);
}