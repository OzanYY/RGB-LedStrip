#pragma once
#include "Arduino.h"

class bluetooth //Создание класса для режима - градиент
{
  public:
    void scan(); //Функция запуска режима
  private:
};

#define PARSE_AMOUNT 7         // число значений в массиве, который хотим получить
int intData[PARSE_AMOUNT];     // массив численных значений после парсинга
bool recievedFlag;
bool getStarted;
byte index;
String string_convert = "";

void parsing() {
  if (Serial.available() > 0) {
    char incomingByte = Serial.read();        // обязательно ЧИТАЕМ входящий символ
    if (getStarted) {                         // если приняли начальный символ (парсинг разрешён)
      if (incomingByte != ' ' && incomingByte != ';') {   // если это не пробел И не конец
        string_convert += incomingByte;       // складываем в строку
      } else {                                // если это пробел или ; конец пакета
        intData[index] = string_convert.toInt();  // преобразуем строку в int и кладём в массив
        string_convert = "";                  // очищаем строку
        index++;                              // переходим к парсингу следующего элемента массива
      }
    }
    if (incomingByte == '#') {                // если это #
      getStarted = true;                      // поднимаем флаг, что можно парсить
      index = 0;                              // сбрасываем индекс
      string_convert = "";                    // очищаем строку
    }
    if (incomingByte == ';') {                // если таки приняли ; - конец парсинга
      getStarted = false;                     // сброс
      recievedFlag = true;                    // флаг на принятие
    }
  }
}

void bluetooth::scan() //Функция запуска режима
{
  parsing();
  if (recievedFlag) 
  {                           // если получены данные
    recievedFlag = false;
    for (byte i = 0; i < PARSE_AMOUNT; i++) 
    { // выводим элементы массива
      Serial.print(intData[i]); Serial.print(" ");
    } 
    Serial.println();

    if(intData[0] == 1) //Если первое значение массива равно 1, то мы выбираем режим
    {
    switch(intData[1])
      {
        case 0: patternCounter = 0; break;
        case 1: patternCounter = 1; break;
        case 2: patternCounter = 2; break;
        case 3: patternCounter = 3; break;
      }
    }
    switch(intData[2])
    {
      case 0: brightFromPot = false; break;
      case 1: brightFromPot = true; break;
    }
  }
}