#include <stdio.h>
#include <unistd.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "constants.h"
#include "config.h"

SDL_Window *window;
SDL_Renderer *renderer;
TTF_Font *font_monospace;
TTF_Font *font_sans;

void handle_exit()
{
    puts("ur sus");

    // SDL_FreeSurface(surface);
    if (window)
        SDL_DestroyWindow(window);
    SDL_Quit();
    if (font_monospace)
        TTF_CloseFont(font_monospace);
    if (font_sans)
        TTF_CloseFont(font_sans);
    TTF_Quit();
    exit(0);
}

int poll()
{
    SDL_Event next_event;

    if (SDL_PollEvent(&next_event))
    {
        switch (next_event.type)
        {
        case SDL_QUIT:
            handle_exit();
            break;
        }
    }
}

int draw()
{
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, DUCKOS_ACCENT_BACKGROUND);
    // SDL_UpdateWindowSurface(window);
}

int main(int argc, char *const argv[])
{
    // initialize config struct
    load_config();

    // initialize sdl
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fputs("SDL start vented\n", stderr);
        return 1;
    }

    // initialize ttf library
    TTF_Init();

    // load in some fonts
    font_monospace = TTF_OpenFont(DUCKOS_FONT_LOCATION_MONO, DUCKOS_FONT_SIZE_TERM);
    font_sans = TTF_OpenFont(DUCKOS_FONT_LOCATION_SANS, DUCKOS_FONT_SIZE_WINTITLE);
    if (!font_sans)
    {
        fputs("failed to load " DUCKOS_FONT_LOCATION_SANS, stderr);
        return 1;
    }
    if (!font_monospace)
    {
        fputs("failed to load " DUCKOS_FONT_LOCATION_MONO, stderr);
        return 1;
    }

    // create window
    window = SDL_CreateWindow("DuckOS Native",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 540,
                              SDL_WINDOW_OPENGL);
    if (!window)
    {
        fputs("Window creation vented\n", stderr);
        return 1;
    }

    // get window renderer
    // surface = SDL_GetWindowSurface(window);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        fputs("Renderer getting vented\n", stderr);
        return 1;
    }

    while (1)
    {
        poll();
        draw();
    }

    return 0;
}
