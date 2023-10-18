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
	bool generateStep(void);
	MapEntity* get(int x, int y);
	MapEntity* get(Position p);
	bool add(MapEntity* mapEntity);
	void erase(int x, int y);
	void erase(Position p);
	std::list<MapEntity*> getAll();
	bool isInBounds(int x, int y);
	bool isInBounds(Position p);
	std::list<Position> getEndPoints();
private:
	std::map<Position, MapEntity*> entities;
	std::map<Position, bool> visited;
	std::stack<Position> cellStack;
	std::list<Position> endPoints;
};