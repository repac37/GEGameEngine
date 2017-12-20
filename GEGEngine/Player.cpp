#include "Player.h"
#include <string>
#include "GameLoop.h"

namespace ggEngine
{
	Player::Player(int x, int y, int w, int h, std::string path) : MovableGameObject(x, y, w, h), _name("Player")
	{
		_texture = Sprite(path).get_texture();
	}


	Player::~Player()
	{
		puts("you died in Play");
	}

	void Player::setRect(int x, int y)
	{
		this->rect.x += x;
		this->rect.y += y;
	}

	void Player::moveSpeed(int x, int y)
	{
		if (x > 0) {
			this->velocityX += GEO_VEL;
		}
		if (x < 0) {
			this->velocityX -= GEO_VEL;
		}
		if (y > 0) {
			this->velocityY += GEO_VEL;
		}
		if (y < 0) {
			this->velocityY -= GEO_VEL;
		}
		move();
		this->velocityX = this->velocityY = 0;

	}

	void Player::moveForward()
	{
		this->velocityX += GEO_VEL*GameLoop::timer.deltaTime;
		move();
	}

	void Player::moveBackward()
	{
		this->velocityX -= GEO_VEL*GameLoop::timer.deltaTime;
		move();
	}

	void Player::moveUp()
	{
		this->velocityY -= GEO_VEL*GameLoop::timer.deltaTime;
		move();
	}

	void Player::moveDown()
	{
		this->velocityY += GEO_VEL*GameLoop::timer.deltaTime;
		move();
	}

	void Player::shoot()
	{
		printf("shoot");
	}

	void Player::move()
	{
		//Move the dot left or right
		rect.x += velocityX;

		//If the dot went too far to the left or right
		if ((rect.x < 0) || (rect.x + rect.w > core.getWinWidth()))
		{
			//Move back
			rect.x -= velocityX;
		}

		//Move the dot up or down
		rect.y += velocityY;

		//If the dot went too far up or down
		if ((rect.y < 0) || (rect.y + rect.h >  core.getWinHeight()))
		{
			//Move back
			rect.y -= velocityY;
		}
		
		velocityY = velocityX = 0;
	}
}

