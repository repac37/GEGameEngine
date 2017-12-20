#ifndef BULLET_H
#define BULLET_H

#include "MovableGameObject.h"
#include <string>

namespace ggEngine
{
	class Bullet : public MovableGameObject
	{
	public:

		Bullet(int x, int y, int w, int h, std::string path);
		~Bullet();
		void FireBullet(int x, int y);
		void Move();

	private:

		int mVelX;
		const int BULLET_VET = 1000;

	};
}
#endif

