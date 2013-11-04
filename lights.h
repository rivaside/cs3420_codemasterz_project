#ifndef LIGHTS_H
#define LIGHTS_H
#include <iostream>
using namespace std;
#include <string>
#include "drawengine.h"


enum 
{
	redGreen, redYellow, greenRed, yellowRed
};


class lights
{
private:
	int counter;
	LPCSTR address[4];
public:
	lights();
	LPCSTR getAddress();
	void setAddress(LPCSTR addr);
	void changeLight();

};





#endif // !LIGHTS_H
