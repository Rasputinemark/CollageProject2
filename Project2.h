#include<SDL.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<cstdio>
#include<string>
#include<Windows.h>
using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 512;
const int SCREEN_HEIGHT = 512;
bool vacant[15][15];
bool black[15][15];
bool white[15][15];
int step = 0;

void initVacant() {
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++)
			vacant[i][j] = true;
}

bool init();
bool loadMedia();
void close();

SDL_Window* genWindow;                // generate window
SDL_Surface* genScreenSurface = NULL; // generate backround surface
SDL_Surface* genImageBoard = NULL;		  // generate image surface
SDL_Surface* genImageGo = NULL;		  // generate image surface
SDL_Surface* genImageWGo = NULL;
SDL_Surface* genImageRP = NULL;

SDL_Rect goRect; //black, is played by the layer
SDL_Rect wgoRect;//white, is played by the computer
SDL_Rect goBoardRect;//chess board

SDL_Surface* loadSurface(string path)
{
	SDL_Surface* optimizedSurface = NULL;

	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == NULL)
		cout << "fail!" << endl;
	else
	{
		optimizedSurface = SDL_ConvertSurface(loadedSurface, genScreenSurface->format, 0);
		if (optimizedSurface == NULL)
			cout << "faile" << endl;

		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}

bool init() {
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO < 0)) {
		cout << "SDL failed to initialize!" << endl;
		success = false;
	}
	else {
		genWindow = SDL_CreateWindow("Chess", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (genWindow == NULL) {
			cout << "Window failed to create!" << endl;
			success = false;
		}
		else
			genScreenSurface = SDL_GetWindowSurface(genWindow);
	}
	return success;
}

bool loadMedia() {
	bool success = true;
	genImageGo = SDL_LoadBMP("go.bmp");
	genImageBoard = SDL_LoadBMP("goBoard.bmp");
	genImageWGo = SDL_LoadBMP("wgo.bmp");
	genImageRP = SDL_LoadBMP("redPoint.bmp");

	if (genImageGo == NULL || genImageBoard == NULL || genImageWGo == NULL) {
		cout << "Failed to load media!" << endl;
		success = false;
	}
	return success;
}

void close() {
	SDL_FreeSurface(genImageGo);
	genImageGo = NULL;

	SDL_FreeSurface(genImageWGo);
	genImageWGo = NULL;

	SDL_FreeSurface(genImageBoard);
	genImageBoard = NULL;

	SDL_DestroyWindow(genWindow);
	genWindow = NULL;

	SDL_Quit();
}

void wgoMove(int random) {
	switch (random) {
	case 0:
		wgoRect.x = goRect.x + wgoRect.w; // white go at the right side of black go 
		break;
	case 1:
		wgoRect.x = goRect.x - wgoRect.w;
		break;
	case 2:
		wgoRect.y = goRect.y + wgoRect.h;
		break;
	case 3:
		wgoRect.y = goRect.y - wgoRect.h;
	}

}
