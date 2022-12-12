#define BATTERY_TEMPERATURE(temperature) (((temperature) < 0) || ((temperature) > 45))
#define BATTERY_SOC(soc)                 (((soc) < 20) || ((soc) > 80))
#define BATTERY_CHARGERATE(chargeRate)   (chargeRate > 0.8)

int IsTemperatureOK(float temperature)
{
  if(BATTERY_TEMPERATURE(temperature))
    printf("Temperature out of range!\n");
}

int IsSocOK(float soc)
{
  if(BATTERY_SOC(soc))
    printf("State of Charge out of range!\n");
}

int IsChargeRate(float chargeRate)
{
  if(BATTERY_CHARGERATE(chargeRate))
    printf("Charge Rate out of range!\n");
}
