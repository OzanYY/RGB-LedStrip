//=============== Библиотеки ================================================
#include <FastLED.h> //Светодиодная лента
#include <GParser.h> //Парсер
#include <parseUtils.h>
#include <unicode.h>
#include <url.h>

//================ Порты ====================================================
#define NUM_LEDS 75 //Количество светодиодов на ленте
#define LED_PIN 12 //Порт управления лентой
#define POT A0 //Потециометр
#define BTN 3 //Кнопка

//================ Переменные ===============================================
#define SPEED 25

uint8_t hue = 0; //Оттенок
uint16_t potRead; //Данные с потециометра
uint8_t brightness; //Яркость
uint8_t patternCounter; //Счетчик нажатий
bool off; //Флаг выключения
bool brightFromPot = true;

CRGB leds[NUM_LEDS]; //Массив под светодиоды

//================ ООП ========================================================
#include "bluetooth.h" //Блютуз
#include "rainbowHSV.h" //Радуга(ЛГБТ!)
#include "changingColor.h" //Плавная смена цвета
#include "button.h" //Настройка кнопок
#include "colorConfigurate.h" //Ручная настройка цветов
#include "white.h" //Градиент

//================ DATA =======================================================
rainbowHSV rainbow; //Создание объекта в классе rainbowHSV
changingColor changing; //Создание объекта в классе changingColor
btn_conf btnConf; //Создание объекта в классе btn
colorConfigurate configurate; //Создание объекта в классе colorConfigurate
white white; //Создание объекта в классе gradient
bluetooth bluetooth;
parser parser;

#include "effect.h" //Переключатель режимов
effect effect; //Создание объекта в классе effect

//================ SETUP ======================================================
void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS); //Настройка библиотеки под ленту
  FastLED.setCorrection(TypicalPixelString); //Коррекция
  FastLED.setTemperature(Halogen); //Температура
  attachInterrupt(digitalPinToInterrupt(BTN), Click, RISING); //Установка прерывания на кнопку
  Serial.begin(9600); //Проброс порта
  Serial.setTimeout(5); //Установка timeout для Serial
  pinMode(BTN, INPUT); //Вход кнопки
  pinMode(POT, INPUT); //Вход потециометра
  patternCounter = 0; //Обнуление счетчика режимов
}

//============== LOOP =============================================================
void loop() {
  btnConf.scanPot(); //Сканирование положения потоциометра
  effect.start(); //Включение эффектов

  bluetooth.scan(); //Сканирование Bluetooth

  FastLED.setBrightness(brightness); //Установка яркости
}

//============= Функции ==============================================================
void Click()
{
  Serial.println("touch");
  btnConf.nextPattern();
}