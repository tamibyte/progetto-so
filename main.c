#include "disk.c"

int main() {
    // create
    Disk* disk = Disk_create("test/test.txt");
    char *buf = malloc(13);

    // open
    if (Disk_open(disk) != DISK_OK) 
        exit(DISK_ERROR);

    // write
    if (Disk_write(disk, "Hello World!", 12) != DISK_OK)
        exit(DISK_ERROR);

    // read
    lseek(disk->fd, 0, SEEK_SET);
    if (Disk_read(disk, buf, 12) != DISK_OK)
        exit(DISK_ERROR);
    printf("%s\n", buf);

    // close
    if (Disk_close(disk) != DISK_OK)
        exit(DISK_ERROR);

    // destroy
    if (Disk_destroy(disk) != DISK_OK)
        exit(DISK_ERROR);
    return 0;
}