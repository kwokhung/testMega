#include <HardwareSerial.h>
#include "App.h"

App::App()
{
}

void App::setup()
{
    Serial.begin(SERIAL_RATE);
    Serial1.begin(SERIAL_1_RATE);
}
