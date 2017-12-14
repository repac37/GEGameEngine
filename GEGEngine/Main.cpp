#include "Core.h"
#include "GameLoop.h"
#include "Player.h"
#include "Enemy.h"
#include <SDL.h>


using namespace ggEngine;

int main(int argc, char** argv)
{
	if (core.getInitComplete());
	{
		GameLoop loop;
		Player *p = new Player(100, 100, 120, 120, "assets/spacePlane.png");
		Enemy *e = new Enemy(800, 200, 120, 120, "assets/ufo.png");
		Enemy *e2 = new Enemy(400, 200, 120, 120, "assets/ufo.png");
		//Bullet *b = new Bullet(160, 140, 40, 80, "assets/bullet.png");
		loop.addComponent(p);
		loop.addComponent(e);
		loop.addComponent(e2);
		//loop.addComponent(b);
		loop.addPlayer(p);
		loop.addEnemy(e);
		loop.addEnemy(e2);
		//loop.addBullets(b);
		loop.run();
	}

	return 0;
}