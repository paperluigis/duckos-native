#include <stdio.h>
#include <unistd.h>
#include "config.h"
#include "gui.h"

void handle_exit() {
    puts("ur sus");
    deinit_sdl();
    exit(0);
}

int main() {
    // initialize config struct
    load_config();

    init_sdl();
    load_assets();
    
    handle_exit();
}