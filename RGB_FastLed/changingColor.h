#pragma once
#include "Arduino.h"

struct changingColor //Создание класса для плавно сменяющегося цвета
{
  void runPattern(); //Функция запуска режим
};

void changingColor::runPattern() //Функция запуска режима
{
  
  for(int i = 0; i < NUM_LEDS; i++) //Цикл для присваивония цвета каждому светодиоду
  {
    leds[i] = CHSV(hue, 255, 255);
  }
  EVERY_N_MILLISECONDS(SPEED) { //Прибовления оттенка
    hue++;
  }
  FastLED.show(); //Вывод цвета на ленту
}
