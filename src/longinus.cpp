#include <iostream>
#include <SDL2/SDL.h>

struct Vector2D {
    int x;
    int y;
};

struct particle {
    Vector2D pos;
    int type;
};


//xorshift.
//Faster than any other rng.
struct xorshift128_state {
    uint32_t x[4];
};

/* The state must be initialized to non-zero */
uint32_t xorshift128(struct xorshift128_state *state)
{
	/* Algorithm "xor128" from p. 5 of Marsaglia, "Xorshift RNGs" */
	uint32_t t  = state->x[3];
    
    uint32_t s  = state->x[0];  /* Perform a contrived 32-bit shift. */
	state->x[3] = state->x[2];
	state->x[2] = state->x[1];
	state->x[1] = s;

	t ^= t << 11;
	t ^= t >> 8;
	return state->x[0] = t ^ s ^ (s >> 19);
}

int main() {
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    xorshift128_state rngState;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Initialization failed" << std::endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Practice making SDL Window",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH,
            WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        SDL_Quit();
        return 2;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    // Create a texture that will hold the random pixel data
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, WINDOW_WIDTH, WINDOW_HEIGHT);

    bool quit = false;
    SDL_Event event;

    unsigned int a;
    unsigned int b = 0;
    double delta = 0;
    int FPS;

    // Array to hold pixel data
    uint32_t *pixels = new uint32_t[WINDOW_WIDTH * WINDOW_HEIGHT];

    while (!quit) {
        a = SDL_GetTicks();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Fill the pixel array with random colors
        for (int i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT; ++i) {
            pixels[i] = (xorshift128(&rngState) % 255 << 24) | (xorshift128(&rngState) % 255 << 16) | (xorshift128(&rngState) % 255 << 8) | 0xFF; // RGBA format
        }

        // Update the texture with the random pixel data
        SDL_UpdateTexture(texture, NULL, pixels, WINDOW_WIDTH * sizeof(uint32_t));

        // Clear the screen
        SDL_RenderClear(renderer);

        // Render the texture to the screen
        SDL_RenderCopy(renderer, texture, NULL, NULL);

        SDL_RenderPresent(renderer);

        b = SDL_GetTicks();
        delta = b - a;

        // Calculate FPS
        FPS = 1000 / delta;
        std::cout << "FPS: " << FPS << std::endl;

        // Cap to 60 FPS
        if (delta < 16.666f) {
            SDL_Delay(16.666f - delta);
        }
    }

    // Cleanup
    delete[] pixels;
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
