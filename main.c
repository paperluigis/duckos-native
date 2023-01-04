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
    load_config();

    if(!init_sdl()) return 0;
    load_assets();
    


    handle_exit();
    return 0;
}