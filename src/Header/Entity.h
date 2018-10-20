#pragma once
#include "Sprite.h"
class Entity : public Sprite{
private:

public:
	Entity();
	Entity(int x, int y, int w, int h, Uint32 c, int winWidth, int winHeight);
	~Entity();

	void move(int x, int y);
};

