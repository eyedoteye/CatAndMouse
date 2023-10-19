#include "Mouse.h"
#include "Cheese.h"

void Mouse::step() {
	Position p = getPos();

	Position adjacents[4];
	int adjacentsSize = 0;

	Position adjacent = Position(p.x - 1, p.y); // Left
	if (map->isInBounds(adjacent) && map->get(adjacent) == nullptr) {
		adjacents[adjacentsSize++] = adjacent;
	}

	adjacent = Position(p.x + 1, p.y); // Right
	if (map->isInBounds(adjacent) && map->get(adjacent) == nullptr) {
		adjacents[adjacentsSize++] = adjacent;
	}

	adjacent = Position(p.x, p.y - 1); // Up
	if (map->isInBounds(adjacent) && map->get(adjacent) == nullptr) {
		adjacents[adjacentsSize++] = adjacent;
	}

	adjacent = Position(p.x, p.y + 1); // Down
	if (map->isInBounds(adjacent) && map->get(adjacent) == nullptr) {
		adjacents[adjacentsSize++] = adjacent;
	}

	Position nextPos = p;

	if (adjacentsSize > 1) {
		do {
			int randomNeighborIndex = rand() % adjacentsSize;
			nextPos = adjacents[randomNeighborIndex];
		} while (nextPos == lastPosition);
	}
	else
	{
		nextPos = adjacents[0];
	}
	
	lastPosition = p;

	map->erase(p);
	setPos(nextPos);
	map->add(this);

}