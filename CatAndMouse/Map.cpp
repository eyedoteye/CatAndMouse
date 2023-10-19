#include "Map.h"
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <stack>

#define SIZE MAZE_WIDTH * MAZE_HEIGHT
#define POS2SIZE(x, y) x + MAZE_WIDTH * y
#define SIZE2POS_X(s) s % MAZE_WIDTH
#define SIZE2POS_Y(s) s / MAZE_WIDTH

void Map::generateInit() {
	for (int x = 0; x < MAZE_WIDTH; x++) {
		for (int y = 0; y < MAZE_HEIGHT; y++) {
			add(new Wall(x, y, Color(0, 0, 0)));
		}
	}
	Position rP;
	rP.x = (rand() % MAZE_WIDTH/2) * 2;
	rP.y = (rand() % MAZE_HEIGHT/2) * 2;
	cellStack.push(rP);
}

bool Map::generateStep() {
	if (cellStack.empty()) {
		return false;
	}
	
	Position pT = cellStack.top();
	cellStack.pop();
	erase(pT.x, pT.y);

	MapEntity* entityAtTargetLocation = get(pT.x, pT.y);

	if (entityAtTargetLocation != NULL) {
		printf("Error: Entity already exists at location %i,%i during generation.\n", pT.x, pT.y);
	}


	Position neighbors[4];
	Position betweenNeighbors[4];
	int neighborsSize = 0;

	auto positionNotInVisited = [this](Position p) {
		return visited.find(p) == visited.end();
	};

	int adjacentCount = 0;
	Position neighbor;
	Position betweenNeighbor;

	neighbor = Position(pT.x - 2, pT.y); // Left
	betweenNeighbor = Position(pT.x - 1, pT.y);
	if (isInBounds(neighbor) && positionNotInVisited(neighbor)) {
		betweenNeighbors[neighborsSize] = betweenNeighbor;
		neighbors[neighborsSize++] = neighbor;
	}
	if (get(betweenNeighbor) == NULL) {
		adjacentCount++;
	}


	neighbor = Position(pT.x + 2, pT.y); // Right
	betweenNeighbor = Position(pT.x + 1, pT.y);
	if (isInBounds(neighbor) && positionNotInVisited(neighbor)) {
		betweenNeighbors[neighborsSize] = betweenNeighbor;
		neighbors[neighborsSize++] = neighbor;
	}
	if (get(betweenNeighbor) == NULL) {
		adjacentCount++;
	}

	neighbor = Position(pT.x, pT.y - 2); // Up
	betweenNeighbor = Position(pT.x, pT.y - 1);
	if (isInBounds(neighbor) && positionNotInVisited(neighbor)) {
		betweenNeighbors[neighborsSize] = betweenNeighbor;
		neighbors[neighborsSize++] = neighbor;
	}
	if (get(betweenNeighbor) == NULL) {
		adjacentCount++;
	}

	neighbor = Position(pT.x, pT.y + 2); // Down
	betweenNeighbor = Position(pT.x, pT.y + 1);
	if (isInBounds(neighbor) && positionNotInVisited(neighbor)) {
		betweenNeighbors[neighborsSize] = betweenNeighbor;
		neighbors[neighborsSize++] = neighbor;
	}
	if (get(betweenNeighbor) == NULL) {
		adjacentCount++;
	}


	if (neighborsSize != 0) {
		int randNeighborIndex = rand() % neighborsSize;
			
		cellStack.push(pT);
		visited[pT] = true;
		Position pBN = betweenNeighbors[randNeighborIndex];
		erase(pBN.x, pBN.y);
		//printf("pT(%i,%i) marked as visited.\n", pT.x, pT.y);
		pT = neighbors[randNeighborIndex];
		cellStack.push(pT);
	}
	else {
		visited[pT] = true;
		//printf("End reached at pT(%i,%i).\n", pT.x, pT.y);
		//printf("adjacentCount: %i\n", adjacentCount);
		if (adjacentCount == 1) {
			endPoints.push_back(pT);
			printf("True endpoint reached.\n");
		}
	}

	return true;
}

bool Map::add(MapEntity* mapEntity) {
	Position p = mapEntity->getPos();
	if (!isInBounds(p.x, p.y))
		return false;

	MapEntity* entityAtTargetPosition = get(p.x, p.y);
	if (entityAtTargetPosition != NULL) {
		return false;
	}

	entities[p] = mapEntity;
	return true;
}

void Map::erase(int x, int y) {
	entities.erase(Position(x, y));
}

void Map::erase(Position p) {
	erase(p.x, p.y);
}

MapEntity* Map::get(int x, int y) {
	return get(Position(x, y));
}

MapEntity* Map::get(Position p) {
	auto iter = entities.find(p);
	if (iter == entities.end()) {
		return nullptr;
	}

	return iter->second;
}

std::list<MapEntity*> Map::getAll() {
	std::list<MapEntity*> m;
	for (auto iter = entities.begin(); iter != entities.end(); iter++) {
		m.push_back(iter->second);
	}
	return m;
}

std::list<Position> Map::getEndPoints() {
	return endPoints;
}

bool Map::isInBounds(int x, int y) {
	if (x < 0 || x >= MAZE_WIDTH)
		return false;
	if (y < 0 || y >= MAZE_HEIGHT)
		return false;
	return true;
}

bool Map::isInBounds(Position p) {
	return isInBounds(p.x, p.y);
}