#include <Arduino.h>
#include <GyverHub.h>
GyverHub hub;

void build(gh::Builder& b) {
    bool sw;
    if (b.Switch(&sw).click()) digitalWrite(LED_BUILTIN, !sw);
}

void setup() {
    WiFi.mode(WIFI_AP);
    WiFi.softAP("My Hub");

    hub.config(F("MyDevices"), F("LED"));
    hub.onBuild(build);
    hub.begin();

    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, 1);
}

void loop() {
    hub.tick();
}