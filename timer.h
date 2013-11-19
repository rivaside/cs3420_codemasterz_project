#ifndef TIMER_H
#define	TIMER_H
#include <time.h>
#include "drawengine.h"
#include "vehicle.h"
#include "lights.h"

class TIMER
{

private:


double startTime;
time_t sysTime;
double runTime;
double vehicleTime;
double lightTime;
double lastVehicleTime;
double lastLightTime;
double progLength;
lights* streetLights;
vehicle* vehicles;
double lightSpeed;
double carSpeed;

public:


TIMER(lights* streetL, vehicle* veh, double progLength);
bool moveVehicle();
bool changeLight();
void updateTime();
bool endprog();

};










#endif // !TIMER_H