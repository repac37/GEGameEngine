#include "Dot.h"
namespace ggEngine
{

	Dot::Dot()
	{
		//Initialize the offsets
		mPosX = 0;
		mPosY = 0;

		//Initialize the velocity
		mVelX = 0;
		mVelY = 0;
	}

	void Dot::handleEvent(SDL_Event & e)
	{
		if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
		{
			//Adjust the velocity
			switch (e.key.keysym.sym)
			{
			case SDLK_UP: mVelY -= DOT_VEL; break;
			case SDLK_DOWN: mVelY += DOT_VEL; break;
			case SDLK_LEFT: mVelX -= DOT_VEL; break;
			case SDLK_RIGHT: mVelX += DOT_VEL; break;
			}
		}
		else if (e.type == SDL_KEYUP && e.key.repeat == 0)
		{
			//Adjust the velocity
			switch (e.key.keysym.sym)
			{
			case SDLK_UP: mVelY += DOT_VEL; break;
			case SDLK_DOWN: mVelY -= DOT_VEL; break;
			case SDLK_LEFT: mVelX += DOT_VEL; break;
			case SDLK_RIGHT: mVelX -= DOT_VEL; break;
			}
		}
	}

	void Dot::move()
	{
		//Move the dot left or right
		mPosX += mVelX;

		//If the dot went too far to the left or right
		if ((mPosX < 0) || (mPosX + DOT_WIDTH > 800))
		{
			//Move back
			mPosX -= mVelX;
		}
		mPosY += mVelY;

		//If the dot went too far up or down
		if ((mPosY < 0) || (mPosY + DOT_HEIGHT > 600))
		{
			//Move back
			mPosY -= mVelY;
		}
	}


	void Dot::render()
	{
		//Show the dot
		gDotTexture.render(mPosX, mPosY);
	}

	Dot::~Dot()
	{
	}
}
