#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <string>


unsigned const short PositionOfB = 320;
unsigned const short  TileHAndW = 30;
const int ScrW = 412;
const int ScrH = 600;



class Graphs
{
public:
	Graphs(); //initializes SDL and variables

	~Graphs(); // Dellocates

	/*The boolean methods are mostly used for troubleshooting*/
	void Update();
	int Events();
	
	void setColor(Uint8 red, Uint8 green, Uint8 blue);
	void blendMode(SDL_BlendMode blending);  // blending of colors for the SDL 
	void loadImg(std::string imagePath);
	void alphaSDL(Uint8 alpha);


	bool isClosed();

	void freeTextures();
	
	void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE); //Prepares the image to show it on screen

	
private:
	/*I'm using p before the name of the pointers so I know they are pointers*/
	SDL_Texture  *txture = nullptr; 
	SDL_Window *pWindow = nullptr; //our window 
	SDL_Renderer *pRenderer = nullptr;

	bool closed = false;
	bool Init();
	bool CreateRender();
	int txWidht, txHeight;
};

