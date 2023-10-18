#include "Navigator.h"
#include <cmath>
#include <set>

void Navigator::computePath() {
	std::set<NavCell> openList;
	NavCell startNavCell(getPos());
	
	startNavCell.g = computeG(startNavCell);
	
	openList.insert(startNavCell);

	while (!openList.empty()) {

	}
}

void Navigator::recomputePathEnd() {
	// To Do
}

int Navigator::computeG(NavCell n) {
	Position targetPos = target->getPos();
	return abs(targetPos.x - n.p.x) + abs(targetPos.y - n.p.y);
}