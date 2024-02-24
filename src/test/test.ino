#include <Arduino.h>

#include <GyverHub.h>
GyverHub hub;

void build(gh::Builder& b) {
    if (b.Switch().click()) digitalWrite(LED_BUILTIN, !b.build.value);
}

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_AP);
    WiFi.softAP("My Device");

    hub.config(F("MyDevices"), F("ESP"));
    hub.onBuild(build);
    hub.begin();

    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, 1);
}

void loop() {
    hub.tick();
}
