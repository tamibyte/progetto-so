#include "common.h"

#define DISK_ERROR -1
#define DISK_OK 0

typedef struct Disk {
    char name[MAX_LENGTH_NAMES];
    int fd;
} Disk;

void Disk_error(Disk* disk, char* msg);

Disk *Disk_create(char* name);
int Disk_destroy(Disk *disk);
int Disk_open(Disk* disk);
int Disk_close(Disk* disk);
int Disk_write(Disk *disk, char *buf, int size);
int Disk_read(Disk *disk, char *buf, int size);

