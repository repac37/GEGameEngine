#ifndef COMPONENT_H
#define COMPONENT_H

#include <SDL.h>
#include "Core.h"
#include "SpriteManager.h"

namespace ggEngine
{

	class Component
	{
	public:

		virtual ~Component();
		virtual void setRect(int x, int y) {}

		void draw();
		const SDL_Rect& getRect() const { return rect; };
		void setTex() { _texture = nullptr; };

	protected:

		Component(int x, int y, int w, int h);
		SDL_Rect rect;
		SDL_Texture *_texture = nullptr;



	private:
		
		Component(const Component&) = delete;
		const Component& operator=(const Component&) = delete;

	};
}
#endif //slut