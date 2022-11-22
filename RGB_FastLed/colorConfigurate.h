#pragma once
#include "Arduino.h"

class colorConfigurate //Создание класса для ручного управления цветами
{
  public:
    void runPattern(); //Запуск режима
    void off(); //Выключение ленты
  private:
};

void colorConfigurate::runPattern()//Запуск режима
{ 
  int r = intData[4]; //Присваивание красного цвета
  int g = intData[5]; //Присваивание зеленого цвета
  int b = intData[6]; //Присваивание синего цвета
 
  fill_solid(leds, NUM_LEDS, CRGB(r, g, b)); //Вывод цвета на ленту
  EVERY_N_MILLISECONDS(25) {FastLED.show();} //Каждые 15мс обновление цветов ленты
}

void colorConfigurate::off() //Функция выключения ленты
{
    fill_solid(leds, NUM_LEDS, CRGB::Black); //Выключение светодиодов
    FastLED.show(); //Обновление ленты
}