#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "GTimer.h"
#include "Geometry.h"
#include "InputHandler.h"


namespace ggEngine
{
	class GameLoop
	{
	public:
		~GameLoop();
		GameLoop();
		void initGame();
		void addEnemy(Enemy* e);
		void addComponent(Component* c);
		void addBullets(Bullet* b);
		void loopComponent();
		void run();

		void Update();

		void Draw();

		void InputHandler();

		void move(int x, int y);
		void shoot(int x);
		
		void checkCollision(const Enemy &enemie);
		SDL_Rect getEnemyRect();
		static SDL_Event event;

	private:
		bool runOn = true;
		int lap = 0;
		Player* player;
		GTimer timer;
		std::vector<Enemy*> enemies;
		std::vector<Component*> comp;
		std::vector<Bullet*> bullets;
	};
}
#endif

