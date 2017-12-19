#ifndef ENEMY_H
#define ENEMY_H


#include "MovableGameObject.h"

namespace ggEngine
{
	class Enemy : public MovableGameObject
	{
	public:

		Enemy(int x, int y, int w, int h, std::string path);
		~Enemy();
		void setRect(int x, int y);
		void move();

	private:
		static const int GEO_VEL = 100;

	};
}
#endif

