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
  int temperature;
  int soc;
  int chargeRate;
  
  temperature = IsTemperatureOK(temperature);
  soc = IsSocOK(soc);
  chargeRate = IsChargeRate(chargeRate);
  
  return (temperature && soc && chargeRate);
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
