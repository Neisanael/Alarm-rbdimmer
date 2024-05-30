# Automatic Alarm Program

This repository contains a program for an automatic alarm system implemented using an ESP32 microcontroller and Blynk platform for remote control. The alarm system is designed to trigger actions such as turning on a lamp and activating a buzzer at specified times.

## Features
Automatic activation of alarm components at predefined times. Integration with Blynk for remote control to control the brighness of the lamp. Utilizes a DS3231 RTC module for precise timekeeping.

## Hardware Requirements

    - ESP32 microcontroller board (e.g., ESP32 DevKit)
    - DS3231 RTC module
    - Lamp (connected to a dimmer module)
    - Buzzer

## Dependencies

    - Blynk - Library for Blynk platform integration.
    - RBDdimmer - Library for controlling dimmer modules.
    - RTClib - Library for interfacing with RTC modules.

## Schematic

![Schematic](https://github.com/Neisanael/Alarm-rbdimmer/blob/main/Schematic.png?raw=true)

> **Warning:**
> The schematic provided may vary depending on the specific components you are using. Not all components use the same pins. Please refer to the datasheets of your components before making connections to avoid any damage.
