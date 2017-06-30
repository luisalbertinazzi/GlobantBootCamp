#include "stdafx.h"
#include "Rect.h"
#include <SDL_image.h>


Rect::Rect(const Window &window, int widht, int height, int x, int y, const std::string &imagePath) :
	Window(window), textureWidht(widht), textureHeight(height), posX(x), posY(y)
{
	auto surface = IMG_Load(imagePath.c_str());
	if (!surface)
	{
		std::cerr<<"Failed to create surface";
	}
	pTexture = SDL_CreateTextureFromSurface(pRender, surface);
	if(!pTexture)
	{
		std::cerr << "Failed to create texture";
	}
	SDL_FreeSurface(surface);
}
Rect::~Rect()
{
	SDL_DestroyTexture(pTexture);
}

void Rect::draw() const
{ 
	SDL_Rect rect = { posX, posY, textureWidht, textureHeight };
	if (pTexture) {
		SDL_RenderCopy(pRender, pTexture, nullptr, &rect);
	}
	else {
		SDL_SetRenderDrawColor(pRender, 200, 200, 0, 255);
		SDL_RenderFillRect(pRender, &rect);
	}
}
