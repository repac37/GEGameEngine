#include "Enemy.h"
#include <string>
#include <math.h>

namespace ggEngine
{
	Enemy::Enemy(int x, int y, int w, int h, std::string path) : MovableGameObject(x, y, w, h)
	{
		_texture = Sprite(path).get_texture();
	}


	Enemy::~Enemy()
	{
	}

	void Enemy::setRect(int x, int y)
	{
		//double d = sin(++y / 3.14 / 180);
		this->rect.x -= x;
		this->rect.y += y;
	}
}
