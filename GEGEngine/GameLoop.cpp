#include "GameLoop.h"
#include <iostream>

namespace ggEngine
{
	void GameLoop::addPlayer(Player* p)
	{
		player.push_back(p);
	}
	void GameLoop::addEnemy(Enemy* e)
	{
		enemies.push_back(e);
	}
	void GameLoop::addComponent(Component* c)
	{
		comp.push_back(c);
	}
	void GameLoop::addBullets(Bullet* b)
	{
		for (int i = 0; i < 10; i++)
		{
			bullets.push_back(b);
		}
	}

	void GameLoop::run()
	{
		bool quit = false;
		SDL_Event e;

		while (!quit)
		{
			Uint32 nextTick = SDL_GetTicks() + tickInterval;
			++lap;

			InputHandler(e);
			for (Enemy *e : enemies)
			{
				e->setRect(1, 0);
			}
			for (int i = 0; i < player.size(); i++)
			{
				checkCollision(player[i]->getRect());
			}
			SDL_SetRenderDrawColor(core.get_ren(), 0, 0, 200, 255);
			SDL_RenderClear(core.get_ren());
			for (Component *c : comp)
			{
				c->draw();
			}
			SDL_RenderPresent(core.get_ren());
			int delay = nextTick - SDL_GetTicks();
			if (delay > 0) {
				SDL_Delay(delay);

			}
			//printf("Antal varv %d\n", lap);

		}
		
	}

	void GameLoop::InputHandler(SDL_Event &e)
	{
		while (SDL_PollEvent(&e))
		{
			const Uint8 *state = SDL_GetKeyboardState(NULL);

			if (state[SDL_SCANCODE_RIGHT] && state[SDL_SCANCODE_UP]) {
				move(2,-2);	
			}
			else if (state[SDL_SCANCODE_RIGHT] && state[SDL_SCANCODE_DOWN]) {
				move(2, 2);		
			}
			else if (state[SDL_SCANCODE_LEFT] && state[SDL_SCANCODE_UP]) {
				move(-2, -2);	
			}
			else if (state[SDL_SCANCODE_LEFT] && state[SDL_SCANCODE_DOWN]) {
				move(-2, 2);	
			}
			else if (state[SDL_SCANCODE_LEFT]) {
				move(-2, 0);	
			}
			else if (state[SDL_SCANCODE_RIGHT]) {
				move(2, 0);	
			}
			else if (state[SDL_SCANCODE_UP]) {
				move(0, -2);	
			}
			else if (state[SDL_SCANCODE_DOWN]) {
				move(0, 2);	
			}
			else if (state[SDL_SCANCODE_SPACE])
			{
				shoot(1);
			}
			if (state[SDL_SCANCODE_ESCAPE])
			{
				SDL_Quit();
			}
			switch (e.type)
			{
			case SDL_QUIT:
				SDL_Quit();
			}
		}
	}

	void GameLoop::move(int x, int y)
	{
		for (Player* p : player)
		{
			p->setRect(x, y);
		}
	}

	void GameLoop::shoot(int x)
	{
		for (int i = 0; i < bullets.size(); i++)
		{
			std::cout << "Shots fired!" << std::endl;
		}
	}

	SDL_Rect GameLoop::getEnemyRect()
	{
		for (Enemy *e : enemies)
		{
			return e->getRect();
		}
	}

	void GameLoop:: checkCollision(SDL_Rect a)
	{
		bool hit = false;
		
		SDL_Rect b = getEnemyRect();

		//The sides of the rectangles
		int leftA, leftB;
		int rightA, rightB;
		int topA, topB;
		int bottomA, bottomB;
		

		//Calculate the sides of rect A
		leftA = a.x;
		rightA = a.x + a.w;
		topA = a.y;
		bottomA = a.y + a.h;

		//Calculate the sides of rect B
		leftB = b.x;
		rightB = b.x + b.w;
		topB = b.y;
		bottomB = b.y + b.h;
		

		//If any of the sides from A are outside of B
		if (bottomA <= topB || topA >= bottomB || rightA <= leftB || leftA >= rightB)
		{
			hit = false;

		}
		else {
			hit = true;
			
		}
		if (hit) {
			printf("träff");
			for (Player* p : player)
			{
				p->setTex();
			}
		}
	}

	GameLoop::~GameLoop()
	{
	}
}
