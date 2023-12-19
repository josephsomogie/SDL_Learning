#include "Game.h"

Game::Game() {

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
		if(renderer) std::cout << "Renderer Created..." << std::endl;

		isRunning = true;

	} else {
		isRunning = false; }

}
void Game::handleEvents() {

}
void Game::update() {

}
void Game::render() {

}
void Game::clean(){

}

bool Game::running() {
	return isRunning;
}
