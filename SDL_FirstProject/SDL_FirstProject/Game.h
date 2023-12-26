#pragma once
#include <SDL.h>
#include "SDL_image.h"
#include <ctime>
#include <iostream>
class Game
{
private:
	short frameRate;
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;

public:
	Game();
	~Game();

	void init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running();




};

