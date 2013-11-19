#ifndef CAR_SIMULATOR
#define CAR_SIMULATOR

#include"drawengine.h"
#include "vehicle.h"
#include <time.h>





class CARSIMULATOR
{
private:
	HWND window_handle;
	double lastTime;
	time_t timer;
	vehicle *vehicles;
	int numCars;
	lights streetLight;
	double lastLightTime;
	double lightSpeed;
	double carspeed;
	
public:
	CARSIMULATOR()
	{lastTime=0;}
	CARSIMULATOR(HWND hWnd, int numCars, double lightSpeed, double carspeed);
	void drawImage(HWND hWnd, LPCSTR location,int x, int y);//I no longer use this draw function. I used this to create the drawengine. I no longer use this. I use a drawengine object to draw images now.
	void run(HWND hWnd); //run program
	void move(vehicle &veh);
	void erase(int x, int y);
	void carTimer(vehicle &veh, vehicle &veh2);
	void drawLights();
	void checkLights(vehicle &veh);
	DRAWENGINE *car;
	void drawMap();
	~CARSIMULATOR()
	{
		delete car;
		delete[] vehicles;
	}
	
protected:

		
	
};

#endif