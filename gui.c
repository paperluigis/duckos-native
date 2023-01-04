#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "config.h"

static SDL_Window *window;
static SDL_Renderer *renderer;
static TTF_Font *font_monospace;
static TTF_Font *font_sans;

static void poll() {
    SDL_Event next_event;
    if (SDL_PollEvent(&next_event)) {
        switch (next_event.type) {
        case SDL_QUIT:
            handle_exit();
            break;
        }
    }
}

static void draw(){

}


int init_sdl() {
    // initialize sdl
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fputs("SDL start vented\n", stderr);
        return 1;
    }
    SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");

    // initialize ttf library
    TTF_Init();
}
int load_assets() {
    // load in some fonts
    font_monospace = TTF_OpenFont(duckos_configuration.path.font_monospace, duckos_configuration.font.pt_terminal);
    font_sans = TTF_OpenFont(duckos_configuration.path.font_sans, duckos_configuration.font.pt_terminal);
    if (!font_sans) {
        fprintf(stderr, "failed to load %s", duckos_configuration.path.font_sans);
        return 1;
    }
    if (!font_monospace) {
        fprintf(stderr, "failed to load %s", duckos_configuration.path.font_monospace);
        return 1;
    }
}
int open_window() {
    // create window
    window = SDL_CreateWindow("DuckOS Native",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 540,
        SDL_WINDOW_OPENGL);
    if (!window) {
        fputs("Window creation vented\n", stderr);
        return 1;
    }

    // get window renderer
    // surface = SDL_GetWindowSurface(window);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        fputs("Renderer creation vented\n", stderr);
        return 1;
    }
    
    return 0;
}
void close_window() {
    if(renderer) SDL_DestroyRenderer(renderer);
    if(window)   SDL_DestroyWindow(window);
    renderer = NULL;
    window = NULL;
}
void deinit_sdl() {
    if (window)         SDL_DestroyWindow(window);
    SDL_Quit();
    if (font_monospace) TTF_CloseFont(font_monospace);
    if (font_sans)      TTF_CloseFont(font_sans);
    TTF_Quit();
}