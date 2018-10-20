#include "Entity.h"

Entity::Entity(){}

Entity::Entity(int x, int y, int w, int h, Uint32 c, int winWidth, int winHeight){
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	surface = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
	SDL_FillRect(surface, NULL, c);

	W = winWidth;
	H = winHeight;

	color = c;
}

Entity::~Entity(){}

void Entity::move(int x, int y){
	if(checkInWindow(rect.x + (x * rect.w), rect.y + (y * rect.h))){
		rect.x = rect.x + (x * rect.w);
		rect.y = rect.y + (y * rect.h);
	}
}
