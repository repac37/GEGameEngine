#ifndef MOVABLEGAMEOBJECT_H
#define MOVABLEGAMEOBJECT_H

#include "Component.h"
#include <string>

namespace ggEngine
{
	class MovableGameObject : public Component
	{
	public:

		~MovableGameObject();
		virtual void setPath(std::string path) {}
		virtual std::string getPath() { return 0; }

	protected:

		virtual void setRect(int x, int y){}
		MovableGameObject(int x, int y, int w, int h);

	};
}
#endif

