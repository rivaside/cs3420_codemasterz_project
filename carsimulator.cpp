#include "carsimulator.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



/*CARSIMULATOR::CARSIMULATOR()
{
	
}
*/


CARSIMULATOR::CARSIMULATOR(HWND hWnd, int num_Cars, double light_speed, double car_speed, double prog_Length)
{
	window_handle=hWnd;
	
	car=new DRAWENGINE(hWnd);

	
	numCars=num_Cars;

	vehicles = new vehicle[num_Cars];

	lightSpeed = light_speed;
	carspeed=car_speed;
	progLength = prog_Length;
}

void CARSIMULATOR::erase(vehicle veh, int x, int y)
{
	if (veh.getDirection()==vleft || veh.getDirection()==vright)
	{car->draw("hroad.bmp", x, y);}
	else if(veh.getDirection()==vup || veh.getDirection()==vdown)
	{car->draw("vnroad.bmp", x, y);}
}
void CARSIMULATOR::drawMap()
{

	int xpos=0;
	int ypos=0;

	for (ypos=0; ypos<700; ypos=ypos+75)
	{
		for(xpos=0;xpos<1000;xpos=xpos+25)
		{
			car->draw("hroad.bmp",xpos, ypos);		
		}
	}

	ypos=0;
	xpos=100;
	for (xpos=0; xpos<1000; xpos=xpos+100)
	{
		for(ypos=0;ypos<700;ypos=ypos+25)
		{
			car->draw("vnroad.bmp",xpos, ypos);
		
		}
	}
	
}

void CARSIMULATOR::drawLights()
{
	int xpos=0, ypos=0;

	for (xpos=0;xpos<1000; xpos=xpos+100)
	{
		for(ypos=0;ypos<750;ypos=ypos+75)
		{
			car->draw(streetLight.getAddress(),xpos,ypos);
		}
	}
	
}
void CARSIMULATOR::checkLights(vehicle &veh)
{
	int random_number=0;

	if ((veh.getDirection()==vright || veh.getDirection()== vleft))
	{
		//one way street down
		if (veh.getNextPos().x==100|| veh.getNextPos().x==300 || veh.getNextPos().x==500 || veh.getNextPos().x==700
		|| veh.getNextPos().x==900)
		{
			if (streetLight.getAddress()=="redGreen.bmp" || streetLight.getAddress()=="redYellow.bmp")
			{
				veh.setMove(false);
			}
			else
			{
				veh.setMove(true);
				//srand (time(NULL));

				random_number= rand() % 2 + 1;

				if (random_number == 1)
				{veh.setDirection(vdown);}
			
			}
		
		}
		//one way street up
		if (veh.getNextPos().x==0|| veh.getNextPos().x==200 || veh.getNextPos().x==400
		    || veh.getNextPos().x==600 || veh.getNextPos().x==800 ||veh.getNextPos().x==1000)
		{
			if (streetLight.getAddress()=="redGreen.bmp" || streetLight.getAddress()=="redYellow.bmp")
			{
				veh.setMove(false);
			}
			else
			{
				veh.setMove(true);
				//srand (time(NULL));

				random_number= rand() % 2 + 1;

				if (random_number == 1)
				{veh.setDirection(vup);}
			
			}
		
		}
		
	}
	else// (veh.getDirection()==vup || veh.getDirection()==vdown)
	{
		//one way street right
		if (veh.getNextPos().y==0|| veh.getNextPos().y==150 || veh.getNextPos().y==300
		    || veh.getNextPos().y==450 || veh.getNextPos().y==600 ||veh.getNextPos().y==750)
		{
			if (streetLight.getAddress()=="greenRed.bmp" || streetLight.getAddress()=="yellowRed.bmp")
			{
				veh.setMove(false);
			}
			else
			{
				veh.setMove(true);
				//srand (time(NULL));

				random_number= rand() % 2 + 1;

				if (random_number == 1)
				{veh.setDirection(vright);}			
			}
								
		}
		//one way street left
		if (veh.getNextPos().y==75|| veh.getNextPos().y==225 || veh.getNextPos().y==375
		    || veh.getNextPos().y==525 || veh.getNextPos().y==675 ||veh.getNextPos().y==825)
		{
			if (streetLight.getAddress()=="greenRed.bmp" || streetLight.getAddress()=="yellowRed.bmp")
			{
				veh.setMove(false);
			}
			else
			{
				veh.setMove(true);
				//srand (time(NULL));

				random_number= rand() % 2 + 1;

				if (random_number == 1)
				{veh.setDirection(vleft);}			
			}
								
		}
	}
}

void CARSIMULATOR::move(vehicle &veh)
{
	if (!veh.move())
		return;
	


int x,y;

x=veh.getCurrPos().x;
y=veh.getCurrPos().y;

erase(veh, x,y);


x= veh.getNextPos().x;
y= veh.getNextPos().y;

car->draw(veh.getAddress(), x, y);

veh.setCurrPos(veh.getNextPos());
veh.update();

drawLights();


}


void CARSIMULATOR::run(HWND hWnd)
{
	
	drawMap();	
	int pos=0;

	TIMER timers(progLength, carspeed, lightSpeed);
		
	
	while (!timers.endprog())
	{
		if (timers.moveVehicle())
		{
			for (int i=0; i < numCars; i++)
				{
					
					move(vehicles[i]);
					checkLights(vehicles[i]);
					
					
				}
		}
		if (timers.changeLight())
		{
			streetLight.changeLight();
		}

		timers.updateTime();
		
	}
	

}