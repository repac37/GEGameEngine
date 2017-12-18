#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "MovableGameObject.h"


namespace ggEngine
{
	class Player : public MovableGameObject
	{
	public:

		Player(int x, int y, int w, int h, std::string path);
		~Player();
		void setRect(int x, int y);
		std::string getName() const { return _name; }
		inline void move();
		void moveSpeed(int x, int y);
	
	private:
		//Maximum axis velocity of the dot
		static const int GEO_VEL = 10;
		std::string _name;
	};
}
#endif