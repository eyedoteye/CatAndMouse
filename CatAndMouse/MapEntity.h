#pragma once

struct Position {
	int x, y;
};

class MapEntity {
public:
	MapEntity(int x, int y);
	Position getPos();
	bool setPos(int x, int y);
private:
	int x, y;
};