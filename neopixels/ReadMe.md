<h1 align="center">Neopixels</h1>
<br>
<p align="center">
  <img src="https://github.com/gdegidy/coolRoom/blob/main/Images/TVHeadOn.png" style="width: 85%">
  <br>
  Neopixels shown above TV along the ceiling
</p>

The neopixels are just a strip of 200 WS2812B Neopixels controlled by Arduino IoT Cloud. These pixels are pretty basic but every time you set a color, it sets every other pixel to that color, so you can get cool lighting effects or really vibrant light if the two colors are slightly different. 

# Setup
I'm using an ESP-01 in a 3d printed housing to control the pixels through Arduino IoT Cloud. I have 5v going to the pixels and a 5v-3.3v
buck converter which powers the chip which sends data to the pixels.

<p align="center"><img src="https://github.com/gdegidy/coolRoom/blob/main/Images/GithubImages/BetterVoltageSetup.png" width=300></p>

## Usage:

#### ex 1:
"Set the color to red", "Set the color to green"
<br>
<br>
rgrgrgrg...

#### ex 2:
"Set the Color to red" 

r0r0r0r0...

"Set the Color to red"

rrrrrrrr...

#### ex 3:
"Set the Color to red"

r0r0r0r0...

"Set the Color to blue"

rbrbrbrb...

"Set the Color to green"

gbgbgbgb...

"Turn the pixels off"

00000000...
