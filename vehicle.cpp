#include "vehicle.h"



vehicle::vehicle()
{
	startPos.x=0;startPos.y=0;
	currentPos.x=0;currentPos.y=0;
	nextPos.x=0;nextPos.y=0;
	direction=vright;
	address[vleft]="lcar.bmp";
	address[vright]="rcar.bmp";
	address[vup]="ucar.bmp";
	address[vdown]="dcar.bmp";
}
vehicle::vehicle(int x, int y)
{
	startPos.x=0;startPos.y=0;
	currentPos.x=x;currentPos.y=y;
	nextPos.x=x;nextPos.y=y;
	direction=vright;
	address[vleft]="lcar.bmp";
	address[vright]="rcar.bmp";
	address[vup]="ucar.bmp";
	address[vdown]="dcar.bmp";
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
	nextPos.x=(nextPos.x)+50;
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