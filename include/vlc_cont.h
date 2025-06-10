#ifndef VLC_CONT_H
#define VLC_CONT_H

#include <vlc/libvlc.h>
#include <vlc/libvlc_media.h>
#include <vlc/libvlc_media_list.h>
#include <vlc/libvlc_media_list_player.h>
#include <vlc/libvlc_events.h>

#define CD_ROM_PATH "cdda:///dev/cdrom"

extern libvlc_instance_t *instance;
extern libvlc_media_t *media;
extern libvlc_media_list_t *media_list;
extern libvlc_media_list_player_t *media_list_player;
extern libvlc_media_track_t *media_track;
extern char *info_string;
void vlc_init();
void vlc_play();
void vlc_next_track();
void vlc_previous_track();
void vlc_release();

#endif