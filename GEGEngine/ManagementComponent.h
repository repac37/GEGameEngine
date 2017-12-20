#ifndef MANAGEMENTCOMPONENT_H
#define MANAGEMENTCOMPONENT_H
#include <cstdio>
#include <vector>
#include "Enemy.h"
#include "Player.h"
#include "Component.h"
#include "Bullet.h"

namespace ggEngine {

	class ManagementComponent
	{
	
		//Player firstPlayer;		
		void initEnemy();
		void addObjectsToGame();
		void initBullet();

		int bulletNumber = 0;

	public:
		Player* player;
		std::vector<Enemy*> initEnemies;
		std::vector<Bullet*> initBullets;
		std::vector<Enemy*> enenmiesInGame;
		std::vector<Bullet*> bulletsInGame;
		std::vector<Component*> GameObjects;
		ManagementComponent();
		~ManagementComponent();
		void shoot();

	};

}
#endif // !MANAGEMENTCOMPONENT_H


