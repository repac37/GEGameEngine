#include "ManagementComponent.h"

namespace ggEngine {

	void ManagementComponent::initEnemy()
	{
		int y = 100;
		for (int i = 0; i < 10; ++i) {
			Enemy* p = new Enemy(400, y, 120, 120, "assets/ufo.png");
			initEnemies.push_back(p);
			y += 120;
		}
	}

	void ManagementComponent::initBullet()
	{
		for (int i = 0; i < 10; ++i) {
			Bullet* b = new Bullet(100, 100, 25, 25, "assets/bullet.png");
			initBullets.push_back(b);
		}
	}

	void ManagementComponent::addObjectsToGame()
	{
		GameObjects.push_back(player);
		enenmiesInGame.push_back(initEnemies.at(2));
		enenmiesInGame.push_back(initEnemies[3]);
		GameObjects.push_back(initEnemies.at(2));
		GameObjects.push_back(initEnemies[3]);
	}

	void ManagementComponent::shoot()
	{
		initBullets[bulletNumber]->FireBullet(player->getRect().x + 111, player->getRect().y + 55);
		GameObjects.push_back(initBullets[bulletNumber]);
		bulletsInGame.push_back(initBullets[bulletNumber]);
		if (bulletNumber > 9)
		{
			bulletNumber = 0;
			bulletsInGame.clear();
			for (Bullet *e : GameObjects)
			{
				if (typeid(*e) == typeid(Bullet))
				
			}
		}
		else {
			bulletNumber++;
		}
	}

	ManagementComponent::ManagementComponent()
	{
		initEnemy();
		initBullet();
		player = new Player(100, 100, 120, 120, "assets/spacePlane.png");
		addObjectsToGame();
	}


	ManagementComponent::~ManagementComponent()
	{
		delete player;
	}

}
