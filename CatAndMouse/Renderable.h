#pragma once

#include "SDL.h"
#include "MapEntity.h"

#define SCALE 32

class Renderable : public MapEntity
{
public:
	Renderable(int x, int y) : MapEntity(x, y) {};
	~Renderable(void) {};
	virtual void render(SDL_Renderer*) = 0;
};

class ColorRect : public Renderable {
public:
	struct Color {
		int r;
		int g;
		int b;
	};
	ColorRect(int x, int y, int width, int height, Color color);
	~ColorRect(void) {};
	void render(SDL_Renderer*);
private:
	int width, height;
	
	Color color;
};