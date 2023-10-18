#pragma once

#include "Renderable.h"

class Wall : public ColorRect {
public:
	Wall(int x, int y, Color color) : MapEntity(x,y), Renderable(x,y), ColorRect(x,y,1,1,color) {};
};