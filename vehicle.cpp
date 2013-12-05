#include "vehicle.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



vehicle::vehicle()
{
	startPos.x=0;startPos.y=0;
	//currentPos.x=0;currentPos.y=300;
	//nextPos.x=400; nextPos.y=300;
	direction=vright;
	address[vleft]="lcar.bmp";
	address[vright]="rcar.bmp";
	address[vup]="ucar.bmp";
	address[vdown]="dcar.bmp";
	go=true;
	draw=false;
	erase=false;

	
	int random_number=0;


	random_number= rand() % 3 + 1;

	if (random_number==1)
	{
		address[vleft]="blackCarLeft.bmp";
		address[vright]="blackCarRight.bmp";
		address[vup]="blackCarUp.bmp";
		address[vdown]="blackCarDown.bmp";
	}
	else if (random_number==2)
	{
		address[vleft]="greenCarLeft.bmp";
		address[vright]="greenCarRight.bmp";
		address[vup]="greenCarUp.bmp";
		address[vdown]="greenCarDown.bmp";
	}
	else if (random_number==3)
	{
		address[vleft]="blueCarLeft.bmp";
		address[vright]="blueCarRight.bmp";
		address[vup]="blueCarUp.bmp";
		address[vdown]="blueCarDown.bmp";
	}

	

	random_number= rand() % 10 + 1;

	if (random_number == 1)
	{currentPos.x=0; nextPos.x=0;}
	else if (random_number==2)
	{currentPos.x=100; nextPos.x=100;}
	else if (random_number==3)
	{currentPos.x=200; nextPos.x=200;}
	else if (random_number==4)
	{currentPos.x=300; nextPos.x=300;}
	else if (random_number==5)
	{currentPos.x=400; nextPos.x=400;}
	else if (random_number==6)
	{currentPos.x=500; nextPos.x=500;}
	else if (random_number==7)
	{currentPos.x=600; nextPos.x=600;}
	else if (random_number==8)
	{currentPos.x=700; nextPos.x=700;}
	else if (random_number==9)
	{currentPos.x=800; nextPos.x=800;}
	else if (random_number==10)
	{currentPos.x=900; nextPos.x=900;}

	random_number=rand() % 10 + 1;

	if (random_number==1)
	{currentPos.y=0; nextPos.y=0; direction=vright;}
	else if (random_number==2)
	{currentPos.y=75; nextPos.y=75;direction=vleft;}
	else if (random_number==3)
	{currentPos.y=150; nextPos.y=150;direction=vright;}
	else if (random_number==4)
	{currentPos.y=225; nextPos.y=225;direction=vleft;}
	else if (random_number==5)
	{currentPos.y=300; nextPos.y=300;direction=vright;}
	else if (random_number==6)
	{currentPos.y=375; nextPos.y=375;direction=vleft;}
	else if (random_number==7)
	{currentPos.y=450; nextPos.y=450;direction=vright;}
	else if (random_number==8)
	{currentPos.y=525; nextPos.y=525;direction=vleft;}
	else if (random_number==9)
	{currentPos.y=600; nextPos.y=600;direction=vright;}
	else if (random_number==10)
	{currentPos.y=675; nextPos.y=675;direction=vleft;}




}

int vehicle::getIndex()
{
	return index;
}

void vehicle::setIndex(int ind)
{
	index=ind;
}

LPCSTR vehicle::getAddress()
{
	return address[direction];
}
location vehicle::getCurrPos()
{
	return currentPos;
}
location vehicle::getNextPos()
{
	return nextPos;
}
void vehicle::setCurrPos(location loc)
{
	currentPos=loc;
}
void vehicle::update()
{
	if (direction==vright)
	{nextPos.x=(nextPos.x)+CAR_SIZE;}
	else if (direction == vleft)
	{nextPos.x=(nextPos.x)-CAR_SIZE;}
	else if (direction == vup)
	{nextPos.y=(nextPos.y)-CAR_SIZE;}
	else if (direction == vdown)
	{nextPos.y=(nextPos.y)+CAR_SIZE;}
	
}
void vehicle::setNextPos(int x, int y)
{
	nextPos.x=x;
	nextPos.y=y;
}
dir vehicle::getDirection()
{
	return direction;
}
void vehicle::setDirection(dir direct)
{
	direction=direct;
}
bool vehicle::move()
{
	return go;
}
void vehicle::setMove(bool mv)
{
	go=mv;
}

bool vehicle::vdraw()
{
	return draw;
}

void vehicle::setDraw(bool d)
{
	draw=d;
}

bool vehicle::verase()
{
	return erase;
}

void vehicle::setErase(bool e)
{
	erase=e;
}