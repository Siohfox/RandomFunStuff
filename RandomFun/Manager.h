#pragma once
#include "SDL2/SDL.h"
#include <iostream>

class Manager
{
public:
	Manager(int windowSizeX, int windowSizeY);
	~Manager();

	int CheckSuccess();

protected:
	int m_windowSizeX;
	int m_windowSizeY;
	bool m_successful;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

};

