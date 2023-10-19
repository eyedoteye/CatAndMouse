#pragma once

#include "Renderable.h"
#include "Steppable.h"
#include "Map.h"

class Cheese : public ColorRect {
	public:
		Cheese(Map* m, int x, int y) : MapEntity(x, y), Renderable(x, y), ColorRect(x, y, 1, 1, Color(255, 255, 0)), map(m) {};
	private:
		Map* map;
};