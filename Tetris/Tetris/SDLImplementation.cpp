#include "stdafx.h"
#include "SDLImplementation.h"




Graphs::Graphs()
{
	closed = !Init();
}

Graphs::~Graphs()
{
	freeTextures();
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	SDL_Quit();
}

bool Graphs::isClosed()
{
	return closed;
}

void Graphs::freeTextures()
{
	SDL_DestroyTexture(txture);
	txHeight = 0;
	txWidht = 0;
}



void Graphs::render(int x, int y, SDL_Rect * clip, double angle, SDL_Point * center, SDL_RendererFlip flip) //adds the image to the renderer so it can be showed
{
	SDL_Rect renderQuad = { x, y, ScrW, ScrH };

	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopyEx(pRenderer, txture, clip, &renderQuad, angle, center, flip);
}

bool Graphs::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0 || SDL_Init(SDL_INIT_AUDIO)!=0) //initialization of the SDL, we have to make sure it works so I put a little msg in case something is wrong
	{
		std::cerr << "There was an error! (Hubo un error) SDL_Error: ", SDL_GetError();
		return false;
	}

	
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) /*linear filtering*/
	{
		std::cerr<<"Linear filtering failed!";
	}

	pWindow = SDL_CreateWindow("BootCamp Tetris",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		ScrW, ScrH,
		0);
		if (pWindow == nullptr)
	{
		std::cerr << "Failed to create the window! (Hubo un error) ";
		return false;
	}

		if (!CreateRender()) 
		{			
			SDL_SetRenderDrawColor(pRenderer, 0x00, 0x00, 0x00, 0x00);

			if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
			{
				std::cerr << "There was an error with IMG initialization! (Hubo un error) ";
				return false;
			}

			return true;
		}
	else return false;
}

bool Graphs::CreateRender()
{
	pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (pRenderer == nullptr)
	{
		std::cerr << "Failed to create renderer! (Hubo un error) ";
		return false;
	}
	return true;
}


void Graphs::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	SDL_SetTextureColorMod(txture, red, green, blue);
}

void Graphs::blendMode(SDL_BlendMode blending)
{
	//blending
	SDL_SetTextureBlendMode(txture, blending);
}

void Graphs::loadImg(std::string imagePath)
{
	freeTextures();

	SDL_Texture *nTxture = nullptr;
	SDL_Surface *tempSurface = IMG_Load(imagePath.c_str());

	if (tempSurface == nullptr)
	{
		std::cerr << "Failed to create surface! (Hubo un error) ";
	}
	else 
	{
		SDL_SetColorKey(tempSurface, SDL_TRUE, SDL_MapRGB(tempSurface->format, 0, 0xFF, 0xFF));
		nTxture = SDL_CreateTextureFromSurface(pRenderer, tempSurface);

		if (nTxture == nullptr)
		{
			std::cerr << "Failed to create texture! (Hubo un error) ";
		}
		else //dimensions of the image
		{
			txWidht = tempSurface->w;
			txHeight = tempSurface->h;
		}

		SDL_FreeSurface(tempSurface);
	}
	txture = nTxture;
}


void Graphs::alphaSDL(Uint8 alpha)
{
	
	SDL_SetTextureAlphaMod(txture, alpha);
}



void Graphs::Update()
{

}

int Graphs::Events()
{
	SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				SDL_DestroyWindow(pWindow);
				exit(3);
				break;

			case SDL_KEYDOWN:
				return event.key.keysym.sym;

			default:
				break;
			}
		}
	
	return -1;
}
