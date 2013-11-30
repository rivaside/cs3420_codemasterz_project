#ifndef VEHICLE_H
#define	VEHICLE_H

#include "drawengine.h"
#include <string>
#include <iostream>
using namespace std;



static enum dir{vleft, vright, vup, vdown};

const int CAR_SIZE= 25;

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
	bool go;
	
public:


	vehicle();
	vehicle(int x, int y);
	LPCSTR getAddress();
	dir getDirection();
	void setDirection(dir direct);
	location getCurrPos();
	location getNextPos();
	void setCurrPos(location loc);
	void setNextPos(int x, int y);
	void update();
	bool move();
	void setMove(bool mv);
	



};

#endif // !VEHICLE_H
