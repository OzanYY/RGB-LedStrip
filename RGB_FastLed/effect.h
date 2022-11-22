#pragma once
#include "Arduino.h"

class effect //Создание класса для режима - градиент
{
  public:
    void start(); //Функция запуска режима
  private:
};

void effect::start() //Функция запуска режима
{
  switch (patternCounter) //Переключение режимов
  {
    case 0:
       off = false;
       changing.runPattern(); break; //Плавная смена цветов
    case 1:
      rainbow.runPattern(); break; //Радуга
    case 2:
      if(off == false) {configurate.off(); off = !off;} //Проверка круга для выключения ленты
       configurate.runPattern(); break; //Ручная настройка
     case 3:
        white.runPattern(); break; //Белый
  }
}
