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
double sysTime;
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


TIMER(double progLength,double vehS, double lightS);
bool moveVehicle();
bool changeLight();
void updateTime();
bool endprog();

};










#endif // !TIMER_H
