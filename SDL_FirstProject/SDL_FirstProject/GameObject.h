#pragma once
#include "Game.h"
class GameObject {

private:
	int xPos;	
	int yPos;
	SDL_Texture* objTexture;
	SDL_Rect srcR, destR;
	SDL_Renderer* renderer;	
public:
	GameObject(const char* texturesheet, SDL_Renderer* ren);
	~GameObject();
	void Update();
	void Render();


};