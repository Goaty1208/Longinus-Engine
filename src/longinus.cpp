#include <iostream>
#include <SDL2/SDL.h>
#include <random>

std::random_device seeder;

std::mt19937 engine(seeder());

std::uniform_int_distribution<int> dist(0, 255);

struct Vector2D {
    int x;
    int y;
};

struct particle {
    Vector2D pos;
    int type;
};

int main() {
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return 1;
        std::cout << "Initialization failed" << std::endl;
    }

    SDL_Window *window = SDL_CreateWindow("Practice making sdl Window",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH,
            WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        SDL_Quit();
        return 2;
    }

    // We create a renderer with hardware acceleration, we also present according with the vertical sync refresh.
    SDL_Renderer *renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC) ;

    bool quit = false;
    SDL_Event event;

    unsigned int a;
    unsigned int b = 0;
    double delta = 0;
    int FPS;

    while (!quit) {

        a = SDL_GetTicks();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_RenderClear(renderer);

        for (size_t i = 0; i < WINDOW_WIDTH; i++) {
            for (size_t j = 0; j < WINDOW_HEIGHT; j++){
                SDL_SetRenderDrawColor(renderer, dist(engine), dist(engine), dist(engine), 0xFF);
                SDL_RenderDrawPoint(renderer, i, j);
            }      
        }
        
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);

        SDL_RenderPresent(renderer);

        delta += a - b;

        FPS = 1000/delta;

        // Cap to 60 FPS
	    SDL_Delay(floor(16.666f - (delta/SDL_GetPerformanceFrequency() * 1000)));

        std::cout << "FPS: " << FPS << std::endl;

        b = SDL_GetTicks();
    }

    SDL_DestroyWindow(window);
    // We have to destroy the renderer, same as with the window.
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

}