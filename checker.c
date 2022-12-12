#include <stdio.h>
#include <assert.h>

#include "checker.h"

int batteryIsOk(float temperature, float soc, float chargeRate) {
  if(IsTemperatureOK(temperature)) {
    return 0;
  } else if(IsSocOK(soc)) {
    return 0;
  } else if(IsChargeRate(chargeRate)) {
    return 0;
  }
  return 1;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
