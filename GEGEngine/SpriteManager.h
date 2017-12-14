#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H

#include <SDL_image.h>
#include "Core.h"
#include <string>

namespace ggEngine
{
	class Sprite
	{
	public:
		Sprite(std::string path);
		~Sprite();


		SDL_Texture* get_texture();

	private:
		SDL_Texture *texture = nullptr;


	};
}
#endif

