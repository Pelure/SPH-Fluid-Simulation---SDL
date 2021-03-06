#include <SDL.h>
// #include <SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
	:window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(p_title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, p_w,p_h,SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		std::cout << "Window failed to init. Error -> " << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

// SDL_Texture* RenderWindow::LoadTexture(const char* p_filePath)
// {
// 	SDL_Texture* texture = NULL;
// 	texture = IMG_LoadTexture(renderer, p_filePath);

// 	if (texture == NULL)
// 	{
// 		std::cout << "Failed to load texture. Error -> " << SDL_GetError() << std::endl;
// 	}
// 	return texture;
// }

void RenderWindow::CleanUp()
{
	SDL_DestroyWindow(window);
}

void RenderWindow::Clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::Clear(int pRed, int pGreen, int pBlue)
{
	SDL_SetRenderDrawColor(renderer, pRed, pGreen, pBlue, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer,0, 0, 0, 0);
}

void RenderWindow::RenderTex(SDL_Texture* p_tex,float p_x, float p_y, float p_sizeW, float p_sizeH)
{
	int wTex,hTex;

	SDL_QueryTexture(p_tex,NULL,NULL,&wTex,&hTex);

	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w = wTex;
	src.h = hTex;

	SDL_Rect dst;
	dst.x = p_x;
	dst.y = p_y;
	dst.w = wTex * p_sizeW;
	dst.h = hTex * p_sizeH;

	SDL_RenderCopy(renderer, p_tex, &src, &dst);
}

void RenderWindow::Display()
{
	SDL_RenderPresent(renderer);
}

void RenderWindow::DrawRect(double pPosLeft, double pPosTop, double pWidthWidth, double pWidthHeight, int pRed, int pGreen, int pBlue)
{
	SDL_SetRenderDrawColor(renderer,pRed, pGreen, pBlue, 255);

	SDL_Rect myRect;
	myRect.x = pPosLeft;
	myRect.y = pPosTop;
	myRect.w = pWidthWidth;
	myRect.h = pWidthHeight;

	SDL_RenderFillRect(renderer, &myRect);

	SDL_SetRenderDrawColor(renderer, 0,0,0,0);
}
