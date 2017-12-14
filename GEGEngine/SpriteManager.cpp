#include "SpriteManager.h"

#include <iostream>

namespace ggEngine
{
	Sprite::Sprite(std::string path)
	{
		SDL_Surface *surf = IMG_Load(path.c_str());
		texture = SDL_CreateTextureFromSurface(core.get_ren(), surf);
		SDL_FreeSurface(surf);
	}

	SDL_Texture* Sprite::get_texture()
	{
		return texture;
	}

	Sprite::~Sprite()
	{
		std::cout << "Destroyed SPRITE" << std::endl;
	}
}