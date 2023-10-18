#pragma once

struct Position {
	int x, y;
	Position(int x, int y) : x(x), y(y) {};
	Position(): x(-1), y(-1) {};
	bool operator==(const Position& p) {
		return x == p.x && y == p.y;
	}
	bool operator<(const Position& other) const {
		return (x < other.x) || (x == other.x && y < other.y);
	}
};

class MapEntity {
public:
	MapEntity(int x, int y);
	Position getPos();
	bool setPos(int x, int y);
	bool setPos(Position p);
	virtual void update(float deltaT) {
		return;
	}
private:
	int x, y;
};