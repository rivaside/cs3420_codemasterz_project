#include "timer.h"


TIMER::TIMER(double progL, double vehS, double lightS)
{
time(&sysTime);
startTime=sysTime;

sysTime=0;
runTime=0;
vehicleTime=0;
lightTime=0;
lastVehicleTime=0;
lastLightTime=0;
progLength=progL;
carSpeed=vehS;
lightSpeed=lightS;

}


void TIMER::updateTime()
{
	time(&sysTime);
	runTime = sysTime-startTime;
}

bool TIMER::moveVehicle()
{
	vehicleTime=(runTime-lastVehicleTime)/100;
	

	if (vehicleTime<(carSpeed/100))
	{return false;}
	else
	{
		lastVehicleTime=runTime;
		return true;
	}
}

bool TIMER::changeLight()
{
	lightTime=runTime-lastLightTime;

	if (lightTime<lightSpeed)
	{return false;}
	else
	{
		lastLightTime=runTime;
		return true;
	}

}

bool TIMER::endprog()
{
	if (runTime<progLength)
	{return false;}
	else
	{return true;}
}