#include "timer.h"


TIMER::TIMER(lights* streetL, vehicle* veh, double progL)
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
streetLights=streetL;
vehicles=veh;

}


void TIMER::updateTime()
{
	time(&sysTime);
	runTime = sysTime-startTime;
}

bool TIMER::moveVehicle()
{
	vehicleTime=runTime-lastVehicleTime;
	

	if (vehicleTime<carSpeed)
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