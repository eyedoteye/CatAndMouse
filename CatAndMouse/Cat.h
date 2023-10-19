#pragma once

#include "Renderable.h"
#include "Steppable.h"
#include "Map.h"
#include "Mouse.h"

class Cat : public Steppable, public ColorRect {
public:
	Cat(Map* m, int x, int y, Mouse* mouse) : MapEntity(x, y), Renderable(x, y), ColorRect(x, y, 1, 1, Color(255, 0, 0)), map(m), mouse(mouse) {
		lastPosition = Position(x, y);
	};
	void step();
private:
	Map* map;
	Position lastPosition;
	Mouse* mouse;
};