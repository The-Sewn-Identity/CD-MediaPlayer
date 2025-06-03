#include <ncurses.h>
#include <vlc/libvlc.h>
#include "start.h"

void start() {
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    printw(WELCOME_MESSAGE); 
}

void startmenu() {
    printw("<< START MENU >>");
    printw("PRESS A to play from CD");
    printw("PRESS Q to quit");
}

// libvlc_instance_t *instance;
void vlcInit() {
    // instance = libvlc_new(0, NULL);
}