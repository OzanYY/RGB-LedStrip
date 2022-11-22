#pragma once
#include "Arduino.h"

class white //Создание класса для режима - градиент
{
  public:
    void runPattern(); //Функция запуска режима
  private:
};

void white::runPattern() //Функция запуска режима
{
  fill_solid(leds, NUM_LEDS, CRGB(255, 255, 255));
  FastLED.show(); //Вывод цвета на ленту
}
  
