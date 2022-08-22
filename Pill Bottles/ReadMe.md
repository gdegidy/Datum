# Pill Bottle Lights
#### This uses a strip of 50 individual neopixels wired together that I found on [Aliexpress](https://www.aliexpress.com/item/2251832843155630.html?spm=a2g0o.order_list.0.0.79a11802pMhqkL).
When they arrived, I didn't know what to do with them but
I remembered a tiktok that my friend sent to me where there were a bunch of lit up pill bottles hanging from the walls like christmas lights, so I just stole the idea and made that. [(Original TikTok)](https://www.tiktok.com/@kylierae7116/video/7075654022283218218?is_from_webapp=v1&item_id=7075654022283218218&lang=en)

  I changed their setup where they had regular christmas lights in the bottles, I used WS2811 individually addressable neopixels so I could control the color and do a carnival-esque animation where an off neopixel scoots one to the right every second. I also used an ESP-01 as the microcontroller so I was able to connect it to the Arduino IoT cloud and control it with Alexa like the other ~/coolRoom devices.
I drilled a hole in the center of each lid for the WS2811 neopixels to slide into. I have my typical setup of 5 volts going into the pixels and 5v-3v regulator to power the esp which sends out data to the pixels.
<p align="center"><img src="https://github.com/gdegidy/coolRoom/blob/main/Images/GithubImages/BetterVoltageSetup.png" height="200">

I slipped all of the electronics into the first pill bottle which doesn't have a light in it. It has a DC5V port coming out of the bottom for power.

# Code Description
The code first does all the initiation stuff for the neopixels and IoT. The Arduino IoT Cloud works by calling a request to get all values from the project and a function is called if there is a new value. To make the motion more fluid, I only update the cloud values every 2 seconds. I defined every every 10th pixel (0, 10, 20, 30, 40) to an array called offPixels. Every half second, the code adds 1 to each value in offPixels, turns those pixels off, and turns the previous (n-1) pixel back to the iot RGB value.
```
offPixels[5] = {0, 10, 20, 30, 40};
if(t-ct >= 500){
  for(int i = 0; i < 5; i++){
    offPixels[i] += 1;
    pixels.SetPixelColor(offPixels[i-1], pixels.Color(r, g, b));
    pixels.setPixelColor(offPixels[i], pixels.Color(0,0,0));
  }
  ct = t;
}
```
  
