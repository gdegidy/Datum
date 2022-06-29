This project is still in the works. I pretty much only have the idea finished

# Datum
The Datum is a project that takes input from a controller and uses arduino to write bytes to the serial out port. This output can be read by a device by the serial in pin and have a set function when it recieves a certain byte.

The idea for this project is to have one Serial wire and one ground wire around the perimiter of the room and connect devices that can interpret the signal. I designed it to look like a military machine since it is in charge of everything in the room and it will sit stationary on a desk. 

# Design
The Datum has one large joystick from microcenter to the left of a 3x3 button array to the left of one big button all on the top panel. On the bottom panel, there is a 4x3 led array, One large potentiometer only to control the lcd brightness, Then four switches and the lcd on the bottom. The lcd also has five menu buttons above it.

# Hotkeys and Memory Usage
While the datum is at idle, any button can be programmed to send a certain code through serial except for the five menu buttons and one big button. The big button will be responsible for a series of signals sent that will cause the most chaos and anxiety in the room as fast as possible because my roommate and I think it would be funny. The EEPROM Adresses and Serial output bytes can be seen on the excel document.

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
