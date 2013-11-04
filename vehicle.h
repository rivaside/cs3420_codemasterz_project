#ifndef VEHICLE_H
#define	VEHICLE_H

#include "map.h"
#include <string>
#include <iostream>
using namespace std;



enum dir{vleft, vright, vup, vdown};

struct location
{
	int x;
	int y;
};

class vehicle
{
private:
	dir direction;
	location startPos;
	location currentPos;
	location nextPos;
	LPCSTR address[4];
	bool end;
	
public:


	vehicle();
	vehicle(int x, int y);
	LPCSTR getAddress();
	dir getDirection();
	location getCurrPos();
	location getNextPos();
	void setCurrPos(location loc);
	void setNextPos(int x, int y);
	void update();



};

#endif // !VEHICLE_H
