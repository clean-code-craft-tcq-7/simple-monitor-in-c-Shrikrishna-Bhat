#include <stdio.h>
#include <assert.h>

int IsTemperatureOK(float temperature)
{
  int returnValue = 1;
  if(((temperature) < 0) || ((temperature) > 45))
  {
    printf("Temperature out of range!\n");
    returnValue = 0;
  }
  return returnValue;
}

int IsSocOK(float soc)
{
  int returnValue = 1;
  if(((soc) < 20) || ((soc) > 80))
  {
    printf("State of Charge out of range!\n");
    returnValue = 0;
  }
  return returnValue;
}

int IsChargeRate(float chargeRate)
{
  int returnValue = 1;
  if(chargeRate > 0.8)
  {
    printf("Charge Rate out of range!\n");
    returnValue = 0;
  }
  return returnValue;
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
