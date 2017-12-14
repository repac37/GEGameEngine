#ifndef PLAYER_H
#define PLAYER_H

#include "MovableGameObject.h"

namespace ggEngine
{
	class Player : public MovableGameObject
	{
	public:

		Player(int x, int y, int w, int h, std::string path);
		~Player();
		void setRect(int x, int y);
		
	private:


	};
}
#endif