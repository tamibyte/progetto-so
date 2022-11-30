#include "disk.h"

void Disk_error(Disk *disk, char *msg) {
    printf("[%s] %s\n", disk->name, strerror(errno));
    return;
}

Disk* Disk_create(char *name) {
    Disk *disk = malloc(sizeof(Disk));
    strcpy(disk->name, name);
    disk->fd = -1;
    return disk;
}

int Disk_destroy(Disk *disk) {
    Disk_close(disk);
    if (disk) {
        free(disk);
    }
    return DISK_OK;
}

int Disk_open(Disk *disk) {
    int fd;

    char dir[39] = "os/disks/\0";
    strcat(dir, disk->name);

    fd = open(dir, O_CREAT | O_RDWR, 0666);

    if (fd == -1) {
        Disk_error(disk, "Unable to open the file");
        return DISK_ERROR;
    }

    disk->fd = fd;
    return DISK_OK;
}

int Disk_close(Disk *disk) {
    if (disk && disk->fd != -1) close(disk->fd);
    return DISK_OK;
}

int Disk_write(Disk *disk, char *buf, int size){
    write(disk->fd, buf, size);
    return DISK_OK;
}

int Disk_read(Disk *disk, char *buf, int size) {
    read(disk->fd, buf, size);
    return DISK_OK;
}
