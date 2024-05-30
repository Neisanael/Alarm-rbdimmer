# Automatic Alarm Program

This repository contains a program for an automatic alarm system implemented using an ESP32 microcontroller and Blynk platform for remote control. The alarm system is designed to trigger actions such as turning on a lamp and activating a buzzer at specified times.

## Features
    - Automatic activation of alarm components at predefined times.
    - Integration with Blynk for remote control to control the brightness of the lamp.
    - Utilizes a DS3231 RTC module for precise timekeeping.

## Hardware Requirements

    - ESP32 microcontroller board (e.g., ESP32 DevKit)
    - DS3231 RTC module
    - Lamp (connected to a dimmer module)
    - Buzzer

## Dependencies

Ensure you have the following libraries installed in your Arduino IDE:

1. **WiFi**
   - Library for WiFi connectivity, usually included with the ESP32 core for Arduino.
   - Installation:
     ```arduino
     #include <WiFi.h>
     ```

2. **Blynk**
   - Library for Blynk platform integration.
   - Installation:
     ```arduino
     #include <BlynkSimpleEsp32.h>
     ```

3. **RBDdimmer**
   - Library for controlling dimmer modules.
   - Installation:
     ```arduino
     #include <RBDdimmer.h>
     ```

4. **RTClib**
   - Library for interfacing with RTC modules.
   - Installation:
     ```arduino
     #include <RTClib.h>
     ```

5. **Wire**
   - Library for I2C communication, usually included with the Arduino core.
   - Installation:
     ```arduino
     #include <Wire.h>
     ```

## Schematic

![Schematic](https://github.com/Neisanael/Alarm-rbdimmer/blob/main/Schematic.png?raw=true)

> **Warning:**
> The schematic provided may vary depending on the specific components you are using. Not all components use the same pins. Please refer to the datasheets of your components before making connections to avoid any damage.
