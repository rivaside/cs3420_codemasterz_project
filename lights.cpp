#include "lights.h"


lights::lights()
{
	address[0]="redGreen.bmp";
	address[1]="redYellow.bmp";
	address[2]="greenRed.bmp";
	address[3]="yellowRed.bmp";
	counter=0;
}

LPCSTR lights::getAddress()
{
	return address[counter];
}
void lights::setAddress(LPCSTR addr)
{

	//address=addr;
}

void lights::changeLight()
{
	if (counter<3)
	{
		counter++;
	}
	else
		counter=0;
}