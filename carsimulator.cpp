#include "carsimulator.h"
#include <conio.h>



/*CARSIMULATOR::CARSIMULATOR()
{
	
}
*/


CARSIMULATOR::CARSIMULATOR(HWND hWnd, int num_Cars, double light_speed, double car_speed)
{
	window_handle=hWnd;
	
	car=new DRAWENGINE(hWnd);

	lastTime=0;

	numCars=num_Cars;

	vehicles = new vehicle[num_Cars];

	lightSpeed = light_speed;
	lastLightTime=0;
	carspeed=car_speed;
}

void CARSIMULATOR::erase(int x, int y)
{
	car->draw("road.bmp", x, y);
}
void CARSIMULATOR::drawMap()
{

	int xpos=0;
	int ypos=0;

	for(xpos=0;xpos<1000;xpos=xpos+100)
	{
	car->draw("road.bmp",xpos, ypos);
		
	}
	ypos=50;
	for(xpos=0;xpos<1000;xpos=xpos+100)
	{
	car->draw("road.bmp",xpos, ypos);
		
	}
	ypos=100;for(xpos=0;xpos<1000;xpos=xpos+100)
	{
	car->draw("road.bmp",xpos, ypos);
		
	}
	ypos=150;
	for(xpos=0;xpos<1000;xpos=xpos+100)
	{
	car->draw("road.bmp",xpos, ypos);
		
	}
	ypos=200;
	for(xpos=0;xpos<1000;xpos=xpos+100)
	{
	car->draw("road.bmp",xpos, ypos);
		
	}
	ypos=250;
	for(xpos=0;xpos<1000;xpos=xpos+100)
	{
	car->draw("road.bmp",xpos, ypos);
		
	}
	ypos=300;
	for(xpos=0;xpos<1000;xpos=xpos+100)
	{
	car->draw("road.bmp",xpos, ypos);
		
	}
	ypos=350;
	for(xpos=0;xpos<1000;xpos=xpos+100)
	{
	car->draw("road.bmp",xpos, ypos);
		
	}
	ypos=400;
	for(xpos=0;xpos<1000;xpos=xpos+100)
	{
	car->draw("road.bmp",xpos, ypos);
		
	}
	ypos=450;
	for(xpos=0;xpos<1000;xpos=xpos+100)
	{
	car->draw("road.bmp",xpos, ypos);
		
	}
	ypos=0;
	xpos=0;

	for(ypos=0;ypos<1000;ypos=ypos+100)
	{
	car->draw("vroad.bmp",xpos, ypos);
		
	}

	ypos=0;
	xpos=100;
	for(ypos=0;ypos<1000;ypos=ypos+100)
	{
	car->draw("vroad.bmp",xpos, ypos);
		
	}
	xpos=200;
	for(ypos=0;ypos<1000;ypos=ypos+100)
	{
	car->draw("vroad.bmp",xpos, ypos);
		
	}
	xpos=300;
	for(ypos=0;ypos<1000;ypos=ypos+100)
	{
	car->draw("vroad.bmp",xpos, ypos);
		
	}
	xpos=400;
	for(ypos=0;ypos<1000;ypos=ypos+100)
	{
	car->draw("vroad.bmp",xpos, ypos);
		
	}
	xpos=500;
	for(ypos=0;ypos<1000;ypos=ypos+100)
	{
	car->draw("vroad.bmp",xpos, ypos);
		
	}
	xpos=600;
	for(ypos=0;ypos<1000;ypos=ypos+100)
	{
	car->draw("vroad.bmp",xpos, ypos);
		
	}
	xpos=700;
	for(ypos=0;ypos<1000;ypos=ypos+100)
	{
	car->draw("vroad.bmp",xpos, ypos);
		
	}
	xpos=800;
	for(ypos=0;ypos<1000;ypos=ypos+100)
	{
	car->draw("vroad.bmp",xpos, ypos);
		
	}
	xpos=900;
	for(ypos=0;ypos<1000;ypos=ypos+100)
	{
	car->draw("vroad.bmp",xpos, ypos);
		
	}
	/*
	xpos=0;
	ypos=0;
	
	for(ypos=0;ypos<500;ypos=ypos+50)
	{
	car->draw("vlight.bmp",xpos, ypos);
		
	}

	xpos=100;
	ypos=0;
	
	for(ypos=0;ypos<500;ypos=ypos+50)
	{
	car->draw("redgreen.bmp",xpos, ypos);
		
	}
	xpos=200;
	for(ypos=0;ypos<500;ypos=ypos+50)
	{
	car->draw("vlight.bmp",xpos, ypos);
		
	}
	xpos=300;
	for(ypos=0;ypos<500;ypos=ypos+50)
	{
	car->draw("vlight.bmp",xpos, ypos);
		
	}
	xpos=400;
	for(ypos=0;ypos<500;ypos=ypos+50)
	{
	car->draw("vlight.bmp",xpos, ypos);
		
	}
	xpos=500;
	for(ypos=0;ypos<500;ypos=ypos+50)
	{
	car->draw("vlight.bmp",xpos, ypos);
		
	}
	xpos=600;
	for(ypos=0;ypos<500;ypos=ypos+50)
	{
	car->draw("vlight.bmp",xpos, ypos);
		
	}
	xpos=700;
	for(ypos=0;ypos<500;ypos=ypos+50)
	{
	car->draw("vlight.bmp",xpos, ypos);
		
	}
	xpos=800;
	for(ypos=0;ypos<500;ypos=ypos+50)
	{
	car->draw("vlight.bmp",xpos, ypos);
		
	}
	xpos=900;
	for(ypos=0;ypos<500;ypos=ypos+50)
	{
	car->draw("vlight.bmp",xpos, ypos);
	}
	*/
}

