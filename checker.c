#include <stdio.h>
#include <assert.h>

int IsTemperatureOK(float temperature)
{
  (((temperature) < 0) || ((temperature) > 45)) ? 0 : 1;
}

int IsSocOK(float soc)
{
  (((soc) < 20) || ((soc) > 80)) ? 0 : 1;
}

int IsChargeRate(float chargeRate)
{
  (chargeRate > 0.8) ? (0):(1);
}

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
  int temperature_l;
  int soc_l;
  int chargeRate_l;
  
  temperature_l = IsTemperatureOK(temperature);
  soc_l = IsSocOK(soc);
  chargeRate_l = IsChargeRate(chargeRate);
  
  return (temperature_l && soc_l && chargeRate_l);
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
