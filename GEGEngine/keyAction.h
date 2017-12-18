#ifndef KEYACTION_H
#define KEYACTION_H
#include "Command.h"
#include "Player.h"

namespace ggEngine
{

	namespace ggEngine
	{
		class MoveForward : public Command {
		public:
			virtual void execute(Player & play) { play.moveForward(); }
		};

		class MoveBackward : public Command {
		public:
			virtual void execute(Player & play) { play.moveBackward(); }
		};

		class MoveUp : public Command {
		public:
			virtual void execute(Player & play) { play.moveUp(); }
		};


		class MoveDown : public Command {
		public:
			virtual void execute(Player & play) { play.moveDown(); }
		};

	}

#endif // !KEYACTION_H
