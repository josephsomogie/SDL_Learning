#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"



GameObject* player;

Game::Game() {
	isRunning = false;
	frameRate = 0;
	renderer = nullptr;
	window = nullptr;
}
Game::~Game() {

}

void Game::init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen) flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems Initialized..." << std::endl;

		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		if (window) std::cout << "Window Created..." << std::endl;

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created..." << std::endl;
		}
		isRunning = true;

	} else {
		isRunning = false; }
	player = new GameObject("assets/fella.png", renderer);
	

}
void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

		
	default:
		break;
	}
}
void Game::update() {
	frameRate++;
	/*destR.h = 400;
	destR.w = 400;
	static bool right = true;
	if (destR.x < 590 && right) {
		destR.x++;
	}
	else if (destR.x > 10 && !right) {
		destR.x--;
	}
	else
		right = !right;*/

	player->Update();

	


	std::cout << frameRate << std::endl;
}
void Game::render() {
	SDL_RenderClear(renderer);
	player->Render();
	SDL_RenderPresent(renderer);

}
void Game::clean(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned..." << std::endl;
}

bool Game::running() {
	return isRunning;
}
