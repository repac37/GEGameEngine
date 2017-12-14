#include <SDL.h>

namespace ggEngine
{
	class ControlHandler
	{
	private:
		
		bool isPressed(SDL_Keycode)
		{
			return (keyState[0] == 0);
		}
		bool isReleased();

		SDL_Keycode keyState[];

	protected:

	public:

		void handleKeyboardEvent(SDL_Event)
		{
			
		}

	};
}