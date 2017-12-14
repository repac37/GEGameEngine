#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <SDL.h>
#include "Core.h"
#include <cstdio>
namespace ggEngine
{
	class Geometry
	{
		//Maximum axis velocity of the dot
		static const int GEO_VEL = 10;

		int witdh, height, mPosX, mPosY;
		SDL_Rect geo;
		
		//The velocity of the dot
		int mVelX, mVelY;
		inline void move();
	
	public:
		Geometry();
		Geometry(int x, int y, int w, int h);
		void draw();
		~Geometry();
		void moveVel(int x, int y);
	};
}

#endif
