#pragma once
#include "window.h"
class Rect : public Window /*I needed to use the same renderer as window, this is the class for all the textures*/
{
public:
	
	Rect(const Window &window, int widht, int height, int x, int y, const std::string &imagePath);

	~Rect();
	void draw() const;

private:
	short int textureWidht, textureHeight;
	short int posX, posY;
	

	SDL_Texture *pTexture = nullptr;
};

