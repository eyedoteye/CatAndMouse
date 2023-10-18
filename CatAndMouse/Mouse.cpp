#include "Mouse.h"

void Mouse::step() {
	Position p = getPos();

	Position neighbors[4];
	int neighborsSize = 0;

	Position neighbor = Position(p.x - 1, p.y); // Left
	if (map->isInBounds(neighbor) && map->get(neighbor) == NULL) {
		neighbors[neighborsSize++] = neighbor;
	}

	neighbor = Position(p.x + 1, p.y); // Right
	if (map->isInBounds(neighbor) && map->get(neighbor) == NULL) {
		neighbors[neighborsSize++] = neighbor;
	}

	neighbor = Position(p.x, p.y - 1); // Up
	if (map->isInBounds(neighbor) && map->get(neighbor) == NULL) {
		neighbors[neighborsSize++] = neighbor;
	}

	neighbor = Position(p.x, p.y + 1); // Down
	if (map->isInBounds(neighbor) && map->get(neighbor) == NULL) {
		neighbors[neighborsSize++] = neighbor;
	}

	Position nextPos = p;

	if (neighborsSize != 0) {
		int randomNeighborIndex = rand() % neighborsSize;
		nextPos = neighbors[randomNeighborIndex];
	}

	map->erase(p);
	setPos(nextPos);
	map->add(this);
}