#ifndef DOT_H
#define DOT_H
#include <SDL.h>

namespace ggEngine
{
	class Dot
	{
		int mPosX, mPosY;
		int mVelX, mVelY;

	public:
		static const int DOT_WIDTH = 20;
		static const int DOT_HEIGHT = 20;

		static const int DOT_VEL = 10;

		Dot();

		void handleEvent(SDL_Event& e);

		void move();

		void render();
		~Dot();
	};
}

#endif