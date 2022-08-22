[Watch The Video Tutorial](https://drive.google.com/file/d/1q8wW7tiSs-QX5U77vw8-VzYiKtA6Mmot/view?usp=sharing)
# Backstory
I am in the middle of a possibly endless project I call "~/coolRoom" where I create as many smart home devices to create a college dorm that has never been experienced by mankind. I want this project to be able to take the vibe of the room and flip it on its head in a second. I already have a variety of devices that I will set up to work with the datum.

# Datum
The Datum is a project that will act as a controller for the room although it will remain stationary and output serial bytes that can be read from other devices, from a serial cable running along the perimiter of the room. The Datum will also have a wireless module (Currently thiniking radio or BT) that can connect to a controller which is not made but will be a smaller, handheld device.

The idea for this project is to have one Serial wire and one ground wire around the perimiter of the room and connect devices that can interpret the signal. I designed it to look like a military machine since it is in charge of everything in the room and it will sit stationary on a desk. 

I will use two microcontrollers for this project. One will act as a keyboard and send keystroke signals through Serial to the other microcontroller which will control the lcd screen and leds and send the final serial signals through the whole room.

# Design
The Datum has one large joystick from microcenter to the left of a 3x3 button array to the left of one big button all on the top panel. On the bottom panel, there is a 4x3 led array, Then four switches and the lcd on the bottom. The lcd also has five menu buttons below it.

# Hotkeys and Memory Usage
While the datum is at idle, any button except for the big button and menu buttons can be programmed to send a certain code through serial. The big button will be responsible for a series of signals sent that will cause the most chaos and anxiety in the room as fast as possible because my roommate and I think it would be funny. The EEPROM Adresses and Serial output bytes can be seen on the excel document.

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
