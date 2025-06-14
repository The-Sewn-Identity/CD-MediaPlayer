#include <stdio.h>
#include <stdlib.h>
#include "vlc_cont.h"
#include "ncurses.h"

libvlc_instance_t *instance;
libvlc_media_t *media;
libvlc_media_list_t *media_list;
libvlc_media_list_player_t *media_list_player;
libvlc_media_track_t *media_track;
char *info_string;

void vlc_init() {
    instance = libvlc_new(0, NULL);
    media = libvlc_media_new_location(instance, CD_ROM_PATH);
    
    libvlc_media_parse_with_options(media, libvlc_MediaParsedChanged, -1);

    media_list = libvlc_media_list_new(instance);
    libvlc_media_list_add_media(media_list, media);
    
    media_list_player = libvlc_media_list_player_new(instance);
    libvlc_media_list_player_set_media_list(media_list_player, media_list);
    libvlc_media_list_media(media_list);

}

void vlc_play() {
    libvlc_media_list_player_play(media_list_player);
}

void vlc_next_track() {
    libvlc_media_list_player_next(media_list_player);
}

void vlc_previous_track() {
    libvlc_media_list_player_previous(media_list_player);
}

void vlc_release() {
    libvlc_media_release(media);
    libvlc_media_list_release(media_list);
    libvlc_media_list_player_release(media_list_player);
    libvlc_release(instance);
}
