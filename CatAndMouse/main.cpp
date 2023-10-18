#include "SDL.h"
#include "Renderable.h"
#include "Map.h"
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <list>
#include <time.h>

#define SCREEN_WIDTH SCALE * MAZE_WIDTH
#define SCREEN_HEIGHT SCALE * MAZE_HEIGHT

typedef struct {
	SDL_Renderer *renderer;
	SDL_Window *window;
} App;

App app;

bool initSDL(void) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Couldn't initalize SDL. SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	app.window = SDL_CreateWindow(
		"Cat & Mouse",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN);

	if (!app.window) {
		printf("Failed to open window: %s\n", SDL_GetError());
		return false;
	}

	app.renderer = SDL_CreateRenderer(app.window, -1, 0);

	if (!app.renderer) {
		printf("Failed to create renderer: %s\n", SDL_GetError());
		return false;
	}

	return true;
}

void loadMedia() {
	// load images
}

void doInput(void) {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			exit(0);
			break;
		default:
			break;
		}
	}
}

int main(int argc, char *argv[])
{
	srand(time(0));

	if (!initSDL()) {
		exit(1);
	}

	std::list<Renderable*> renderableEntities;

	Map map;
	map.generateInit();

	loadMedia();

	while (1) {
		doInput();

		SDL_SetRenderDrawColor(app.renderer, 0, 255, 0, 255);
		SDL_RenderClear(app.renderer);

		map.generateStep();
		std::list <MapEntity*> entities = map.getAll();
		renderableEntities.clear();
		for (MapEntity* m : entities) {
			Renderable* r = dynamic_cast<Renderable*>(m);
			if (r != NULL) {
				renderableEntities.push_back(r);
			}
		}

		for (Renderable* r : renderableEntities) {
			r->render(app.renderer);
		}

		SDL_RenderPresent(app.renderer);

		SDL_Delay(50);
	}

	return 0;
}