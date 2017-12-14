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
		int getWinWidth() { return winSize.x; }
		int getWinHeight() { return winSize.y; }

	private:
		bool initComplete = true;
		SDL_Renderer *ren = nullptr;
		SDL_Window *win = nullptr;
		SDL_Point winSize = { 1200,720 };
	};

	extern Core core;
}
#endif //slut
