#include <stdio.h>
#include <assert.h>

#define BATTERY_TEMPERATURE(temperature) (((temperature) < 0) || ((temperature) > 45))
#define BATTERY_SOC(soc)                 (((soc) < 20) || ((soc) > 80))
#define BATTERY_CHARGERATE(chargeRate)   (chargeRate > 0.8)

static void IsTemperatureOK(float temperature)
{
  if(BATTERY_TEMPERATURE(temperature))
  {
    printf("Temperature out of range!\n");
  }
}

static void IsSocOK(float soc)
{
  if(BATTERY_SOC(soc))
  {
    printf("State of Charge out of range!\n");
  }
}

static void IsChargeRate(float chargeRate)
{
  if(BATTERY_CHARGERATE(chargeRate))
  {
    printf("Charge Rate out of range!\n");
  }
}

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
