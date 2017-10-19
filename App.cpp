#include <HardwareSerial.h>
#include "Gprs.h"
#include "Mqtt.h"
#include "App.h"

App::App()
    : gprs(new Gprs(APN)),
      mqtt(new Mqtt(*gprs, MQTT_URL))
{
}

void App::setup()
{
    Serial.begin(SERIAL_RATE);

    gprs->setup();
    mqtt->setup();
}

Mqtt *App::getMqtt()
{
    return mqtt;
}
