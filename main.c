#include <stdio.h>
#include <sys/types.h>
#include <cdio/cdio.h>
#include <vlc/libvlc.h>

int main(int argc, const char *argv[]) {
    /* CdIo_t *p_cdio = cdio_open ("/dev/sr0", DRIVER_DEVICE);
    track_t first_track_num = cdio_get_first_track_num(p_cdio);
    track_t i_tracks        = cdio_get_num_tracks(p_cdio);
    int j, i=first_track_num;

    printf("CD-ROM Track List (%i - %i)\n", first_track_num, first_track_num+i_tracks-1);

    printf("  #:  LSN\n");

    for (j = 0; j < i_tracks; i++, j++) {
    lsn_t lsn = cdio_get_track_lsn(p_cdio, i);
    if (CDIO_INVALID_LSN != lsn)
        printf("%3d: %06d\n", (int) i, (long unsigned int) lsn);
    }
    printf("%3X: %06d  leadout\n", CDIO_CDROM_LEADOUT_TRACK,
            (long unsigned int) cdio_get_track_lsn(p_cdio, CDIO_CDROM_LEADOUT_TRACK));
    cdio_destroy(p_cdio); */

    libvlc_instance_t *Instance = libvlc_new(0, NULL);

    return 0;
}
