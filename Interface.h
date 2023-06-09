#include <Arduino.h>
#include "RTClib.h"
#include "DHT.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EasyButton.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET 4 // Reset pin # (or -1 if sharing Arduino reset pin)

#define SELECT_BTN 8 // Select/Edit button
#define PLUS_BTN 9 // "+" button
#define MINUS_BTN 10 // "-" button
#define SAVE_BTN 11 // Save button

#define DHTPIN 5  
#define DHTTYPE DHT11

void ShowTime();
void ShowDate();
void timePlusZero(DateTime time);
void Menu();
void ShowHumidity();
void ShowTemp();
void menuBtnPlus();
void menuBtnMinus();
void btnMinusRead();
void btnPlusRead();
void btnSaveRead();
void btnSelectRead();
void MenuFalse();