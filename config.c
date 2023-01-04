#include "config.h"

struct duckos_config_t duckos_configuration;

void load_config()
{
    duckos_configuration = (struct duckos_config_t){
        .color.accent = {79, 175, 111, 255},
        .color.accent_trans = {79, 175, 111, 63},
        .color.accent_light = {127, 255, 159, 255},
        .color.background = {31, 79, 79, 111},
        .font.pt_wintitle = 13,
        .font.pt_terminal = 16,
        .path.font_sans = "./assets/font_sans.ttf",
        .path.font_monospace = "./assets/font_mono.ttf"};
}
