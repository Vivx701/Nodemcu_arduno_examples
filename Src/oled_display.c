#include <ESP8266WiFi.h>
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`
 
 // Initialize the OLED display using Wire library
SSD1306Wire  display(0x3c, D2, D1);  //D2=SDK  D1=SCK  As per labeling on NodeMCU

void drawLines() {
   display.setColor(WHITE);
  for (int16_t i=0; i<display.getWidth(); i++) {
    display.drawLine(0, 0, i, display.getHeight()-1);
    display.display();
    delay(1);
  }
  for (int16_t i=0; i<display.getHeight(); i++) {
    display.drawLine(0, 0, display.getWidth()-1, i);
    display.display();
    delay(1);
  }
  
}


void setup()
{
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
}

void loop() 
{
  //display.invertDisplay();
  display.clear();
  drawLines();
  delay(3000);
}

 
