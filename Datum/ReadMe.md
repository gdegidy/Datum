<div align="center">
  <h1>Datum</H1>
  <img src = "https://github.com/gdegidy/coolRoom/blob/main/Images/GithubImages/Datum.png" style="width: 60%;"><br>
  <a href = "https://drive.google.com/file/d/1q8wW7tiSs-QX5U77vw8-VzYiKtA6Mmot/view?usp=sharing">Watch the Video Tutorial</a>
</div>
&nbsp;&nbsp;&nbsp;&nbsp;The datum will act as a stationary way to control all of the devices in the room. It will have a serial cable coming out from the side, running around the perimiter of the dorm room. Devices that can read these serial codes coming from the datum will connect to the serial line and react when it hears a command it was programmed to hear.
<br>
<br>
&nbsp;&nbsp;&nbsp;&nbsp;The Datum is made from two arduino megas. The first mega has all of the buttons and switches hooked into the gpio pins and is programmed to send out bytes corresponding to the button presses sent through serial, into the second arduino mega. The second mega is connected to the lcd screen and interprets a button press from arduino mega 1. Arduino mega 2 is also responsible for the final serial output that will run along the perimeter of the room. All of the bytes from the keyboard and menu are available in the excel document.

# Design
&nbsp;&nbsp;&nbsp;&nbsp;The Datum has one large joystick from microcenter to the left of a 3x3 button array to the left of one big button all on the top panel. On the bottom panel, there is a 4x3 led array, Then four switches and the lcd on the bottom. The lcd also has five menu buttons below it.

# Hotkeys and Memory Usage
&nbsp;&nbsp;&nbsp;&nbsp;While the datum is at idle, any button except for the big button and menu buttons can be programmed to send a certain code through serial. The big button will be responsible for a series of signals sent that will cause the most chaos and anxiety in the room as fast as possible because my roommate and I think it would be funny. The EEPROM Adresses and Serial output bytes can be seen on the excel document.

# Menus
The "First Layer" Menu:
- Device Menu
  - List of all Device Menus
- Preset Menu
  - Preset 1
  - Preset 2
  - ...
  - Preset 10
- Set Preset Menu (presets send 8 programmable signals)
  - Set Preset 1
    - Set Slot 1
      - type byte to send with 9 buttons and big button to act as 0
    - Set Slot 2
      - ...
    - ...
    - Set Slot 8
      - ...
  - Set Preset 2
    - ...
  - ...
  - Set Preset 10
    - ...
- Set HotKey Menu
  - Press Key
    - Type byte to send with 9 buttons and big button to act as 0
- Settings (idrk yet)
