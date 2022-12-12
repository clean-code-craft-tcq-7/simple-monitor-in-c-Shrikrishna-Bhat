#include <stdio.h>
#include <assert.h>

int IsTemperatureOK(float temperature)
{
  if(((temperature) < 0) || ((temperature) > 45))
    printf("Temperature out of range!\n");
}

int IsSocOK(float soc)
{
  if(((soc) < 20) || ((soc) > 80))
    printf("State of Charge out of range!\n");
}

int IsChargeRate(float chargeRate)
{
  if(chargeRate > 0.8)
    printf("Charge Rate out of range!\n");
}

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
  if(IsTemperatureOK(temperature) && IsSocOK(soc) && IsChargeRate(chargeRate)) 
  {
    return 0;  
  }
  return 1;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
