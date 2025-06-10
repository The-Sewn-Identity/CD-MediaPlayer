#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include "vlc_cont.h"
#include "start.h"
#include "keys.h"

int main() {
    start();
    vlc_init();

    bool loop = true;
    int keys;

    do {
        keys = getch();
        switch (keys) {
            case KEY_A: case KEY_A_SHIFT:
                vlc_play();
                break;
            case KEY_PLUS: case KEY_PLUS_SHIFT:
                vlc_next_track();
                break;
            case KEY_MINUS: case KEY_MINUS_SHIFT:
                vlc_previous_track();
                break;
            default:
                break;
        }
    } while (keys != KEY_Q && keys != KEY_Q_SHIFT && loop);

    vlc_release();
    
    refresh();
    endwin();

    return 0;
}
