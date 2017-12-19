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

	void ManagementComponent::addEnemyToGame()
	{
		GameObjects.push_back(player);
		enenmiesInGame.push_back(initEnemies.at(2));
		enenmiesInGame.push_back(initEnemies[3]);
		GameObjects.push_back(initEnemies.at(2));
		GameObjects.push_back(initEnemies[3]);
	}

	ManagementComponent::ManagementComponent()
	{
		initEnemy();
		player = new Player(100, 100, 120, 120, "assets/spacePlane.png");
		addEnemyToGame();
	}


	ManagementComponent::~ManagementComponent()
	{
		delete player;
	}

}
