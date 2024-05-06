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

## Setup Instructions

Connect the hardware components according to the wiring specified in the code. Install the necessary libraries mentioned above. Configure Blynk by creating a project with the provided template ID and authorization token. Update the Wi-Fi credentials in the code to match your network. Upload the sketch to your ESP32 board.
