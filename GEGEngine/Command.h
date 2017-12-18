#ifndef COMMAND_H
#define COMMAND_H
#include "Player.h"
namespace ggEngine {
	class Command
	{
	public:
		virtual void execute(Player & play) = 0;
		virtual ~Command();
	};
}
#endif