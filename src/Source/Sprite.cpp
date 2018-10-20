#include "Sprite.h"
#include <cmath>
#include <ctime>

Sprite::Sprite(){}

Sprite::Sprite(int x, int y, int w, int h, Uint32 c, int winWidth, int winHeight){
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	surface = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
	SDL_FillRect(surface, NULL, color);

	W = winWidth;
	H = winHeight;

	color = c;
}

Sprite::~Sprite(){}

void Sprite::setPos(int x, int y){
	rect.x = x;
	rect.y = y;
}

void Sprite::draw(SDL_Surface *destination){
	SDL_BlitSurface(surface, NULL, destination, &rect);
}

int Sprite::getX() const{
	return rect.x;
}

int Sprite::getY() const{
	return rect.y;
}

int Sprite::getW() const{
	return rect.w;
}

int Sprite::getH() const{
	return rect.h;
}

bool Sprite::checkInWindow(int x, int y){
	if(x < 0 || y < 0 || x + rect.w > W || y + rect.h > H) return false;
	return true;
}

void Sprite::setColor(Uint32 c){
	color = c;
	SDL_FillRect(surface, NULL, c);
}

Uint32 Sprite::getColor(){
	return color;
}

void Sprite::setRandomColor(){
	srand(time(0));
	color = SDL_MapRGB(surface->format, rand() % 256, rand() % 256, rand() % 256);
	SDL_FillRect(surface, NULL, color);
}

void Sprite::setRandomPos(){
	srand(time(0));
	setPos(rand() % 10 * 40 + 10, rand() % 10 * 40 + 10);
}

