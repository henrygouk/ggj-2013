#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
	public:
		virtual ~GameObject() = 0;
		virtual void update() = 0;
		virtual void draw() = 0;
};

#endif
