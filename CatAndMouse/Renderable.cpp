#include "Renderable.h"

ColorRect::ColorRect(int x, int y, int width, int height, Color color) : Renderable(x,y) {
	ColorRect::width = width;
	ColorRect::height = height;
	ColorRect::color = color;
}

void ColorRect::render(SDL_Renderer* renderer) {
	SDL_Rect rect;
	Position p = getPos();
	rect.x = p.x * SCALE;
	rect.y = p.y * SCALE;
	rect.w = width * SCALE;
	rect.h = height * SCALE;

	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
	SDL_RenderFillRect(renderer, &rect);
}