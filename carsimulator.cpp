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

	srand (time(NULL));
	numCars=num_Cars;

	vehicles = new vehicle[num_Cars];

	lightSpeed = light_speed;
	carspeed=car_speed;
	progLength = prog_Length;

	for(int i=0; i <num_Cars ; i++ )
	{
		vehicles[i].setIndex(i);
	}
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
	

	if (veh.getNextPos().y<0)
	{
		veh.setNextPos(veh.getNextPos().x, 0);
		veh.setDirection(vright);
	}
	else if (veh.getNextPos().y>675)
	{
		veh.setNextPos(veh.getNextPos().x,675);
		veh.setDirection(vleft);
	}
	else if (veh.getNextPos().x<0)
	{
		veh.setNextPos(0, veh.getNextPos().y);
		veh.setDirection(vup);
	}
	else if (veh.getNextPos().x>900)
	{
		veh.setNextPos(900, veh.getNextPos().y);
		veh.setDirection(vdown);
		
	}
	else
	{
		

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
					veh.setDraw(false);
					//srand (time(NULL));

					random_number= rand() % 2 + 1;

					if (random_number == 1)
					{veh.setDirection(vdown);}
			
				}
		
			}
			//one way street up
			else if (veh.getNextPos().x==0|| veh.getNextPos().x==200 || veh.getNextPos().x==400
				|| veh.getNextPos().x==600 || veh.getNextPos().x==800 ||veh.getNextPos().x==1000)
			{
				if (streetLight.getAddress()=="redGreen.bmp" || streetLight.getAddress()=="redYellow.bmp")
				{
					veh.setMove(false);
				}
				else
				{
					veh.setMove(true);
					veh.setDraw(false);
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
					veh.setDraw(false);
					//srand (time(NULL));

					random_number= rand() % 2 + 1;

					if (random_number == 1)
					{veh.setDirection(vright);}			
				}
								
			}
			//one way street left
			else if (veh.getNextPos().y==75|| veh.getNextPos().y==225 || veh.getNextPos().y==375
				|| veh.getNextPos().y==525 || veh.getNextPos().y==675 ||veh.getNextPos().y==825)
			{
				if (streetLight.getAddress()=="greenRed.bmp" || streetLight.getAddress()=="yellowRed.bmp")
				{
					veh.setMove(false);
				}
				else
				{
					veh.setMove(true);
					veh.setDraw(false);
					//srand (time(NULL));

					random_number= rand() % 2 + 1;

					if (random_number == 1)
					{veh.setDirection(vleft);}			
				}
								
			}
		}
	}
}

void CARSIMULATOR::checkVehicle(vehicle &veh)
{
	int index;
	int random_number=0;
	random_number= rand() % 2 + 1;


	index=veh.getIndex();

	for (int i=0; i<numCars; i++)
	{
		if (i!=index&& vehicles[index].getNextPos().x==vehicles[i].getCurrPos().x
			&&vehicles[index].getNextPos().y== vehicles[i].getCurrPos().y && !vehicles[i].move())
		{
			vehicles[index].setMove(false);
		}
		
		else if (i!=index&& vehicles[index].getNextPos().x==vehicles[i].getNextPos().x 
			&& vehicles[index].getNextPos().y==vehicles[i].getNextPos().y 
			&& vehicles[index].move()==vehicles[i].move())
		{
			if (random_number== 1)
			{
				vehicles[index].setMove(false);
				vehicles[i].setMove(true);
				//vehicles[index].setNextPos(vehicles[i].getCurrPos().x, vehicles[i].getCurrPos().y);
									
			}
			else
			{
				vehicles[index].setMove(true);
				vehicles[i].setMove(false);
				//vehicles[index].setNextPos(vehicles[index].getCurrPos().x, vehicles[index].getCurrPos().y);
			}
		}
	}
}

void CARSIMULATOR::move(vehicle &veh)
{
	if (!veh.move())
	{
		veh.setMove(true);
		return;
	}


int cx,cy,nx,ny;

cx=veh.getCurrPos().x;
cy=veh.getCurrPos().y;

if (veh.verase())
{
erase(veh, cx,cy);
}
else
{veh.setErase(true);}

nx= veh.getNextPos().x;
ny= veh.getNextPos().y;

if (veh.vdraw())
{
	
	car->draw(veh.getAddress(), nx, ny);
}
else
{veh.setDraw(true);veh.setErase(false);}
veh.setCurrPos(veh.getNextPos());
veh.update();


veh.setMove(true);

}


void CARSIMULATOR::run(HWND hWnd)
{
	
	drawMap();	
	drawLights();

	TIMER timers(progLength, carspeed, lightSpeed);
		
	
	while (!timers.endprog())
	{
		if (timers.moveVehicle())
		{
			for (int i=0; i < numCars; i++)
				{
					
					move(vehicles[i]);
					checkVehicle(vehicles[i]);
					checkLights(vehicles[i]);						
					
				}
		}
		if (timers.changeLight())
		{
			streetLight.changeLight();
			drawLights();
		}

		timers.updateTime();
		
	}
	

}