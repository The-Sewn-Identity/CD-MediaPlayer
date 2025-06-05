#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <vlc/libvlc.h>
#include "start.h"

char COLOR[] = "\u001b[42m";
char RESET[] = "\u001b[0m";

int startmenu() {
    FILE *sign = fopen("../sign.txt", "r");
    if (sign == NULL) { return 1; }
    
    attron(A_BOLD);
    char buffer[960];
    while (fgets(buffer, sizeof(buffer), sign) != NULL) {
        printw(" %s", buffer);
    }
    fclose(sign);
    attroff(A_BOLD);
    return 0;
}

void start() {
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    
    start_color();
    init_color(COLOR_WHITE, 1000, 1000, 1000);
    init_pair(1, COLOR_WHITE, COLOR_GREEN);
    wbkgd(stdscr, COLOR_PAIR(1));

    startmenu();
}


libvlc_instance_t *instance;
void vlcInit() {
    instance = libvlc_new(0, NULL);
}