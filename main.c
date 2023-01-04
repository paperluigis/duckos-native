#include <stdio.h>
#include <unistd.h>
#include "config.h"
#include "gui.h"

#include "kernel.h"

void handle_exit() {
    puts("ur sus");
    deinit_sdl();
    exit(0);
}

int main() {
    load_config();

    if(!init_sdl()) return 1;
    if(!load_assets()) return 1;
    

    handle_exit();
    return 0;
}