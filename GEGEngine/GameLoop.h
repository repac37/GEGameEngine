#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "GTimer.h"
#include "Geometry.h"
#include "InputHandler.h"
#include "ManagementComponent.h"

namespace ggEngine
{
	class GameLoop
	{
	public:
		~GameLoop();
		GameLoop();
		void run();
		void Update();
		void Draw();
		void InputHandler();
		void move(int x, int y);	
		//void checkCollision(const Enemy &enemie);
		//SDL_Rect getEnemyRect();
		static SDL_Event event;
		static ManagementComponent mc;
		static GTimer timer;

	private:
		const int fps = 60;
		const int tickInterval = 1000 / fps;
		bool runOn = true;
		
		
	};
}
#endif

