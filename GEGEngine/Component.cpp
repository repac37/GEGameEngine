#include "Component.h"

#include <SDL_image.h>

namespace ggEngine
{

	Component::Component(int x, int y, int w, int h) :rect { x, y, w, h }
	{
	}

	Component::~Component()
	{
		SDL_DestroyTexture(_texture);
	}

	void Component::draw()
	{
		SDL_RenderCopy(core.get_ren(), _texture, NULL, &getRect());
	}
}
