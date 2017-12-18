#include "GameLoop.h"
#include <iostream>
#include <string>

namespace ggEngine
{
	SDL_Event GameLoop::event;

	void GameLoop::addEnemy(Enemy* e)
	{
		enemies.push_back(e);
	}

	void GameLoop::addComponent(Component* c)
	{
		comp.push_back(c);
		loopComponent();
	}
	void GameLoop::loopComponent() {
		printf("antal %d\n", comp.size());
	}
	void GameLoop::addBullets(Bullet* b)
	{
		for (int i = 0; i < 10; i++)
		{
			bullets.push_back(b);
		}
	}

	void GameLoop::InputHandler()
	{
		while (SDL_PollEvent(&event))
		{
			const Uint8 *state = SDL_GetKeyboardState(NULL);

			if (state[SDL_SCANCODE_RIGHT] && state[SDL_SCANCODE_UP]) {
				move(2, -2);
			}
			if (state[SDL_SCANCODE_RIGHT] && state[SDL_SCANCODE_DOWN]) {
				move(2, 2);
			}
			if (state[SDL_SCANCODE_LEFT] && state[SDL_SCANCODE_UP]) {
				move(-2, -2);
			}
			if (state[SDL_SCANCODE_LEFT] && state[SDL_SCANCODE_DOWN]) {
				move(-2, 2);
			}
			if (state[SDL_SCANCODE_LEFT]) {
				move(-2, 0);
			}
			if (state[SDL_SCANCODE_RIGHT]) {
				move(2, 0);
			}
			if (state[SDL_SCANCODE_UP]) {
				move(0, -2);
			}
			if (state[SDL_SCANCODE_DOWN]) {
				move(0, 2);
			}
			if (state[SDL_SCANCODE_SPACE])
			{
				shoot(1);
			}

			if (state[SDL_SCANCODE_ESCAPE])
			{
				SDL_Quit();
			}

			switch (event.type)
			{
			case SDL_KEYDOWN:
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
		player->moveSpeed(x, y);
		//geo->moveVel(x, y);
	
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

	void GameLoop::checkCollision(const Enemy &enemie)
	{
		bool hit = false;
		//The sides of the rectangles
		int leftA, leftB;
		int rightA, rightB;
		int topA, topB;
		int bottomA, bottomB;

		//Calculate the sides of rect A
		leftA = player->getRect().x;
		rightA = player->getRect().x + player->getRect().w;
		topA = player->getRect().y;
		bottomA = player->getRect().y + player->getRect().h;

		//Calculate the sides of rect B
		leftB = enemie.getRect().x;
		rightB = enemie.getRect().x + enemie.getRect().w;
		topB = enemie.getRect().y;
		bottomB = enemie.getRect().y + enemie.getRect().h;

		//If any of the sides from A are outside of B
		if (bottomA <= topB || topA >= bottomB || rightA <= leftB || leftA >= rightB)
		{
			hit = false;

		}
		else {
			hit = true;

		}
		if (hit) {
			player->~Player();
		}
	}

	void GameLoop::run()
	{
		bool quit = false;


		//Uint32 startTime = SDL_GetTicks();

		timer.start();

		while (!quit)
		{
			Uint32 nextTick = timer.getTicks();

			InputHandler();

			Update();

			Draw();

			int delay = nextTick - timer.getTicks();
			if (delay > 0) {
				SDL_Delay(delay);
			}
		//printf("time: %d\n", timer.getTicks());
		}
	}

	void GameLoop::Update()
	{
		for (Enemy *e : enemies)
		{
			e->setRect(1, 0);
			checkCollision(*e);
		}
	}

	void GameLoop::Draw()
	{
		SDL_SetRenderDrawColor(core.get_ren(), 0, 0, 200, 255);
		SDL_RenderClear(core.get_ren());
		for (Component *c : comp)
		{
			c->draw();
		}
		SDL_RenderPresent(core.get_ren());
	}

	void GameLoop::initGame()
	{
		player = new Player(100, 100, 120, 120, "assets/spacePlane.png");
		Enemy *e1 = new Enemy(400, 200, 120, 120, "assets/ufo.png");
		Enemy *e2 = new Enemy(800, 100, 120, 120, "assets/ufo.png");
		addComponent(player);
		addComponent(e1);
		addComponent(e2);
		addEnemy(e1);
		addEnemy(e2);
	}

	GameLoop::GameLoop() {
		initGame();
		run();
	}

	GameLoop::~GameLoop() {}
}

