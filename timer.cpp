#include "timer.h"


TIMER::TIMER(double progL, double vehS, double lightS)
{
	sysTime= GetTickCount();
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
	sysTime= GetTickCount();
	runTime = sysTime-startTime;
}

bool TIMER::moveVehicle()
{
	vehicleTime=(runTime-lastVehicleTime)/1000;
	

	if (vehicleTime<(carSpeed))
	{return false;}
	else
	{
		lastVehicleTime=runTime;
		return true;
	}
}

bool TIMER::changeLight()
{
	lightTime=(runTime-lastLightTime)/1000;

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
	if ((runTime/1000)<progLength)
	{return false;}
	else
	{return true;}
}