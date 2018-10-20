#include "Pickup.h"
#include <iostream>

Pickup::Pickup(int x, int y, int w, int h, Uint32 c, int winWidth, int winHeight){
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	surface = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
	SDL_FillRect(surface, NULL, c);

	W = winWidth;
	H = winHeight;

	numOfPickups++;

	color = c;

}

bool Pickup::isPickedUp(Entity *player){
	if(player->getX() == rect.x - 10 && player->getY() == rect.y - 10){
		return true;
	}
	return false;
}
