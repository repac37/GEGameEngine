#include "Core.h"
#include <cstdio>

namespace ggEngine
{

	Core::Core()
	{

		if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
			printf("SDL_Init-fel: %c\n", SDL_GetError());
			setInitComplete(false);
			SDL_Quit();
		}
		win = SDL_CreateWindow("My Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, winSize.x, winSize.y, SDL_WINDOW_SHOWN);
		if (win == nullptr) {
			printf("SDL_Init-fel: %c\n", SDL_GetError());
			setInitComplete(false);
			SDL_Quit();
			
		}
		ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_PRESENTVSYNC);
		if (ren == nullptr) {
			printf("SDL_Init-fel: %c\n", SDL_GetError());
			setInitComplete(false);
			SDL_DestroyWindow(win);
			SDL_Quit();
		}
	}


	Core::~Core()
	{
		SDL_DestroyWindow(win);
		SDL_DestroyRenderer(ren);
		SDL_Quit();
	}

	SDL_Renderer* Core::get_ren() const
	{
		return ren;
	}

	Core core;
}