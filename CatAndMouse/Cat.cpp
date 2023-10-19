#include "Cat.h"

void Cat::step() {
	auto moveTowardsMouse = [this](Position p, int xDir, int yDir) {
		Position nextPos = Position(p.x + xDir, p.y + yDir);
		
		map->erase(p);
		setPos(nextPos);
		map->add(this);

		printf("Mouse in sight.\n");
		};

	Position catPos = getPos();
	Position mousePos = mouse->getPos();
	
	bool inSight = true;
	if (catPos.x == mousePos.x) {
		int dir = mousePos.y - catPos.y < 0 ? -1 : 1;
		for (int y = catPos.y + dir; y != mousePos.y; y += dir) {
			if (map->get(catPos.x, y) != nullptr) {
				inSight = false;
			}
		}
		if (inSight) {
			moveTowardsMouse(catPos, 0, dir);
			return;
		}
	} else if (catPos.y == mousePos.y) {
		int dir = mousePos.x - catPos.x < 0 ? -1 : 1;
		for (int x = catPos.x + dir; x != mousePos.x; x += dir) {
			if (map->get(x, catPos.y) != nullptr) {
				inSight = false;
			}
		}
		if (inSight) {
			moveTowardsMouse(catPos, dir, 0);
			return;
		}
	}

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