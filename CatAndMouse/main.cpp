#include "SDL.h"
#include "Renderable.h"
#include <stdio.h>
#include <vector>

#define MAZE_WIDTH 16
#define MAZE_HEIGHT 16
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

	if (!initSDL()) {
		exit(1);
	}

	std::vector<Renderable*> renderableEntities;
	renderableEntities.reserve(10);

	ColorRect c1(
		0, 0,
		1, 1,
		Color(0, 0, 255)
	);

	ColorRect c2(
		0, 1,
		1, 1,
		Color(255, 0, 255)
	);

	renderableEntities.push_back(&c1);
	renderableEntities.push_back(&c2);


	loadMedia();

	while (1) {
		doInput();
		SDL_SetRenderDrawColor(app.renderer, 0, 255, 0, 255);
		SDL_RenderClear(app.renderer);

		for (Renderable* r : renderableEntities) {
			r->render(app.renderer);
		}

		SDL_RenderPresent(app.renderer);

		SDL_Delay(16);
	}

	return 0;
}