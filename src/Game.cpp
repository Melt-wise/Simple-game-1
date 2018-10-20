#include "SDL.h"
#include "Sprite.h"
#include "Entity.h"
#include "Pickup.h"

#include <iostream>
#include <math.h>
#include <ctime>
#include <vector>

int Pickup::numOfPickups = 0;

int main(int argc, char* args[])
{
	srand(time(0));
	bool gameRunning = true;

	//Start SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window *window = SDL_CreateWindow("Gam", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 400, SDL_WINDOW_RESIZABLE);

	SDL_Event event;
	SDL_Surface *surface = nullptr;

	

	std::vector<Pickup*> pickups;
	for(int i = 0; i < 5; i++){
		int x = rand() % 10 * 40 + 10;
		int y = rand() % 10 * 40 + 10;
		if(x == 0 && y == 0) continue;
		for(int i = 0; i < pickups.size(); i++){
			if(x == pickups[i]->getX() - 10 && x == pickups[i]->getY() - 10) continue;
		}
		pickups.push_back(new Pickup(x, y, 20, 20, SDL_MapRGB(SDL_GetWindowSurface(window)->format, rand() % 256, rand() % 256, rand() % 256), 400, 400));
		std::cout << x - 10 << " " << y - 10 << "\n";
	}

	Entity *player = new Entity(0, 0, 40, 40, SDL_MapRGB(SDL_GetWindowSurface(window)->format, 255, 255, 255), 400, 400);

	while(gameRunning){
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT) gameRunning = false;
			if(event.type == SDL_KEYDOWN){
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE:{
						gameRunning = false;
						break;
					}
					case SDLK_w:
					case SDLK_UP:{
						player->move(0, -1);
						break;
					}
					case SDLK_a:
					case SDLK_LEFT:{
						player->move(-1, 0);
						break;
					}
					case SDLK_s:
					case SDLK_DOWN:{
						player->move(0, 1);
						break;
					}
					case SDLK_d:
					case SDLK_RIGHT:{
						player->move(1, 0);
						break;
					}

				}
			}
		}
		
		//Code for updating
		if(SDL_GetTicks() % 30 == 0){
			SDL_FillRect(SDL_GetWindowSurface(window), NULL, SDL_MapRGB(SDL_GetWindowSurface(window)->format, 31, 31, 31));
			player->draw(SDL_GetWindowSurface(window));
			for(int i = 0; i < pickups.size(); i++){
				if(pickups[i]->isPickedUp(player)){
					player->setColor(pickups[i]->getColor());
					pickups[i] = nullptr;
					pickups.erase(pickups.begin() + i);
					std::cout << "Picked up\n";
				}
				else{
					pickups[i]->draw(SDL_GetWindowSurface(window));
				}
			}

			SDL_UpdateWindowSurface(window);
		}
		
	}

	//cleanup
	SDL_DestroyWindow(window);

	for(int i = 0; i < pickups.size(); i++){
		pickups[i] = nullptr;
	}

	player = nullptr;
	window = nullptr;
	surface = nullptr;

	//Quit SDL
	SDL_Quit();

	return 0;
}
