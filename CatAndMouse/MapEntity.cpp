#include "MapEntity.h"

MapEntity::MapEntity(int x, int y) {
	MapEntity::x = x;
	MapEntity::y = y;
}

Position MapEntity::getPos() {
	
	Position p;
	p.x = x;
	p.y = y;

	return p;
}

bool MapEntity::setPos(int x, int y) {
	MapEntity::x = x;
	MapEntity::y = y;
	return true;
}

bool MapEntity::setPos(Position p) {
	return setPos(p.x, p.y);
}