#include <HardwareSerial.h>

#define SerialMon Serial
#define SerialAT Serial1
#define TINY_GSM_DEBUG SerialMon

#define TINY_GSM_MODEM_A6
#include "TinyGsmClient.h"

uint32_t rate = 0; // Set to 0 for Auto-Detect

void setup()
{
    SerialMon.begin(115200);
}

void loop()
{
    if (!rate)
    {
        rate = TinyGsmAutoBaud(SerialAT, 28800, 28800);

        Serial.println(rate);

        if (!rate)
        {
            SerialMon.println(F("***********************************************************"));
            SerialMon.println(F(" Module does not respond!"));
            SerialMon.println(F("   Check your Serial wiring"));
            SerialMon.println(F("   Check the module is correctly powered and turned on"));
            SerialMon.println(F("***********************************************************"));

            return;
        }
    }
    else
    {
        SerialAT.begin(rate);
    }

    SerialMon.println(F("***********************************************************"));
    SerialMon.println(F(" You can now send AT commands"));
    SerialMon.println(F(" Enter \"AT\" (without quotes), and you should see \"OK\""));
    SerialMon.println(F(" If it doesn't work, select \"Both NL & CR\" in Serial Monitor"));
    SerialMon.println(F("***********************************************************"));

    while (true)
    {
        if (SerialAT.available())
        {
            SerialMon.write(SerialAT.read());
        }

        if (SerialMon.available())
        {
            SerialAT.write(SerialMon.read());
        }

        delay(0);
    }
}
