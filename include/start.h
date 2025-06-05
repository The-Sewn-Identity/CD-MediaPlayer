#ifndef START_H
#define START_H

#define CD_ROM_PATH "cdda:///dev/cdrom"

void start();
int startmenu();

extern libvlc_instance_t *instance;
void vlcInit();

#endif