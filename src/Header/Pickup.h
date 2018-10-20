#pragma once
#include "Entity.h"

class Pickup : public Entity{
private:
	

public:
	static int numOfPickups;
	bool isPickedUp(Entity *player);
	Pickup(int x, int y, int w, int h, Uint32 c, int winWidth, int winHeight);
};
