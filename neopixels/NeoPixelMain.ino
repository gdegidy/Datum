/*
 *
 *   ####            ##  ######   #######   #######  ##       ########   #######   #######  ##     ## 
 *  ##  ##  ##      ##  ##    ## ##     ## ##     ## ##       ##     ## ##     ## ##     ## ###   ### 
 *       ####      ##   ##       ##     ## ##     ## ##       ##     ## ##     ## ##     ## #### #### 
 *                ##    ##       ##     ## ##     ## ##       ########  ##     ## ##     ## ## ### ## 
 *               ##     ##       ##     ## ##     ## ##       ##   ##   ##     ## ##     ## ##     ## 
 *              ##      ##    ## ##     ## ##     ## ##       ##    ##  ##     ## ##     ## ##     ## 
 *             ##        ######   #######   #######  ######## ##     ##  #######   #######  ##     ##  
 *             
 *             
 *     08/22/22
 *     Written by Greg from Fairfield
 *     Big Fun Light Strip Alternating Colors
 *
 */

#include <Adafruit_NeoPixel.h>
#include <Arduino.h>
#include "thingProperties.h"
Adafruit_NeoPixel pixels(200, 0, NEO_GRB + NEO_KHZ800);
void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  pixels.begin();
}
void loop() {
  ArduinoCloud.update();
  if(ArduinoCloud.connected() == 0){
    Serial.println("Not Connected");
    delay(100);
  }
}
bool pixelPlace = 0;
void onNeopixelsChange(){
  Serial.println("Change");
  if(neopixels.getSwitch() == 0){
    for(int i = 0; i < 200; i++){
      pixels.setPixelColor(i, pixels.Color(0,0,0));
      pixels.show();
      delay(30);
    }
  }else{
    uint8_t r, g, b;
    neopixels.getValue().getRGB(r, g, b);
    for(int i = pixelPlace; i < 200; i+=2){
      pixels.setPixelColor(i, pixels.Color(r, g, b));
      pixels.show();
      delay(30);
    }pixelPlace = pixelPlace == 0 ? 1 : 0;
  }
}
