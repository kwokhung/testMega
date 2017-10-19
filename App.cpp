#include <HardwareSerial.h>
#include "Gprs.h"
#include "App.h"

App::App()
    : gprs(new Gprs(APN))
{
}

void App::setup()
{
    Serial.begin(SERIAL_RATE);

    gprs->setup();
}
