#pragma once
#include "Arduino.h"

class rainbowHSV //Создание класса для режима - радуга
{
  public:
    void runPattern(); //Функция запуска режима
  private:
};

void rainbowHSV::runPattern() //Функция запуска режима
{
  
  for(int i = 0; i < NUM_LEDS; i++) //Цикл для присваивония цвета каждому светодиоду
  {
    leds[i] = CHSV(hue + (i * 10), 255, 255);
  }
  EVERY_N_MILLISECONDS(SPEED) { //Прибавление оттенка
    hue++;
  }
  FastLED.show(); //Вывод цвета на ленту
}
