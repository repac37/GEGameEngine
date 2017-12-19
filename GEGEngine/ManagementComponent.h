#ifndef MANAGEMENTCOMPONENT_H
#define MANAGEMENTCOMPONENT_H
#include <cstdio>
#include <vector>
#include "Enemy.h"
#include "Player.h"
#include "Component.h"

namespace ggEngine {

	class ManagementComponent
	{
	
		//Player firstPlayer;		
		void initEnemy();
		void addEnemyToGame();
		

	public:
		Player* player;
		std::vector<Enemy*> initEnemies;
		std::vector<Enemy*> enenmiesInGame;
		std::vector<Component*> GameObjects;
		ManagementComponent();
		~ManagementComponent();
	};

}
#endif // !MANAGEMENTCOMPONENT_H


