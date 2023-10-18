#pragma once

#include "MapEntity.h"
#include "Map.h"
#include <list>

class Navigator : public virtual MapEntity {
public:
	Navigator(Map* m, int x, int y) : MapEntity(x, y), map(m) {
		target = NULL;
	};
	void setTarget(MapEntity* target) {
		Navigator::target = target;
	};
	void computePath();
	void recomputePathEnd();

private:
	MapEntity* target;
	std::list<Position> path;
	Map* map;
	struct NavCell {
		NavCell* parent;
		Position p;
		int g;
		int h;
		NavCell(Position p) : p(p) {
			parent = NULL;
			h = 0;
			g = -1;
		};
		bool operator<(const NavCell& other) const {
			return g + h < other.g + other.h;
		}
	};
	int computeG(NavCell n);
};