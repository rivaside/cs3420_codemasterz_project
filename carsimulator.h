#ifndef CAR_SIMULATOR
#define CAR_SIMULATOR

#include"drawengine.h"
#include "vehicle.h"
#include <time.h>
#include "timer.h"





class CARSIMULATOR
{
private:

	HWND window_handle;
	vehicle *vehicles;
	int numCars;
	lights streetLight;
	double lightSpeed;
	double carspeed;
	double progLength;
	

public:
	CARSIMULATOR()
	{}
	CARSIMULATOR(HWND hWnd, int numCars, double lightSpeed, double carspeed, double progL);
	void run(HWND hWnd); //run program
	void move(vehicle &veh);
	void erase(vehicle veh,int x, int y);
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