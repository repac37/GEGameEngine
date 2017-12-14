#include "Geometry.h"


namespace ggEngine
{
	Geometry::Geometry()
	{
	}
	Geometry::Geometry(int x, int y, int w, int h) : mPosX(x), mPosY(y), witdh(w), height(h)
	{
		geo = { mPosX,mPosY,witdh,height };
		//Initialize the velocity
		mVelX = 0;
		mVelY = 0;
	}

	void Geometry::draw()
	{
		SDL_SetRenderDrawColor(core.get_ren(), 0xFF, 0x00, 0x00, 0xFF);
		SDL_RenderFillRect(core.get_ren(), &geo);
	}


	Geometry::~Geometry()
	{
	}

	void Geometry::moveVel(int x, int y)
	{
		if (x > 0) {
			mVelX += GEO_VEL;
		}
		if (x < 0) {
			mVelX -= GEO_VEL;
		}
		if (y > 0) {
			mVelY += GEO_VEL;
		}
		if (y < 0) {
			mVelY -= GEO_VEL;
		}
		move();
		mVelX = mVelY = 0;
		
	}
	
	void Geometry::move()
	{
		//Move the dot left or right
		geo.x += mVelX;

		//If the dot went too far to the left or right
		if ((geo.x < 0) || (geo.x + geo.w > core.getWinWidth()))
		{
			//Move back
			geo.x -= mVelX;
		}

		//Move the dot up or down
		geo.y += mVelY;

		//If the dot went too far up or down
		if ((geo.y < 0) || (geo.y + geo.h >  core.getWinHeight()))
		{
			//Move back
			geo.y -= mVelY;
		}
	}
}
