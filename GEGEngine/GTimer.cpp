#include "GTimer.h"

namespace ggEngine
{

	GTimer::GTimer()
	{
		mStartTicks = 0;
		mPausedTicks = 0;

		mPaused = false;
		mStarted = false;
	}

	void GTimer::start()
	{
		mStarted = true;

		mPaused = false;

		mStartTicks = SDL_GetTicks();
		mPausedTicks = 0;
	}

	void GTimer::stop()
	{
		mStarted = false;

		mPaused = false;

		mStartTicks = 0;
		mPausedTicks = 0;
	}

	void GTimer::pause()
	{
		if (mStarted && !mPaused)
		{
			mPaused = true;

			mPausedTicks = SDL_GetTicks() - mStartTicks;
			mStartTicks = 0;
		}
	}

	void GTimer::unpause()
	{
		if (mStarted && mPaused)
		{
			mPaused = false;

			mStartTicks = SDL_GetTicks() - mPausedTicks;

			mPausedTicks = 0;
		}
	}

	Uint32 GTimer::getTicks()
	{
		Uint32 time = 0;

		if (mStarted)
		{
			if (mPaused)
			{
				time = mPausedTicks;
			}
			else
			{
				time = SDL_GetTicks() - mStartTicks;
			}
		}

		return time;
	}

	bool GTimer::isStarted()
	{
		return mStarted;
	}

	bool GTimer::isPaused()
	{
		return mPaused && mStarted;
	}

}