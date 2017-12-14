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
		void setRect(int x);
	};
}
#endif

