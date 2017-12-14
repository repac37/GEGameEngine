#ifndef CORE_H
#define CORE_H
#include <SDL.h>

namespace ggEngine
{

	class Core
	{
	public:
		Core();
		~Core();
		SDL_Renderer* get_ren() const;
		void setInitComplete(bool init) { initComplete = init; }
		int getInitComplete()const { return initComplete; }

	private:
		bool initComplete = true;
		SDL_Renderer *ren = nullptr;
		SDL_Window *win = nullptr;
	};

	extern Core core;
}
#endif //slut
