#include <HardwareSerial.h>

#define SerialMon Serial
#define SerialAT Serial1
#define TINY_GSM_DEBUG SerialMon

#define TINY_GSM_MODEM_A6
#include "TinyGsmClient.h"

#define DUMP_AT_COMMANDS
#ifdef DUMP_AT_COMMANDS
#include "StreamDebugger.h"
StreamDebugger debugger(SerialAT, SerialMon);
TinyGsm modem(debugger);
#else
TinyGsm modem(SerialAT);
#endif

void setup()
{
    SerialMon.begin(115200);
    //SerialAT.begin(115200);
    TinyGsmAutoBaud(SerialAT);

    DBG("Initializing modem...");

    if (!modem.restart())
    {
        delay(10000);
        return;
    }

    DBG("Modem:", modem.getModemInfo());

    DBG("Waiting for network...");

    if (!modem.waitForNetwork())
    {
        return;
    }

    if (modem.isNetworkConnected())
    {
        DBG("Network connected");
    }
}

void loop()
{
    while (true)
    {
        modem.maintain();
    }
}