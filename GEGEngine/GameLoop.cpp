#include "GameLoop.h"
#include <iostream>
#include <string>

namespace ggEngine
{
	SDL_Event GameLoop::event;
	ManagementComponent GameLoop::mc;
	GTimer GameLoop::timer;


	void GameLoop::InputHandler()
	{
		while (SDL_PollEvent(&event))
		{
			const Uint8 *state = SDL_GetKeyboardState(NULL);

			if (state[SDL_SCANCODE_RIGHT] && state[SDL_SCANCODE_UP]) {
				mc.player->moveUp();
				mc.player->moveForward();
			}
			if (state[SDL_SCANCODE_RIGHT] && state[SDL_SCANCODE_DOWN]) {
				mc.player->moveDown();
				mc.player->moveForward();
			}
			if (state[SDL_SCANCODE_LEFT] && state[SDL_SCANCODE_UP]) {
				mc.player->moveUp();
				mc.player->moveBackward();
			}
			if (state[SDL_SCANCODE_LEFT] && state[SDL_SCANCODE_DOWN]) {
				mc.player->moveDown();
				mc.player->moveBackward();
			}
			if (state[SDL_SCANCODE_LEFT]) {
				mc.player->moveBackward();
			}
			if (state[SDL_SCANCODE_RIGHT]) {
				mc.player->moveForward();
			}
			if (state[SDL_SCANCODE_UP]) {
				mc.player->moveUp();
			}
			if (state[SDL_SCANCODE_DOWN]) {
				mc.player->moveDown();
			}
		
			if (state[SDL_SCANCODE_ESCAPE])
			{
				SDL_Quit();
			}

			switch (event.type)
			{
			case SDL_KEYDOWN:
				if (state[SDL_SCANCODE_SPACE])
				{
					mc.shoot();
				}
				if (state[SDL_SCANCODE_P]) {
					if (timer.isPaused())
					{
						timer.unpause();
						printf("START\n");
					}
					else {
						timer.pause();
						printf("PAUSE\n");
					}
				}
				break;
			case SDL_QUIT:
				SDL_Quit();
				break;
			}
		}
	}

	void GameLoop::move(int x, int y)
	{
		mc.player->moveSpeed(x, y);	
	}

	//SDL_Rect GameLoop::getEnemyRect()
	//{
	//	for (Enemy *e : enemies)
	//	{
	//		return e->getRect();
	//	}
	//}

	//void GameLoop::checkCollision(const Enemy &enemie)
	//{
	//	bool hit = false;
	//	//The sides of the rectangles
	//	int leftA, leftB;
	//	int rightA, rightB;
	//	int topA, topB;
	//	int bottomA, bottomB;

	//	//Calculate the sides of rect A
	//	leftA = player->getRect().x;
	//	rightA = player->getRect().x + player->getRect().w;
	//	topA = player->getRect().y;
	//	bottomA = player->getRect().y + player->getRect().h;

	//	//Calculate the sides of rect B
	//	leftB = enemie.getRect().x;
	//	rightB = enemie.getRect().x + enemie.getRect().w;
	//	topB = enemie.getRect().y;
	//	bottomB = enemie.getRect().y + enemie.getRect().h;

	//	//If any of the sides from A are outside of B
	//	if (bottomA <= topB || topA >= bottomB || rightA <= leftB || leftA >= rightB)
	//	{
	//		hit = false;

	//	}
	//	else {
	//		hit = true;

	//	}
	//	if (hit) {
	//		player->~Player();
	//	}
	//}

	void GameLoop::run()
	{
		bool quit = false;
		timer.start();

		while (!quit)
		{
			Uint32 next_tick = timer.getTicks()+ tickInterval;
			
			//delta
			Uint32 tick_time = next_tick;
			timer.setDeltaTime(static_cast<double>(tick_time - timer.lastTick)/1000);
			timer.setLastTick(tick_time);
			printf("delay: %f\n", timer.deltaTime);
			
			InputHandler();

			Update();

			Draw();

			int delay = next_tick - timer.getTicks();
			if (delay > 0) {
				SDL_Delay(delay);
			}	
		}
	}

	void GameLoop::Update()
	{
		for (Enemy *e : mc.enenmiesInGame)
		{
			if (typeid(*e) == typeid(Enemy))
				e->move();
				//checkCollision(*e);
		}
		for (Bullet *b : mc.bulletsInGame)
		{
			b->Move();
		}
	}

	void GameLoop::Draw()
	{
		SDL_SetRenderDrawColor(core.get_ren(), 0, 0, 200, 255);
		SDL_RenderClear(core.get_ren());
		for (Component *c : mc.GameObjects)
		{
			c->draw();
		}
		SDL_RenderPresent(core.get_ren());
	}

	GameLoop::GameLoop() {
		run();
	}

	GameLoop::~GameLoop() {
	
	}
}

