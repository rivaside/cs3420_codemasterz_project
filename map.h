#ifndef MAP_H
#define MAP_H
#include "lights.h"
#include "drawengine.h"


struct pos
{
	string content;
	lights *light;
	bool streetlight;
};

class map
{
private:
	pos grid[1000][450];
	lights lightgrid[20];
	
public:
	map();
	

};









#endif // !MAP_H
