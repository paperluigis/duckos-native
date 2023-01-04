#ifndef H__CONFIG
#define H__CONFIG

#include <SDL2/SDL_pixels.h>

struct duckos_config_t {
    struct {
        SDL_Color fg_2;
        SDL_Color fg_2t;
        SDL_Color fg_1;
        SDL_Color bg_1;
    } accent;
    struct {
        const char* monospace;
        const char* sans;
    } font;
};

struct duckos_config_t current_configuration;

#endif
