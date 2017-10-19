#ifndef Mqtt_h
#define Mqtt_h

#include "Gprs.h"
#include <PubSubClient.h>

class Mqtt
{
public:
  Mqtt(Gprs &gprs, char *mqttUrl);

  void setup();
  void loop();
  void reconnect();

private:
  Gprs *gprs;
  PubSubClient *client;
  char *mqttUrl;
};

#endif