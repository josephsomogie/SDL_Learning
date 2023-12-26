#include "Game.h"

SDL_Texture* playerTex;
SDL_Rect  srcR, destR;

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

	SDL_Surface* tmpSurface = IMG_Load("assets/fella.png");
	playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

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
	destR.h = 400;
	destR.w = 400;
	destR.x = frameRate/20;
	


	std::cout << frameRate << std::endl;
}
void Game::render() {
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, playerTex, NULL, &destR);
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
