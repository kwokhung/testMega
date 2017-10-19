#ifndef App_h
#define App_h

#define SERIAL_RATE 115200
#define SERIAL_1_RATE 28800

#define APN "mobile.lte.three.com.hk"

#include "Gprs.h"

class App
{
public:
  App();

  void setup();

private:
  Gprs *gprs;
};

#endif