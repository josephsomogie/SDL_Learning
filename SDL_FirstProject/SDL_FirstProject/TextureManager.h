#pragma once
#include "Game.h"

class TextureManager {

private:

public:
	static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* ren);

};
