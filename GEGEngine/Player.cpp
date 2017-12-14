#include "Player.h"
#include <string>

namespace ggEngine
{
	Player::Player(int x, int y, int w, int h, std::string path) : MovableGameObject(x, y, w, h)
	{
		_texture = Sprite(path).get_texture();
	}


	Player::~Player()
	{
	}

	void Player::setRect(int x, int y)
	{
		this->rect.x += x;
		this->rect.y += y;
	}
}

