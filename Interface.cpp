#include "Interface.h"

extern Adafruit_SSD1306 display;
extern DateTime now;
extern DHT dht;
extern int btnChoise;
extern EasyButton plusButton;
extern EasyButton selectButton;
extern EasyButton minusButton;
extern EasyButton saveButton;
extern bool onMenu;

void ShowTime()
{
    timePlusZero(now.hour());
    display.print(now.hour(), DEC);
    display.print(':');
    timePlusZero(now.minute());
    display.print(now.minute(), DEC);
    display.print(':');
    timePlusZero(now.second());
    display.print(now.second(), DEC);
    display.println();
}

void ShowDate()
{
    timePlusZero(now.day());
    display.print(now.day(), DEC);
    display.print('/');
    timePlusZero(now.month());
    display.print(now.month(), DEC);
    display.print('/');
    display.print(now.year(), DEC);
}

void ShowTemp()
{
  float t = dht.readTemperature(); // Read temperature as Celsius (the default).
  display.setCursor(0,20);
  display.print(F("Temperatur "));
  display.print(t);
  if (isnan(t)) 
  {
    display.print(F("Failed to read from DHT sensor!"));
    return;
  }
}


void ShowHumidity()
{
  float h = dht.readHumidity();// Reading humidity.
  display.setCursor(0,10);
  display.print(F("Humidity: "));
  display.print(h);
  display.print(" %");
  if (isnan(h)) 
  {
    display.print(F("Failed to read from DHT sensor!"));
    return;
  }
}

void timePlusZero(DateTime time)
{
  if(time < 10)
  {
    display.print("0");
  }
}

void Menu()
{
  display.setTextSize(1.3); // Normal 1:1 pixel scale
  display.setCursor(0,10);
  display.print("1- Time/Date");
  display.setCursor(0,30);
  display.print("2- Temperature");
  display.setCursor(0, 50);
  display.print("3- Humidity");
}

void menuBtnPlus()
{
  if(btnChoise < 3)
  {
    btnChoise++;
  }
}

void menuBtnMinus()
{
  if(btnChoise > 1)
  {
    btnChoise--;
  }
}

void btnPlusRead()
{
  plusButton.read();
}

void btnMinusRead()
{
  minusButton.read();
}

void btnSelectRead()
{
  selectButton.read();
}

void btnSaveRead()
{
  saveButton.read();
}

void MenuFalse()
{
  onMenu = !onMenu; 
}
