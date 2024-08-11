#define BLYNK_TEMPLATE_ID "TMPL6y6aUe4CV"
#define BLYNK_TEMPLATE_NAME "test"
#define BLYNK_AUTH_TOKEN "JI0Twf_y6OMreZbRrOJyeuzuwIuVzxJN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <RBDdimmer.h>
#include "RTClib.h"
#include <Wire.h>

#define outputPin 14
#define zerocross 27

dimmerLamp dimmer(outputPin, zerocross);
int outVal = 0;

RTC_DS3231 rtc;

const char ssid[] = "Testing";
const char password[] = "qwertyuiop";

int const BUZZER = 4;

bool lampState = false;

unsigned long previousMillis = 0;
unsigned long interval = 1000;

void setup()
{
  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Blynk.config(BLYNK_AUTH_TOKEN);
  Blynk.connect();
  Serial.println("Connected to Blynk");
  dimmer.begin(NORMAL_MODE, ON);
  Serial.println("Normal Mode Dimmer");

  Wire.begin();
  Serial.println("I2C Init");

  Serial.print("Init RTC");
  while (!rtc.begin())
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nRTC Init");
  dimmer.setPower(0);
  pinMode(BUZZER, OUTPUT);

  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  Serial.println("RTC time set.");
  rtc.disable32K();

  digitalWrite(BUZZER, LOW);
  outVal = 50;
}

void checkAndAct(DateTime now, int targetHour, int targetMinute, int pin, bool state)
{
  if (now.hour() == targetHour && now.minute() == targetMinute)
  {
    delay(100);
    Serial.print("Pin : ");
    Serial.println(pin);
    Serial.print("State : ");
    Serial.println(state);
    digitalWrite(pin, state ? HIGH : LOW);
  }
}

void checkAndAct(DateTime now, int targetHour, int targetMinute, bool state)
{
  if (now.hour() == targetHour && now.minute() == targetMinute)
  {
    delay(100);
    Serial.print("State dimmer : ");
    Serial.println(state);
    lampState = state;
    dimmer.setState(state ? ON : OFF);
  }
}

void loop()
{
  DateTime now = rtc.now();
  Blynk.run();
  checkAndAct(now, 01, 15, true);
  checkAndAct(now, 01, 15, BUZZER, true);
  checkAndAct(now, 01, 16, BUZZER, false);
  checkAndAct(now, 01, 17, false);
  unsigned long currentMillis = millis();
  if ((WiFi.status() != WL_CONNECTED) && (currentMillis - previousMillis >= interval))
  {
    Serial.println("Reconnecting to WiFi...");
    WiFi.disconnect();
    WiFi.reconnect();
    Blynk.connect();
    previousMillis = currentMillis;
  }
}

BLYNK_WRITE(V0)
{
  outVal = map(param.asInt(), 0, 255, 0, 100);
  dimmer.setState(lampState ? ON : OFF);
  Serial.println(outVal);
  dimmer.setPower(outVal);
  dimmer.setState(lampState ? ON : OFF);
}
