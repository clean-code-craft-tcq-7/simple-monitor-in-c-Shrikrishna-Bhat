#include <stdio.h>
#include <assert.h>

#include "checker.h"

int batteryIsOk(float temperature, float soc, float chargeRate) {
  int returnValue = 0;
  if(IsTemperatureOK(temperature)) {
    return returnValue;
  } else if(IsSocOK(soc)) {
    return returnValue;
  } else if(IsChargeRate(chargeRate)) {
    return returnValue;
  }
  return 1;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
