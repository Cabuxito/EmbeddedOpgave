### Intelligent IoT-Controlled House



## T.O.C

* [Intro](#Intro)
* [Requeriments](#Requeriments)

* [Instructions](#Instructions)

   * [Libraries](#Libraries)
   * [Structure](#Structure)
   
* [Information & tech](#Information-og-tech)
* [Changelog](#Changelog)
* [To-Do](#To-do)
* [Contributing](#Contributing)


## Requirements

- Arduino Zero board. [See Here](https://store.arduino.cc/products/arduino-zero)
- 4 buttons for user input with intern-pullup. [See Here](https://ardustore.dk/produkt/tactile-print-push-button-6x6x5mm?gclid=CjwKCAjw-IWkBhBTEiwA2exyO94873bkykivqHhJ76OJxMIguEzHdmNpNAZ3KMVINccsGDTCjgwn7RoCkdUQAvD_BwE)
- OLED screen for displaying information. [See Here](https://ardustore.dk/produkt/display-oled-0-96%e2%80%b3-i2c-128x64-module-hvid)
- DHT11 sensor for temperature and humidity. [See Here](https://ardustore.dk/produkt/dht-11-temperature-humidity-module)
- DS3231 Real Time Clock. [See Here](https://techbitshop.dk/vare/ds3231-at24c32-rtc-i2c-clock-module/?utm_source=Google+Shopping&utm_medium=cpc&utm_campaign=techbitshop_ctx&gclid=CjwKCAjw-IWkBhBTEiwA2exyO2gDGx2PlvWAkwPOLhUiscW6q3YP58kkfcwnMKu4Ql5crO-m6gcD1RoCbpEQAvD_BwE)

## Intro

I created a display output ( Screen ), where it shows a menu and some functions.
It shows differents options as :

  1 - Time/Date
  2 - Temperature
  3 - Humidity
  
and when one is chosen it will display the properties that correspond to the chosen option.
In the future Change the time and date it will be an option.

The Screen is controlled by 4 buttons and the following buttons functions are: 

| Select |  Plus(+) | Minus(-) | Save  |$----------------$| SCREEN |
| ------ | -------- | ---------| ----- |$----------------$| ------ |
   
## Instructions

1. Connect the components provided in Requeriments, and make sure all is connected properly.
2. Install the required libraries by following their respective installation instructions.
3. Install Arduino IDE (Last version).
4. Open the 'arduino_zero_project.ino' file in the Arduino IDE.
5. Select the Arduino Zero board from the 'Tools' menu.
6. Upload the sketch to the Arduino Zero board.

### Libraries

  - EasyButton - by Evert Arias - https://easybtn.earias.me/

  - RTClib - by Adafruit - https://github.com/adafruit/RTClib

  - DHT sensor library - by Adafruit

  - Adafruit BusIO - by Adafruit

  - Adafruit GFX Library - by Adafruit

  - Adafruit SSD1306 - by Adafruit

### Structure

  #### AfleveringsOpgave.ino
  
    - void setup()
    - void loop()
    
  #### Interface.cpp
    - Functions:
      void ShowTime()
      void ShowDate()
      void TimePlusZero(Datetime time)
      void Menu()
      void ShowHumidity()
      void ShowTemp()
      void menuBtnPlus()
      void menuBtnMinus()
      void btnMinusRead()
      void btnPlusRead()
      void btnSaveRead()
      void btnSelectRead()
      void MenuFalse()
      
    This file contains some extern variables for the efficiency of the functions.
    Remember to include "Interface.h".
    
  #### Interface.h
  
    - Includes
    - Function Prototypes
    - Defines

## Information og tech


| Platform      |    Language   | projectVersion| 
| ------------- | ------------- | ------------- |
|    Arduino    |    c/c++ gnu  |       0.0.1   |
| ------------- | ------------- | ------------- |






## Changelog
[Github](https://github.com/Cabuxito/EmbeddedOpgave) - The full project is ready for you to try it.



## To-do

* Change Date and time with the buttons.
* make graphs about temperature.

## Contributing

* Kevin and Elias did help me with the Select function.
* Thomas did help me with some inspiration for my readme file. 

