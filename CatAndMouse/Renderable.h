#pragma once

#include "SDL.h"
#include "MapEntity.h"

#define SCALE 32

struct Color {
	int r;
	int g;
	int b;
	Color(int r, int g, int b) {
		Color::r = r;
		Color::g = g;
		Color::b = b;
	}
};

class Renderable : public MapEntity
{
public:
	Renderable(int x, int y) : MapEntity(x, y) {};
	~Renderable(void) {};
	virtual void render(SDL_Renderer*) = 0;
};

class ColorRect : public Renderable {
public:
	ColorRect(int x, int y, int width, int height, Color color);
	~ColorRect(void) {};
	void render(SDL_Renderer*);
private:
	int width, height;
	
	Color color;
};