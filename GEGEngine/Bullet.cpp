#include "Bullet.h"


namespace ggEngine
{
	Bullet::Bullet(int x, int y, int w, int h, std::string path) : MovableGameObject(x, y, w, h)
	{
		_texture = Sprite(path).get_texture();
	}


	Bullet::~Bullet()
	{
	}

	void Bullet::setRect(int x)
	{
		for (int i = 0; i < 25; i++)
		{
			this->rect.x += x;
		}
	}
}