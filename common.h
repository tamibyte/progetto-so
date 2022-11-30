// Standard libs
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

// Files libs
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// Constants
#define MAX_INPUT_LENGTH 100
#define MAX_LENGTH_NAMES 30

#define MAX_BLOCKS 256
#define BLOCK_SIZE 1024

#define ROOT_DIRECTORY 0