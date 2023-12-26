#include <SDL.h>
#include "Game.h"

Game* game = nullptr;

int main(int arc, char* argv[])
{
	game = new Game();
	game->init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();
	}
	game->clean();

	/*SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(3000);
	//SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Hello World", "Successful", NULL);
	*/
	return 0;
}