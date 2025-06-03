#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <vlc/libvlc.h>
#include <vlc/libvlc_media.h>
#include <vlc/libvlc_media_list.h>
#include <vlc/libvlc_events.h>
#include "start.h"
#include "keys.h"

int main() {
    start();
    // vlcInit();
    libvlc_instance_t *instance = libvlc_new(0, NULL);

    libvlc_media_t *media = libvlc_media_new_location(instance, "cdda:///dev/cdrom");
    libvlc_media_parse_with_options(media, libvlc_MediaParsedChanged, 1);

    libvlc_media_list_t *medialist = libvlc_media_list_new(instance);
    libvlc_media_list_add_media(medialist, media);
    libvlc_media_list_media(medialist);
    printf("%u\n", libvlc_media_list_count(medialist));

    bool loop = true;
    int keys;

    do {
        keys = getch();
        switch (keys) {
            case KEY_A:
                break;
            default:
                printw("...");
                break;
        }
    } while (keys != KEY_Q && loop);

    libvlc_media_release(media);
    libvlc_media_list_release(medialist);
    libvlc_release(instance);
    
    refresh();
    endwin();

    return 0;
}
