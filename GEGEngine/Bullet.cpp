#include "Bullet.h"
#include "GameLoop.h"

namespace ggEngine
{
	Bullet::Bullet(int x, int y, int w, int h, std::string path) : MovableGameObject(x, y, w, h)
	{
		_texture = Sprite(path).get_texture();
	}


	Bullet::~Bullet()
	{
	}

	void Bullet::FireBullet(int x, int y)
	{
		this->rect.x = x;
		this->rect.y = y;
	}

	void Bullet::Move()
	{
		velocityX += (int)BULLET_VET*GameLoop::timer.deltaTime;

		rect.x += velocityX;

		velocityX = 0;
	}
}