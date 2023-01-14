#include "Arduino.h"

void nextPattern()//Функция переключения режимов
{
  patternCounter = (patternCounter + 1) % 4; //Подсчет нажатий и выбор режима
}

void scanPot()//Функция сканирования потоциометра
{
  potRead = analogRead(POT); //Считывание положения потециметра
  switch(brightFromPot)
  {
    case 0: brightness = intData[3]; break;
    case 1: brightness = map(potRead, 0, 1023, 0, 255); break; //Конвертация данных из 16 байт в 8 байт
  }
}
