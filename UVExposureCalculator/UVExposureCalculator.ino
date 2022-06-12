#include <Wire.h>
#include <LiquidCrystal.h>
#include "Adafruit_VEML6070.h"

// initialize the uv sensor
Adafruit_VEML6070 uv = Adafruit_VEML6070();
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


int currentUV = 0;
unsigned long scaledUV = 0;
unsigned long totalUV = 0;

void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  uv.begin(VEML6070_4_T);  // pass in the integration time constant
  
  lcd.print("UV Exposure");
  lcd.setCursor(0, 1);
  lcd.print("1 Sample 1/2 Second");
  lcd.setCursor(8, 0);
  delay(2000);
  lcd.clear();
}

void loop() {
  
  lcd.setCursor(0,0);
  lcd.print("");
  incrementUV();
  displayCurrentUV();
  displayTotalUV();
}

int smoothedUV() {
  int tempUV = 0;
  for (int i = 0; i < 2; i++) {
  tempUV += uv.readUV();
  }
  return tempUV/2;
}

void incrementUV() {
 currentUV = smoothedUV() / 4;
 totalUV += currentUV;
 scaledUV = totalUV / 1024;
}

void displayCurrentUV() {
  lcd.setCursor(0,0);
  lcd.print("Current: ");
  lcd.setCursor(9, 0);
  if (currentUV < 100) {
   lcd.print(" ");
  }
  if (currentUV < 10) {
    lcd.print(" ");
  }
  
  lcd.print(currentUV);
  lcd.print("  ");
}

void displayTotalUV() {
  lcd.setCursor(2,1);
  lcd.print("Total: ");
  lcd.setCursor(9, 1);
  if (scaledUV < 100) {
   lcd.print(" ");
  }
  if (scaledUV < 10) {
    lcd.print(" ");
  }
  
  lcd.print(scaledUV);
  lcd.print("  ");
}
