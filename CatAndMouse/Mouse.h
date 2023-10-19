#pragma once

#include "Renderable.h"
#include "Steppable.h"
#include "Map.h"

class Mouse : public Steppable, public ColorRect {
public:
	Mouse(Map* m, int x, int y) : MapEntity(x, y), Renderable(x, y), ColorRect(x, y, 1, 1, Color(150, 75, 0)), map(m) {
		lastPosition = Position(x, y);
	};
	void step();
private:
	Map* map;
	Position lastPosition;
};