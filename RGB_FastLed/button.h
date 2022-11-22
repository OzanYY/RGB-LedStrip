#pragma once
#include "Arduino.h"

class btn_conf //Создание класса для кнопок
{
  public:
    void nextPattern(); //Функция переключения режимов
    void scanPot(); //Функция сканирования потоциометра
  private:
};

void btn_conf::nextPattern()//Функция переключения режимов
{
  patternCounter = (patternCounter + 1) % 4; //Подсчет нажатий и выбор режима
}

void btn_conf::scanPot()//Функция сканирования потоциометра
{
  potRead = analogRead(POT); //Считывание положения потециметра
  switch(brightFromPot)
  {
    case 0: brightness = intData[3]; break;
    case 1: brightness = map(potRead, 0, 1023, 0, 255); break; //Конвертация данных из 16 байт в 8 байт
  }
}
