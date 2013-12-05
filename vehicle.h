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
	bool draw;
	bool erase;
	int index;
	
public:


	vehicle();
	vehicle(int x, int y);
	int getIndex();
	void setIndex(int ind);
	bool vdraw();
	void setDraw(bool d);
	bool verase();
	void setErase(bool e);
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
