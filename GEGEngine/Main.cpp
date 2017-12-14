#include "Core.h"
#include "GameLoop.h"
#include "Player.h"
#include "Enemy.h"
#include <SDL.h>


using namespace ggEngine;

int main(int argc, char** argv)
{
	GameLoop loop;
	if (core.getInitComplete());
	{
		loop.run();		
	}

	return 0;
}