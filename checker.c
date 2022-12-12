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
  int status = 0, TemperatureOK = 0, SocOK = 0, ChargeRate = 0;
  
  TemperatureOK = IsTemperatureOK(temperature);
  SocOK         = IsSocOK(soc);
  ChargeRate    = IsChargeRate(chargeRate);
  
  status = (TemperatureOK && SocOK && ChargeRate) ? 1 : 0 ;
  
  return status;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
