#include <stdio.h>
#include <assert.h>

int IsTemperatureOK(float temperature)
{
  if(((temperature) < 0) || ((temperature) > 45))
  {
    printf("Temperature out of range!\n");
    return 0;
  }
}

int IsSocOK(float soc)
{
  if(((soc) < 20) || ((soc) > 80))
  {
    printf("State of Charge out of range!\n");
    return 0;
  }
}

int IsChargeRate(float chargeRate)
{
  if(chargeRate > 0.8)
  {
    printf("Charge Rate out of range!\n");
    return 0;
  }
}

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
  int status, status1, status2, status3;
  status = 1;
  
  status1 = IsTemperatureOK(temperature);
  status2 = IsSocOK(soc);
  status3 = IsChargeRate(chargeRate);
  
  status = (status1 && status2 && status3) ? status : status;
  
  return status;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
