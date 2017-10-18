#define SerialMon Serial
HardwareSerial SerialAT = *new HardwareSerial(2);
#define TINY_GSM_DEBUG SerialMon

#define TINY_GSM_MODEM_A6
#include "TinyGsmClient.h"

//#define DUMP_AT_COMMANDS
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
    TinyGsmAutoBaud(SerialAT);
}

void loop()
{
    DBG("Initializing modem...");

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

    while (true)
    {
        modem.maintain();
    }
}