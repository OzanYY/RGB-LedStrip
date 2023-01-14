#pragma once
#include "Arduino.h"

struct white //Создание класса для режима - градиент
{
  void runPattern(); //Функция запуска режима
};

void white::runPattern() //Функция запуска режима
{
  fill_solid(leds, NUM_LEDS, CRGB(255, 200, 255));
  FastLED.show(); //Вывод цвета на ленту
}
  
