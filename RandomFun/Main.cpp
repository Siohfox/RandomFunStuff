#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <iostream>
#include "Manager.h"

bool running = true;

void PollEvents()
{
    const Uint8* keyboard_state_array = SDL_GetKeyboardState(NULL);

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_KEYDOWN:
            // If the player presses 'Escape' in the menu, it will exit the menu loop and quit
            if ((keyboard_state_array[SDL_SCANCODE_ESCAPE]))
            {
				running = false;
            }
            break;
        }
    }
}

int main()
{
	int x = 600;
	int y = 400;
	Manager manager(x,y);

	if (manager.CheckSuccess() != 0)
	{
		std::cout << "Success error with manager" << std::endl;
	}

	while (running)
	{
		PollEvents();
	}

	return 0;
}