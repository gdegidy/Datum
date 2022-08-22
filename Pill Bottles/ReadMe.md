# Pill Bottle Lights
#### This uses a strip of 50 individual neopixels wired together that I found on [Aliexpress](https://www.aliexpress.com/item/2251832843155630.html?spm=a2g0o.order_list.0.0.79a11802pMhqkL).
When they arrived, I didn't know what to do with them but
I remembered a tiktok that my friend sent to me where there were a bunch of lit up pill bottles hanging from the walls like christmas lights, so I just stole the idea and made that. [(Original TikTok)](https://www.tiktok.com/@kylierae7116/video/7075654022283218218?is_from_webapp=v1&item_id=7075654022283218218&lang=en)

  I changed their setup where they had regular christmas lights in the bottles, I used WS2811 individually addressable neopixels so I could control the color and do a carnival-esque animation where an off neopixel scoots one to the right every second. I also used an ESP-01 as the microcontroller so I was able to connect it to the Arduino IoT cloud and control it with Alexa like the other ~/coolRoom devices.
I drilled a hole in the center of each lid for the WS2811 neopixels to slide into. I have my typical setup of 5 volts going into the pixels and 5v-3v regulator to power the esp which sends out data to the pixels.
I slipped all of the electronics into the first pill bottle which doesn't have a light in it. It has a DC5V port coming out of the bottom for power.
<p align="left"><img src="https://github.com/gdegidy/coolRoom/blob/main/Images/GithubImages/PillBottlesBTS.jpg" height="300"></p>

# Code Description
The code first does all the initiation stuff for the neopixels and IoT. The Arduino IoT Cloud works by calling a request to get all values from the project and a function is called if there is a new value. To make the motion more fluid, I only update the cloud values every 2 seconds. I defined every every 10th pixel (0, 10, 20, 30, 40) to an array called offPixels. Every half second, the code adds 1 to each value in offPixels, turns those pixels off, and turns the previous (n-1) pixel back to the iot RGB value.
```
long t = millis();
long ct = 0;
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
This is to get the gist of the code. It wouldn't work in a loop().

# Materials
> I used 50pcs NeoPixels from Aliexpress that I have hyperlinked. For whatever reason, the red and green were flipped compared to the Adafruit NeoPixel library, so I just had to say set(g, r, b) instead of set(r, g, b) and that fixed the problem.

> I used the LM2596 buck converter but I reccomend using the AMS1117 for this project because of the low current fed throught the converter, into the controller.

|Item|Cost|
|---|---|
|[WS2811 5V Neopixels](https://www.aliexpress.com/item/2251832843155630.html?spm=a2g0o.order_list.0.0.671c1802psSvvB) (I use 50) | $12|
|[ESP-01](https://www.aliexpress.com/item/2251832475975062.html?spm=a2g0o.productlist.0.0.7a702136Cmue7f&algo_pvid=073089c8-7c02-4a70-a244-733f9583f2a9&algo_exp_id=073089c8-7c02-4a70-a244-733f9583f2a9-10&pdp_ext_f=%7B"sku_id"%3A"59938322143"%7D&pdp_npi=2%40dis%21USD%211.83%210.93%21%21%21%21%21%402101e9d216611991857737023e672e%2159938322143%21sea&curPageLogUid=LlrYAvQzM8Mn)|$3|
|Voltage Converter <br> [AMS-1117](https://www.aliexpress.com/item/2251832643007346.html?spm=a2g0o.productlist.0.0.1843604bkhVkza&algo_pvid=fb6c2a8b-6392-49f0-a3d6-b9b9533e0faf&algo_exp_id=fb6c2a8b-6392-49f0-a3d6-b9b9533e0faf-14&pdp_ext_f=%7B"sku_id"%3A"12000016563401920"%7D&pdp_npi=2%40dis%21USD%213.26%213.03%21%21%21%21%21%402101e9d216611995861102235e6724%2112000016563401920%21sea&curPageLogUid=spPbw5EVek5G) <br> [LM2596](https://www.amazon.com/gp/product/B008BHBEE0/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)| <br> ~$0.20 <br> ~$1.40
|Empty Pill Bottles | These are probably illegal to buy|