void CARSIMULATOR::drawLights()
{
	int xpos=0, ypos=0;

	for(ypos=0;ypos<500;ypos=ypos+50)
	{
	car->draw(streetLight.getAddress(),xpos,ypos);
	}

	xpos=100;

	for(ypos=0;ypos<500;ypos=ypos+50)
	{
	car->draw(streetLight.getAddress(),xpos,ypos);
	}

	xpos=200;

	for(ypos=0;ypos<500;ypos=ypos+50)
	{
	car->draw(streetLight.getAddress(),xpos,ypos);
		
	}
	xpos=300;
	for(ypos=0;ypos<500;ypos=ypos+50)
	{
	car->draw(streetLight.getAddress(),xpos,ypos);
		
	}
	xpos=400;
	for(ypos=0;ypos<500;ypos=ypos+50)
	{
	car->draw(streetLight.getAddress(),xpos,ypos);
		
	}
	xpos=500;
	for(ypos=0;ypos<500;ypos=ypos+50)
	{
	car->draw(streetLight.getAddress(),xpos,ypos);
		
	}
	xpos=600;
	for(ypos=0;ypos<500;ypos=ypos+50)
	{
	car->draw(streetLight.getAddress(),xpos,ypos);
		
	}
	xpos=700;
	for(ypos=0;ypos<500;ypos=ypos+50)
	{
	car->draw(streetLight.getAddress(),xpos,ypos);
		
	}
	xpos=800;
	for(ypos=0;ypos<500;ypos=ypos+50)
	{
	car->draw(streetLight.getAddress(),xpos,ypos);
		
	}
	xpos=900;
	for(ypos=0;ypos<500;ypos=ypos+50)
	{
	car->draw(streetLight.getAddress(),xpos,ypos);
	}

	
}
void CARSIMULATOR::checkLights(vehicle &veh)
{
	if ((veh.getDirection()==vright || veh.getDirection()== vleft) && (veh.getNextPos().x==0 || veh.getNextPos().x==100
		|| veh.getNextPos().x==200 || veh.getNextPos().x==300 || veh.getNextPos().x==400
		|| veh.getNextPos().x==500 || veh.getNextPos().x==600 || veh.getNextPos().x==700
		|| veh.getNextPos().x==800 || veh.getNextPos().x==900 || veh.getNextPos().x==1000))
	{

	}
}

void CARSIMULATOR::move(vehicle &veh)
{
int x,y;

x=veh.getCurrPos().x;
y=veh.getCurrPos().y;

erase(x,y);


x= veh.getNextPos().x;
y= veh.getNextPos().y;

car->draw(veh.getAddress(), x, y);

veh.setCurrPos(veh.getNextPos());
veh.update();

drawLights();


}

void CARSIMULATOR::drawImage(HWND hWnd, LPCSTR location, int x, int y)
{
			HBITMAP hbitmap;
			BITMAP bitmap;
			PAINTSTRUCT paintStruct;
			HDC hdc= BeginPaint(hWnd, &paintStruct);
			HDC hdcMem= CreateCompatibleDC(hdc);
			int xpos=x;
			int ypos=y;

			hbitmap= (HBITMAP)LoadImage(NULL, location,IMAGE_BITMAP, 0,0, LR_LOADFROMFILE );

			if(hbitmap == NULL)
			 {
				MessageBox(NULL, "Bitmap not loaded- Ensure the file 'car.bmp' is present in the project folder","Error",MB_OK);
			 }
	 
			 SelectObject(hdcMem, hbitmap);

			 GetObject(hbitmap, sizeof(BITMAP), &bitmap);
	 
			 
			 BitBlt(hdc, xpos, ypos, bitmap.bmWidth,bitmap.bmHeight, hdcMem,0,0, SRCCOPY);
			 			
			 DeleteDC(hdcMem);
			 DeleteObject(hbitmap);
			 EndPaint(hWnd, &paintStruct);
	
			 
}

void CARSIMULATOR::carTimer(vehicle &veh,vehicle &veh2)
{
	time(&timer);
	double currentTime = timer-lastTime;

	if (currentTime<(carspeed/100))
		return;
	for (int i=0; i < numCars; i++)
	{
		move(vehicles[i]);
	}
	
	time(&timer);
	currentTime=timer-lastLightTime;
	if (currentTime>lightSpeed)
	{
		streetLight.changeLight();
	}
	


	time(&timer);
	lastTime=timer;
	lastLightTime=timer;
}


void CARSIMULATOR::run(HWND hWnd)
{
	
	drawMap();	
	vehicle veh1(0,100);
	vehicle veh2;
	
	vehicles[0].setNextPos(0,100);

	while (vehicles[0].getCurrPos().x<1000)
	{
		carTimer(veh1, veh2);
		
	}
	erase(veh1.getCurrPos().x,veh1.getCurrPos().y);
	

	//car->draw(veh1.getAddress(), veh1.getNextPos().x, veh1.getNextPos().y);

	//veh1.update();

	
	//car->draw("car.bmp", 0,0);
	//erase(0,0);
	//car->draw("car.bmp",20,0);

		
}