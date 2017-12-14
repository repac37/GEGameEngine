#ifndef GTIMER_H
#define GTIMER_H
#include <SDL.h>

namespace ggEngine
{

	class GTimer
	{
	public:
		
		GTimer();

		void start();
		void stop();
		void pause();
		void unpause();

		Uint32 getTicks();

		bool isStarted();
		bool isPaused();

	private:

		Uint32 mStartTicks;
		Uint32 mPausedTicks;

		bool mPaused;
		bool mStarted;
	};
}

#endif

