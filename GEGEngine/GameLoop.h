#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"


namespace ggEngine
{
	class GameLoop
	{
	public:
		~GameLoop();
		GameLoop();
		void InitGame();
		void addPlayer(Player* p);
		void addEnemy(Enemy* e);
		void addComponent(Component* c);
		void addBullets(Bullet* b);
		void loopComponent();
		void run();

		void Update();

		void Draw();

		void InputHandler(SDL_Event &e);

		void move(int x, int y);
		void shoot(int x);
		
		void checkCollision(const Enemy &enemie);
		SDL_Rect getEnemyRect();

	private:
		bool runOn = true;
		int lap = 0;
		int fps = 60;
		const int tickInterval = 1000 / fps;
		Player* player;
		std::vector<Enemy*> enemies;
		std::vector<Component*> comp;
		std::vector<Bullet*> bullets;
	};
}
#endif

