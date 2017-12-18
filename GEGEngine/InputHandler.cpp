#include "InputHandler.h"
#include "GameLoop.h"
namespace ggEngine
{

	void InputHandler::inputHandler()
	{
		while (SDL_PollEvent(&GameLoop::event))
		{
			const Uint8 *state = SDL_GetKeyboardState(NULL);


			if (state[SDL_SCANCODE_LEFT]) {
				puts("player.moveLeft()");
			}
			if (state[SDL_SCANCODE_RIGHT]) {
				puts("player.moveRight()");
			}
			if (state[SDL_SCANCODE_UP]) {
				puts("player.moveRight()");
			}
			if (state[SDL_SCANCODE_DOWN]) {
				puts("player.moveRight()");
			}
			if (state[SDL_SCANCODE_ESCAPE])
			{
				SDL_Quit();
			}
		}
	}

	InputHandler::~InputHandler()
	{

		puts("Bye inputhandler");
	}

	InputHandler::InputHandler()
	{

	}
}
