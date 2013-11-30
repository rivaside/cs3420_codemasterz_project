#include "vehicle.h"



vehicle::vehicle()
{
	startPos.x=0;startPos.y=0;
	currentPos.x=0;currentPos.y=300;
	nextPos.x=400;nextPos.y=300;
	direction=vright;
	address[vleft]="lcar.bmp";
	address[vright]="rcar.bmp";
	address[vup]="ucar.bmp";
	address[vdown]="dcar.bmp";
	go=true;
}
/*vehicle::vehicle(int x, int y)
{
	startPos.x=0;startPos.y=0;
	currentPos.x=x;currentPos.y=y;
	nextPos.x=x;nextPos.y=y;
	direction=vright;
	address[vleft]="lcar.bmp";
	address[vright]="rcar.bmp";
	address[vup]="ucar.bmp";
	address[vdown]="dcar.bmp";
	go=true;
}
*/
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