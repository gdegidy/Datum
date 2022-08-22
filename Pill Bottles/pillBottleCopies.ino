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
 *     Pill Bottle IoT Lights
 *
 */
#include "thingProperties.h"
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pixels(50, 0, NEO_GRB + NEO_KHZ800);
uint8_t r, g, b;
bool io = 1;
void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  delay(1500);
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  pixels.begin();
}

long ctRefresh = 0;
long ctLightChange = 0;
int lightsOff[5] = {0, 10, 20, 30, 40};

void loop() {
  long t = millis();
  if(t-ctRefresh >= 2000){
    ArduinoCloud.update();
    ctRefresh = t;
  }
  if(Serial.available() > 0){
    int sig = Serial.read();
    switch(sig){
      default:
      break;
    }
  }
  
  if(t-ctLightChange >= 250){
    for(int i = 0; i < 5; i++){
      pixels.setPixelColor(lightsOff[i], pixels.Color(0,0,0));
      pixels.setPixelColor(lightsOff[i]-1, pixels.Color(g, r, b));
    }
    if(lightsOff[0] >= 10){
      for(int i = 0; i < 5; i++){
        lightsOff[i] = lightsOff[i] - 10;
      }
    }else{
      for(int i = 0; i < 5; i++){
        lightsOff[i] += 1;
      }
    }
    pixels.show();
    ctLightChange = t;
  }
}


/*
  Since Lights is READ_WRITE variable, onLightsChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLightsChange()  {
  // Add your code here to act upon Lights change
  if(lights.getSwitch() ==1){
    lights.getValue().getRGB(r, g, b);
  }else{
    r = 0;
    g = 0;
    b = 0;
  }
  io = lights.getSwitch();
  Serial.println("Lights Changed");
  Serial.println(r);
  Serial.println(g);
  Serial.println(b);
  pixels.fill(io == 1 ? pixels.Color(g, r, b) : pixels.Color(0,0,0));
  pixels.show();
  delay(25);
}
