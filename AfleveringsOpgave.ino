#include "Interface.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
DateTime now; // Datetime variable, som bliver initializeret i Loop.
RTC_DS3231 rtc;
DHT dht(DHTPIN, DHTTYPE);

int btnChoise = 1;
bool onMenu = true;

EasyButton selectButton(SELECT_BTN);
EasyButton plusButton(PLUS_BTN);
EasyButton minusButton(MINUS_BTN);
EasyButton saveButton(SAVE_BTN);


void setup () {
  Serial.begin(9600);

  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
	{ // Address for 128x64
		Serial.println(F("SSD1306 allocation failed"));
		for(;;); // Don't proceed, loop forever
	}
  
  //BUTTONS
  selectButton.begin();
  plusButton.begin();
  minusButton.begin();
  saveButton.begin();

  plusButton.onPressed(menuBtnPlus);
  plusButton.enableInterrupt(btnPlusRead);
  minusButton.onPressed(menuBtnMinus);
  minusButton.enableInterrupt(btnMinusRead);
  selectButton.onPressed(MenuFalse);
  selectButton.enableInterrupt(btnSelectRead);
  //dht initializere
  dht.begin();
}


void loop () {
    now = rtc.now(); // Initializere time.
    display.clearDisplay();
    display.setTextColor(WHITE); // Draw white text
    if(onMenu)
    {
      Menu();
    }
    else
    {
      switch (btnChoise) 
      {
        case 1:
          //do something when btnChoise equals 1
          display.setTextSize(2); // Normal 1:1 pixel scale
          display.setCursor(0,10); // Start at top-left corner
          ShowDate(); 
          display.setCursor(0,30);
          ShowTime();
          break;
        case 2:
          //do something when btnChoice equals 2
          display.setTextSize(2); // Normal 1:1 pixel scale
          ShowTemp(); // Show Temperature
          break;
        case 3:
          display.setTextSize(2); // Normal 1:1 pixel scale
          ShowHumidity(); // Show Humidity
          break;
        default:
          display.print("INVALID INPUT, TRY AGAIN!");
          break;
      }
  }
  display.display();
}
