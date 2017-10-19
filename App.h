#ifndef App_h
#define App_h

#define SERIAL_RATE 115200
#define SERIAL_1_RATE 28800

#define APN "mobile.lte.three.com.hk"
#define MQTT_URL "mbltest01.mqtt.iot.gz.baidubce.com"

#include "Gprs.h"
#include "Mqtt.h"

class App
{
public:
  App();

  void setup();
  Mqtt *getMqtt();

private:
  Gprs *gprs;
  Mqtt *mqtt;
};

#endif