//================ Порты ====================================================
#define NUM_LEDS 80 //Количество светодиодов на ленте
#define LED_PIN 12 //Порт управления лентой
#define POT A0 //Потециометр
#define BTN 3 //Кнопка

//=============== Библиотеки ================================================
#include <FastLED.h> //Светодиодная лента

//================ Переменные ===============================================
#define SPEED 25

uint8_t hue = 0; //Оттенок
uint16_t potRead; //Данные с потециометра
uint8_t brightness; //Яркость
uint8_t patternCounter; //Счетчик нажатий
bool off; //Флаг выключения
bool brightFromPot = true;

CRGB leds[NUM_LEDS]; //Массив под светодиоды

//================ Заголовки ========================================================
#include "bluetooth.h" //Блютуз
#include "button.h" //Настройка кнопок
#include "rainbowHSV.h" //Радуга(ЛГБТ!)
#include "changingColor.h" //Плавная смена цвета
#include "colorConfigurate.h" //Ручная настройка цветов
#include "white.h" //Градиент
#include "effect.h" //Переключатель режимов

//================ SETUP ======================================================
void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS); //Настройка библиотеки под ленту
  FastLED.setCorrection(TypicalPixelString); //Коррекция
  FastLED.setTemperature(Halogen); //Температура
  attachInterrupt(digitalPinToInterrupt(BTN), Click, RISING); //Установка прерывания на кнопку
  Serial.begin(9600); //Проброс порта
  pinMode(BTN, INPUT); //Вход кнопки
  pinMode(POT, INPUT); //Вход потециометра
  patternCounter = 0; //Обнуление счетчика режимов
}

//============== LOOP =============================================================
void loop() {
  scanPot(); //Сканирование положения потоциометра
  start(); //Включение эффектов

  scan(); //Сканирование Bluetooth

  FastLED.setBrightness(brightness); //Установка яркости
}

//============= Функции ==============================================================
void Click()
{
  nextPattern();
}