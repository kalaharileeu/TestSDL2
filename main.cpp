#include<SDL.h>

SDL_Window* _gWindow = 0;
SDL_Renderer* _gRenderer = 0;

int main(int argc, char* args[])
{
	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// if succeeded create our window
		_gWindow = SDL_CreateWindow("Hello SDL2",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			640, 480, SDL_WINDOW_SHOWN);
		// If window creation succeeded create renderer
		if (_gWindow != 0)
		{
			_gRenderer = SDL_CreateRenderer(_gWindow, -1, 0);
		}
	}
	else
	{
		return 1; // sdl could not initialize
	}
	// EVERYTHING GOOD draw blue window
	// Function expects Red, Green, Blue and Alpha as color values
	SDL_SetRenderDrawColor(_gRenderer, 0, 0, 255, 255);
	//clear the window
	SDL_RenderClear(_gRenderer);
	// show the window
	SDL_RenderPresent(_gRenderer);
	// set a delay before quitting
	SDL_Delay(5000);
	// clean up SDL
	SDL_Quit();
	return 0;
}