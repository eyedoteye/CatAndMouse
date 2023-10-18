#pragma once

#include "MapEntity.h"
#include "Wall.h"
#include <list>
#include <map>
#include <stack>
#include <vector>

#define MAZE_WIDTH 15
#define MAZE_HEIGHT 15

class Map {
public:
	void generateInit(void);
	void generateStep(void);
	MapEntity* get(int x, int y);
	bool add(MapEntity* mapEntity);
	void erase(int x, int y);
	std::list<MapEntity*> getAll();
private:
	std::map<Position, MapEntity*> entities;
	std::map<Position, bool> visited;
	std::stack<Position> cellStack;
	bool isInBounds(int x, int y);
	bool isInBounds(Position p);
	bool erasePositionFromOpenCells(Position p);
};