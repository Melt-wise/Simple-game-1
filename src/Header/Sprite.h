#pragma once

#include <SDL.h>

class Sprite{
protected:
	SDL_Rect rect;
	SDL_Surface *surface;
	Uint32 color;

	int W, H;

public:
	Sprite();
	Sprite(int x, int y, int w, int h, Uint32 c, int winWidth, int winHeight);
	~Sprite();

	void setPos(int x, int y);
	void draw(SDL_Surface *destination);
	void setColor(Uint32 c);
	void setRandomColor();
	void setRandomPos();

	int getX() const;
	int getY() const;
	int getW() const;
	int getH() const;

	bool checkInWindow(int x, int y);

	Uint32 getColor();
};

