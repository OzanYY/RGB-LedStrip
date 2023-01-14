#include "Arduino.h"

rainbowHSV rainbow; //Создание объекта в классе rainbowHSV
changingColor changing; //Создание объекта в классе changingColor
colorConfigurate configurate; //Создание объекта в классе colorConfigurate
white white; //Создание объекта в классе gradient

void start() //Функция запуска режима
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
