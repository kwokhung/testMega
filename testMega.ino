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

const char apn[] = "mobile.lte.three.com.hk";
const char user[] = "";
const char pass[] = "";

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
        delay(10000);
        return;
    }

    if (modem.isNetworkConnected())
    {
        DBG("Network connected");
    }

    DBG("Connecting to", apn);
    if (!modem.gprsConnect(apn, user, pass))
    {
        delay(10000);
        return;
    }

    DBG("CCID:", modem.getSimCCID());

    DBG("IMEI:", modem.getIMEI());

    DBG("Operator:", modem.getOperator());

    DBG("Local IP:", modem.localIP());

    DBG("Signal quality:", modem.getSignalQuality());

    DBG("Battery lavel:", modem.getBattPercent());
}

void loop()
{
    while (true)
    {
        modem.maintain();
    }
}