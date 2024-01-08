#include "GameObject.h"
#include "TextureManager.h"
GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren)
{
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturesheet, ren);
}
void GameObject::Update()
{
	xPos = 0;
	yPos = 0;

	srcR.h = 100;
	srcR.w = 100;
	srcR.x = 0;
	srcR.y = 0;

	destR.x = xPos;
	destR.y = yPos;
	destR.w = srcR.w*2;
	destR.h = srcR.h * 2;


}
void GameObject::Render()
{
	SDL_RenderCopy(renderer, objTexture, &srcR, &destR);
}