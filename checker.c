#include <stdio.h>
#include <assert.h>

#define BATTERY_TEMPERATURE(temperature) (((temperature) < 0) || ((temperature) > 45))
#define BATTERY_SOC(soc)                 (((soc) < 20) || ((soc) > 80))
#define BATTERY_CHARGERATE(chargeRate)   (chargeRate > 0.8)

static int IsTemperatureOK(float temperature)
{
  if(BATTERY_TEMPERATURE(temperature))
  {
    printf("Temperature out of range!\n");
  }
  return 0;
}

static int IsSocOK(float soc)
{
  if(BATTERY_SOC(soc))
  {
    printf("State of Charge out of range!\n");
  }
  return 0;
}

static int IsChargeRate(float chargeRate)
{
  if(BATTERY_CHARGERATE(chargeRate))
  {
    printf("Charge Rate out of range!\n");
  }
  return 0;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
  if(temperature < 0 || temperature > 45) {
    printf("Temperature out of range!\n");
    return 0;
  } else if(soc < 20 || soc > 80) {
    printf("State of Charge out of range!\n");
    return 0;
  } else if(chargeRate > 0.8) {
    printf("Charge Rate out of range!\n");
    return 0;
  }
  return 1;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
