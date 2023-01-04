#ifndef H_CONFIG
#define H_CONFIG

#include <SDL2/SDL_pixels.h>

struct duckos_config_t {
    struct {
        SDL_Color accent;
        SDL_Color accent_trans;
        SDL_Color accent_light;
        SDL_Color background;
    } color;
    struct {
        char* font_monospace;
        char* font_sans;
    } path;
    struct {
        unsigned int pt_wintitle;
        unsigned int pt_terminal;
    } font;
};

extern struct duckos_config_t duckos_configuration;

void load_config();

#endif